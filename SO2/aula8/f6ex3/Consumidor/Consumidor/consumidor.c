
#include <tchar.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <fcntl.h>
#include <io.h>
#include <windows.h>
#include <process.h>

#include "../../header.h"

DWORD WINAPI consume(LPVOID p) {
	ControlData* cData = (ControlData*)p;
	BufferCell cell;

	while (1) {
		if (cData->shutdown)
			return 0;

		WaitForSingleObject(cData->hReadSem, INFINITE);

		WaitForSingleObject(cData->hMutex, INFINITE);

		CopyMemory(&cell, &(cData->sharedMem->buffer[(cData->sharedMem->wP)++]), sizeof(ControlData));
		if (cData->sharedMem->rP == BUFFER_SIZE)
			cData->sharedMem->rP = 0;

		ReleaseMutex(cData->hMutex);

		ReleaseSemaphore(cData->hWriteSem, 1, NULL);
		_tprintf(_T("C%d consumed %d from P%d.\n"), cData->id, cell.val, cData->sum);
		cData->count++;
		cData->sum += cell.val;

	}
}
int _tmain(int argc, TCHAR* argv[]) {


	ControlData cData;
	HANDLE hThread;
	TCHAR command[100];



#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);
#endif

	srand((unsigned int)time(NULL));
	cData.shutdown = 0;
	cData.count = 0;
	if (!initMemAndSync(&cData)) {
		_tprintf(_T("err"));
		exit(1);
	}

	WaitForSingleObject(cData.hMutex, INFINITE);
	cData.id = ++(cData.sharedMem->c);
	ReleaseMutex(cData.hMutex);
	hThread = CreateThread(NULL, 0, consume, &cData, 0, NULL);
	_tprintf(_T("Type in 'exit' tp leave.\n"));

	do {
		_getts_s(command, 100);
	} while (_tcscmp(command, _T("exit") != 0));

	cData.shutdown = 1;
	WaitForSingleObject(hThread, INFINITE);

	_tprintf(_T("P%d consumed %d items, summing a total of %d.\n"), cData.id, cData.count, cData.sum);

	CloseHandle(hThread);
	UnmapViewOfFile(cData.sharedMem);
	CloseHandle(cData.hMapFile);
	CloseHandle(cData.hMutex);
	CloseHandle(cData.hWriteSem);
	CloseHandle(cData.hReadSem);






	return 0;
}