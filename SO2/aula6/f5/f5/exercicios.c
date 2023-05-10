#include <windows.h>
#include <tchar.h>
#include <math.h>

#include <stdio.h>
#include <fcntl.h> 
#include <io.h>


// funcionalidade relacionada com temporização

static double PerfCounterFreq; // n ticks por seg.
//ex1
/*
void initClock() {
	LARGE_INTEGER aux;
	if (!QueryPerformanceFrequency(&aux))
		_tprintf(TEXT("\nSorry - No can do em QueryPerfFreq\n"));
	PerfCounterFreq = (double)(aux.QuadPart); // / 1000.0;
	_tprintf(TEXT("\nTicks por sec.%f\n"), PerfCounterFreq);
}

__int64 startClock() {
	LARGE_INTEGER aux;
	QueryPerformanceCounter(&aux);
	return aux.QuadPart;
}

double stopClock(__int64 from) {
	LARGE_INTEGER aux;
	QueryPerformanceCounter(&aux);
	return (double)(aux.QuadPart - from) / PerfCounterFreq;
}

// estrutura de dados para controlar as threads

typedef struct {
	// ...
	int x; // remover este inteiro. Está aqui apenas para este código compilar
} TDados;

// função da(s) thread(s)
// ...

// número * máximo * de threads
// podem (e devem) ser menos
#define MAX_THREADS 20





int _tmain(int argc, TCHAR* argv[]) {

	// matriz de handles das threads
	HANDLE hThreads[MAX_THREADS];

	// Matriz de dados para as threads;
	TDados tdados[MAX_THREADS];

	// número efectivo de threads
	int numthreads;

	// limite superior
	unsigned int limsup;

	// variáveis para cronómetro
	__int64 clockticks;
	double duracao;

	unsigned int range;
	unsigned int inter;


#ifdef UNICODE 
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);
#endif

	initClock();
	_tprintf(TEXT("\nLimite sup. -> "));
	_tscanf_s(TEXT("%u"), &limsup);
	_tprintf(TEXT("\nNum threads -> "));
	_tscanf_s(TEXT("%d"), &numthreads);
	if (numthreads > MAX_THREADS)
		numthreads = MAX_THREADS;

	// FAZER prepara e cria threads
	//       manda as threads começar

	clockticks = startClock();

	// FAZER aguarda / controla as threads 
	//       manda as threads parar

	duracao = stopClock(clockticks);
	_tprintf(TEXT("\nSegundos=%f\n"), duracao);

	// FAZER apresenta resultados

	// Cód. ref. para aguardar por uma tecla – caso faça falta
	// _tprintf(TEXT("\nCarregue numa tecla"));
	// _gettch();

	return 0;
}
// Este código é apenas uma ajuda para o exercício. Se quiser, mude-o
*/

//ex2

void initClock() {
	LARGE_INTEGER aux;
	if (!QueryPerformanceFrequency(&aux))
		_tprintf(TEXT("\nSorry - No can do em QueryPerfFreq\n"));
	PerfCounterFreq = (double)(aux.QuadPart); // / 1000.0;
	_tprintf(TEXT("\nTicks por sec.%f\n"), PerfCounterFreq);
}

__int64 startClock() {
	LARGE_INTEGER aux;
	QueryPerformanceCounter(&aux);
	return aux.QuadPart;
}

double stopClock(__int64 from) {
	LARGE_INTEGER aux;
	QueryPerformanceCounter(&aux);
	return (double)(aux.QuadPart - from) / PerfCounterFreq;
}

// estrutura de dados para controlar as threads

typedef struct {
	int min;
	int max;
	int *sharedCounter; 
	HANDLE sharedMutex;
} TDados;

DWORD WINAPI CountMultipleThree(LPVOID lpParam) {
	unsigned int i;
	TDados* data = (TDados*)lpParam;
	for (i = data->min; i <= data->max; i++)
		if (i % 3 == 0) {
			WaitForSingleObject(data->sharedMutex, INFINITE);
			(*(data->sharedCounter)) ++;
			ReleaseMutex(data->sharedMutex);
		}
	return 0;
}

// número * máximo * de threads
// podem (e devem) ser menos
#define MAX_THREADS 20





int _tmain(int argc, TCHAR* argv[]) {

	unsigned int generalCounter = 0;

	// matriz de handles das threads
	HANDLE hThreads[MAX_THREADS];

	// Matriz de dados para as threads;
	TDados tdados[MAX_THREADS];

	// número efectivo de threads
	int numthreads;

	// limite superior
	unsigned int limsup;

	// variáveis para cronómetro
	__int64 clockticks;
	double duracao;

	unsigned int range;
	unsigned int inter;

	HANDLE mutex;
#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);
#endif

	initClock();
	mutex = CreateMutex(NULL, FALSE, NULL);
	if (mutex == NULL)
	{
		_tprintf(TEXT("Erro a criar mutex.\n"));
		return 1;
	}
	_tprintf(TEXT("\nLimite sup. -> "));
	_tscanf_s(TEXT("%u"), &limsup);
	_tprintf(TEXT("\nNum threads -> "));
	_tscanf_s(TEXT("%d"), &numthreads);
	if (numthreads > MAX_THREADS)
		numthreads = MAX_THREADS;

	// FAZER prepara e cria threads
	//       manda as threads começar
	int valorDivisao = 0;
	valorDivisao = limsup / numthreads;
	_tprintf(TEXT("\nDivisão: %d"), valorDivisao);

	for (int i = 0, j=1; i < numthreads - 1; i++) {
		tdados[i].min = j;
		tdados[i].max = valorDivisao * (i+1);
		tdados[i].sharedCounter = &generalCounter;
		tdados[i].sharedMutex = mutex;
		j = valorDivisao * (i+1) + 1;
		_tprintf(TEXT("\nmin: %d, max: %d "), tdados[i].min, tdados[i].max);
		hThreads[i] = CreateThread(
			NULL,
			0,
			CountMultipleThree,
			&tdados[i],
			CREATE_SUSPENDED,
			NULL);
	}
	tdados[numthreads-1].min = valorDivisao * (numthreads - 1);
	tdados[numthreads - 1].max = limsup;
	tdados[numthreads - 1].sharedCounter = &generalCounter;
	tdados[numthreads - 1].sharedMutex = mutex;
	_tprintf(TEXT("\nmin: %d, max: %d "), tdados[numthreads - 1].min, tdados[numthreads - 1].max);
	hThreads[numthreads - 1] = CreateThread(
		NULL,
		0,
		CountMultipleThree,
		&tdados[numthreads - 1],
		CREATE_SUSPENDED,
		NULL);

	
	clockticks = startClock();

	// FAZER aguarda / controla as threads
	//       manda as threads parar

	for (int i = 0; i < numthreads; i++)
		ResumeThread(hThreads[i]);
	WaitForMultipleObjects(numthreads, hThreads, TRUE, INFINITE);


	duracao = stopClock(clockticks);
	_tprintf(TEXT("\nCounter=%u\n"), generalCounter);
	_tprintf(TEXT("\nSegundos=%f\n"), duracao);

	// FAZER apresenta resultados
	for (int i = 0; i < numthreads; i++)
		CloseHandle(hThreads[i]);

	CloseHandle(mutex);
	

	// Cód. ref. para aguardar por uma tecla – caso faça falta
	// _tprintf(TEXT("\nCarregue numa tecla"));
	// _gettch();

	return 0;
}
// Este código é apenas uma ajuda para o exercício. Se quiser, mude-o