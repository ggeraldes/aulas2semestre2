
#include <tchar.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <fcntl.h>
#include <io.h>
#include <windows.h>
#include <process.h>

#include "../../header.h"

#define fileName TEXT("alfabeto.txt")

DWORD WINAPI produce(LPVOID p) {
	ControlData* cData = (ControlData*)p;
	BufferCell cell;
	int r;

	while (1) {
		if (cData->shutdown)
			return 0;
		r = rand() % 3 + 2;
		Sleep(r * 1000);
		r = rand() % 90 + 10;
		cell.id = cData->id;
		cell.val = r;

		WaitForSingleObject(cData->hWriteSem, INFINITE);

		WaitForSingleObject(cData->hMutex, INFINITE);

		CopyMemory(&(cData->sharedMem->buffer[(cData->sharedMem->wP)++]), &cell, sizeof(BufferCell));
		if (cData->sharedMem->wP == BUFFER_SIZE)
			cData->sharedMem->wP = 0;

		ReleaseMutex(cData->hMutex);

		ReleaseSemaphore(cData->hReadSem, 1, NULL);
		_tprintf(_T("P%d producer %d.\n"), cell.id, cell.val);
		cData->count++;

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
	cData.id = ++(cData.sharedMem->p);
	ReleaseMutex(cData.hMutex);
	hThread = CreateThread(NULL, 0, produce, &cData,0, NULL);
	_tprintf(_T("Type in 'exit' tp leave.\n"));
	
	do {
		_getts_s(command, 100);
	} while (_tcscmp(command, _T("exit") != 0));

	cData.shutdown = 1;
	WaitForSingleObject(hThread, INFINITE);

	_tprintf(_T("P%d produced %d items.\n"), cData.id, cData.count);

	CloseHandle(hThread);
	UnmapViewOfFile(cData.sharedMem);
	CloseHandle(cData.hMapFile);
	CloseHandle(cData.hMutex);
	CloseHandle(cData.hWriteSem);
	CloseHandle(cData.hReadSem);

	return 0;



}