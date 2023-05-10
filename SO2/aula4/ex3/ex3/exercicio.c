#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "SO2_F3_DLL.h"

#define TAM 200

typedef double(*applyFactorFunc)(double);


//ex2

int _tmain(int argc, TCHAR* argv[])
{
    HINSTANCE hLib;
    double* var;
    applyFactorFunc procAdd;
    double val;

#ifdef UNICODE
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
#endif

    hLib = LoadLibrary(TEXT("SO2_F3_DLL.dll"));
    if (hLib != NULL) {
        _tprintf(TEXT("Erro a carregar DLL"));
        return 1;
    }

    var = (double*)GetProcAddress(hLib, "factor");
    procAdd = (applyFactorFunc)GetProcAddress(hLib, "applyFactor");

    if (var == NULL || procAdd == NULL) {
        _tprintf(TEXT("Erro varAdd ou procAdd"));
        return 1;
    }

    do {
        _tprintf(TEXT("Introduza o valor de a:"));
        _tscanf_s(TEXT("%lf"), &*var);

        _tprintf(TEXT("Introduza o valor de b:"));
        _tscanf_s(TEXT("%lf"), &val);


        _tprintf(TEXT("%lf * %lf = : %lf\n"), *var, val, procAdd(val));

    } while (*var != -1);

    FreeLibrary(hLib);
    return 0;
}