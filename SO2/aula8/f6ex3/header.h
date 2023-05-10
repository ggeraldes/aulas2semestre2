
#include <windows.h>
#include <tchar.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>

#define SHM_NAME _T("SHM_PC")
#define MUTEX_NAME _T("MUTEX")
#define SEM_WRITE_NAME _T("SEM_WRITE")
#define SEM_READ_NAME _T("SEM_READ")

#define BUFFER_SIZE 10

typedef struct _BufferCell{
	unsigned int id;
	unsigned int val;
} BufferCell;

typedef struct _SharedMem{
	BufferCell buffer[BUFFER_SIZE];
	unsigned int p;
	unsigned int c;
	unsigned int wP;
	unsigned int rP;
} SharedMem;

typedef struct _ControlData{
	HANDLE hMapFile;
	HANDLE hMutex;
	HANDLE hWriteSem;
	HANDLE hReadSem;
	SharedMem* sharedMem;
	unsigned int count;
	unsigned int sum;
	unsigned int id;
	unsigned int shutdown;
} ControlData;

BOOL initMemAndSync(ControlData* cData) {
	BOOL firstProcess = FALSE;
	cData->hMapFile = OpenFileMapping(
		FILE_MAP_ALL_ACCESS,
		FALSE,
		SHM_NAME
	);
	if(cData->hMapFile == NULL) {

		firstProcess = TRUE;
		cData->hMapFile = CreateFileMapping(
			INVALID_HANDLE_VALUE,
			NULL,
			PAGE_READWRITE,
			0,
			sizeof(SharedMem),
			SHM_NAME
		);
		if (cData->hMapFile == NULL) {
			_tprintf("");
			return FALSE;
		}
	}
	cData->sharedMem = (SharedMem*)MapViewOfFile(cData->hMapFile,
		FILE_MAP_ALL_ACCESS,
		0, 
		0, 
		sizeof(SharedMem));
		
	if (cData->sharedMem == NULL) {
		_tprintf("");
		CloseHandle(cData->sharedMem);
		return FALSE;
	}
		if(firstProcess) {
			cData->sharedMem->p = 0;
			cData->sharedMem->c = 0;
			cData->sharedMem->wP = 0;
			cData->sharedMem->rP = 0;

		}
		cData->hMutex = CreateMutex(NULL, FALSE, MUTEX_NAME);

		if (cData->hMutex == NULL) {
			_tprintf("..");
			UnmapViewOfFile(cData->sharedMem);
			CloseHandle(cData->sharedMem);
			return FALSE;
		}
		cData->hWriteSem = CreateSemaphore(NULL, BUFFER_SIZE, BUFFER_SIZE, SEM_WRITE_NAME);
		if(cData->hWriteSem == NULL) {
			_tprintf("");
			UnmapViewOfFile(cData->sharedMem);
			CloseHandle(cData->hMapFile);
			CloseHandle(cData->hMutex);
			return FALSE;
		}
		cData->hReadSem = CreateSemaphore(NULL, 0, BUFFER_SIZE, SEM_WRITE_NAME);
		if (cData->hWriteSem == NULL) {
			_tprintf("");
			UnmapViewOfFile(cData->sharedMem);
			CloseHandle(cData->hMapFile);
			CloseHandle(cData->hMutex);
			CloseHandle(cData->hWriteSem);
			return FALSE;
		}
		return TRUE;

	
}
