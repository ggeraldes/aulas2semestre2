//  ex2
/*#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <ctype.h> 
#define MAX 256

int main(int argc, char* argv[]) {
    char result[MAX] = "Ol�! Este programa ainda n�o representa UNICODE\n";
    printf("Frase:%s Tamanho:%d\n", result, strlen(result));
    getchar();
    return 0;
}
*/

//  ex3
/*
#include <windows.h>
#include <tchar.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#define MAX 256

int _tmain(int argc, LPTSTR argv[]) {
    TCHAR str[MAX], result[MAX] = TEXT("Ol�! Este programa � para aceitar UNICODE. Insira \'fim\' para sair\n");
    unsigned int i;
    //UNICODE: Por defeito, a consola Windows n�o processa caracteres wide. 
    //A maneira mais f�cil para ter esta funcionalidade � chamar _setmode:
#ifdef UNICODE 
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
#endif
    do {
        _tprintf(result);
        fflush(stdin);
        _fgetts(str, MAX, stdin);
        //Retirar \n
        str[_tcslen(str) - 1] = '\0';
        //Mai�sculas
        for (i = 0; i < _tcslen(str); i++)
            str[i] = _totupper(str[i]);
        _stprintf_s(result, MAX, TEXT("Frase:%s, Tamanho:%d\n"), str, _tcslen(str));
    } while (_tcsicmp(TEXT("FIM"), str));
    return 0;
}
*/
