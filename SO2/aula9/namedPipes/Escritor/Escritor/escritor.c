
#include <tchar.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <fcntl.h>
#include <io.h>
#include <windows.h>
#include <process.h>

#define PIPE_NAME TEXT("\\\\.\\pipe\\teste")

#define MAX_CLI 10
#define BUF_SIZE 10

typedef struct {
	int terminar;
	int numClientes;
	HANDLE hMutex;
	HANDLE hPipes[MAX_CLI];
} ThreadDados;

DWORD WINAPI ThreadMensagens(LPVOID param) {
	TCHAR buf[BUF_SIZE];
	DWORD n;
	int i;
	ThreadDados* dados = (ThreadDados*)param;

	do {
		_tprintf(_T("[ESCRITOR] Frase: "));
		_fgetts(buf, 256, stdin);
		buf[_tcslen(buf) - 1] = '\0';

		WaitForSingleObject(dados->hMutex, INFINITE);

		for (i = 0; i < dados->numClientes; i++) {
			if(!WriteFile(dados->hPipes[i], buf, _tcslen(buf) * sizeof(TCHAR), &n, NULL)) {
				_tprintf(TEXT("[ERRO] Escrever no pipe! (WriteFile)\n"));
				exit(-1);
			}
			_tprintf(TEXT("[ESCRITOR] Enviei %d bytes ao leitor [%d]... (WriteFile)\n"), n, i);
		}
		ReleaseMutex(dados->hMutex);
		
	} while (_tcscmp(buf, TEXT("fim")));

	dados->terminar = 1;
	return 0;

}

int _tmain(int argc, LPTSTR argv[]) {
	DWORD n;
	HANDLE hPipe, hThread;
	int i;
	ThreadDados tDados;
	

	

	TCHAR buf[256];
#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif

	tDados.terminar = 0;
	tDados.numClientes = 0;

	tDados.hMutex = CreateMutex(
		NULL,              // default security attributes
		FALSE,             // initially not owned
		NULL);             // unnamed mutex)

	if (tDados.hMutex == NULL)
	{
		printf("CreateMutex error: %d\n", GetLastError());
		return 1;
	}

	hThread = CreateThread(
		NULL,       // default security attributes
		0,          // default stack size
		ThreadMensagens,
		&tDados,       // no thread function arguments
		0,          // default creation flags
		NULL); // receive thread identifier

	if (hThread == NULL)
	{
		printf("CreateThread error: %d\n", GetLastError());
		return 1;
	}
	while (!tDados.terminar) {

		_tprintf(TEXT("[ESCRITOR] Criar uma cópia do pipe '%s' ... (CreateNamedPipe)\n"), PIPE_NAME);
		hPipe = CreateNamedPipe(PIPE_NAME, PIPE_ACCESS_OUTBOUND, PIPE_WAIT |
			PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE, 1,
			sizeof(buf), sizeof(buf), 1000, NULL);
		if (hPipe == INVALID_HANDLE_VALUE) {
			_tprintf(TEXT("[ERRO] Criar Named Pipe! (CreateNamedPipe)"));
			exit(-1);
		}
		_tprintf(TEXT("[ESCRITOR] Esperar ligação de um leitor... (ConnectNamedPipe)\n"));
		if (!ConnectNamedPipe(hPipe, NULL)) {
			_tprintf(TEXT("[ERRO] Ligação ao leitor! (ConnectNamedPipe\n"));
			exit(-1);
		}
		WaitForSingleObject(tDados.hMutex, INFINITE);
		tDados.hPipes[tDados.numClientes] = hPipe;
		tDados.numClientes++;
		Release(tDados.hMutex);

	}
	WaitForSingleObject(hThread, INFINITE);
	for (i = 0; i < tDados.numClientes; i++) {
		_tprintf(TEXT("[ESCRITOR] Desligar o pipe (DisconnectNamedPipe)\n"));
		if (!DisconnectNamedPipe(tDados.hPipes[i])) {
			_tprintf(TEXT("[ERRO] Desligar o pipe! (DisconnectNamedPipe)"));
			exit(-1);
		}
		CloseHandle(tDados.hPipes[i]);
	}
	
	return 0;
		
	
}