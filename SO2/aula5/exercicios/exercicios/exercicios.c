#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>

//ficha4

//ex1

typedef struct {
    int somaPares;
    int somaPrimos;
    int cimaPares;
    int baixoPares;
    int cimaPrimos;
    int baixoPrimos;
}TDADOS;



DWORD WINAPI somaPares(LPVOID param) {

    TDADOS *dados = (TDADOS*)param;
    int count = 0;
    for (int i = dados->baixoPares; i < dados->cimaPares; i++) {
        if (i % 2 == 0) {
            dados->somaPares += i;
            count++;
        }
        if (count == 200) {
            count = 0;
            _tprintf(_T("\nPAUSA NOS PARES"));
            Sleep(1000);
        }
    }
    _tprintf(_T("\nresultado para pares: %d"), dados->somaPares);
    return 7;
}

DWORD WINAPI somaPrimos(LPVOID param) {

    TDADOS* dados = (TDADOS*)param;
    int count = 0, flagP=0;
    for (int i = dados->baixoPrimos; i < dados->cimaPrimos; i++) {
        for (int j = 2; j < i; j++)
            if (i % j == 0) {
                flagP = 1;
                break; 
            }
        if (flagP == 0) {
            dados->somaPrimos += i;
            count++;
        }
        flagP = 0;
       
        if (count == 15) {
            count = 0;
            _tprintf(_T("\nPAUSA NOS PRIMOS"));
            Sleep(1000);
        }
    }
    _tprintf(_T("\nresultado para primos: %d"), dados->somaPrimos);
    return 7;
}

int _tmain(int argc, TCHAR* argv[]) {
    

    DWORD dwTid[2];
    HANDLE hthread[2];
    TDADOS dados;

    int indice;

    dados.somaPares = 0;
    dados.somaPrimos = 0;

#ifdef UNICODE 
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
    _setmode(_fileno(stderr), _O_WTEXT);
#endif
        _tprintf(_T("Digite o lim. min dos pares: "));
        _tscanf_s(_T("%d"), &dados.baixoPares);

        _tprintf(_T("\nDigite o lim. max dos pares: "));
        _tscanf_s(_T("%d"), &dados.cimaPares);
        
        _tprintf(_T("\nDigite o lim. min dos primos: "));
        _tscanf_s(_T("%d"), &dados.baixoPrimos);
        
        _tprintf(_T("\nDigite o lim. max dos primos: "));
        _tscanf_s(_T("%d"), &dados.cimaPrimos);

        hthread[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)somaPrimos, (LPVOID)&dados, 0, &dwTid[0]);
        hthread[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)somaPares, (LPVOID)&dados, 0, &dwTid[1]);

        indice = WaitForMultipleObjects(2, hthread, FALSE, INFINITE);

        for (int i = 0; i < 2; i++)
            if (i != indice)
                indice = WaitForSingleObjectEx(hthread[i], INFINITE, TRUE);
            else if (i == 0)
                _tprintf(_T("\nresultado para primos: %d"), dados.somaPrimos);
            else
                _tprintf(_T("\nresultado para pares: %d"), dados.somaPares);

        if(indice==0)
            _tprintf(_T("\nresultado para primos: %d"), dados.somaPrimos);
        else
            _tprintf(_T("\nresultado para pares: %d"), dados.somaPares);
        CloseHandle(hthread);


        //_tprintf(_T("\nresultado para pares: %d\nresultado para primos: %d"), dados.somaPares, dados.somaPrimos);




    return 0;
}