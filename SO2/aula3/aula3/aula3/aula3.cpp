#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>

#define TAM 200

int _tmain(int argc, TCHAR* argv[]) {
    HKEY chave;
    TCHAR chave_nome[TAM], par_nome[TAM], par_valor[TAM];

    /* ... Mais variáveis ... */

#ifdef UNICODE 
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
    _setmode(_fileno(stderr), _O_WTEXT);
#endif

    //2. Para testar fazer os pontos a, b, c... um por um
        //a)
            /*  
            _tprintf(_T("Indique a chave: "));
            _tscanf_s(_T("%s"), chave_nome, TAM - 1);
            

            LSTATUS res;
            DWORD estado, tipo,num, tam=1;

            RegCreateKeyEx(HKEY_CURRENT_USER, chave_nome, 0, NULL, REG_OPTION_NON_VOLATILE,
                KEY_ALL_ACCESS, NULL, &chave, &estado);
               

            if (estado == REG_OPENED_EXISTING_KEY)
                _tprintf(_T("Chave já existente.\n"));

            else  if (estado == REG_CREATED_NEW_KEY)
                _tprintf(_T("Chave registada com sucesso.\n"));
          */

        //b)
            /*
            _tprintf(_T("Indique o nomedo para o campo: "));
            _tscanf_s(_T("%s"), par_nome, TAM - 1);
            _tprintf(_T("Indique o valor (texto): "));
            _tscanf_s(_T("%s"), par_valor, TAM - 1);

            RegOpenKeyEx(HKEY_CURRENT_USER, _T("aula3"), 0, KEY_ALL_ACCESS, &chave);

            if (RegSetValueEx(chave, par_nome, 0, REG_SZ, (LPBYTE)par_valor,
                (_tcslen(par_valor) + 1) * sizeof(TCHAR)) == ERROR_SUCCESS)
                _tprintf(_T("Chave existe.\n"));
            else
                _tprintf(_T("ERRO - Ao criar o par valor"));
            */
            
        //c)
            _tprintf(_T("Indique o nomedo para o campo: "));
            _tscanf_s(_T("%s"), par_nome, TAM - 1);
            _tprintf(_T("Indique o valor (texto): "));
            _tscanf_s(_T("%s"), par_valor, TAM - 1);
            DWORD tam;

            RegOpenKeyEx(HKEY_CURRENT_USER, _T("aula3"), 0, KEY_ALL_ACCESS, &chave);

            if (RegQueryValueEx(chave, _T("Nome"),NULL, NULL,(LPBYTE)par_valor, &tam) == ERROR_SUCCESS)
                _tprintf(_T("Nome > %s.\n"), par_valor);

            tam = sizeOf(DWORD);
            if (RegQueryValueEx(chave, _T("Nome"), NULL, NULL, (LPBYTE)par_valor, &tam) == ERROR_SUCCESS)
                _tprintf(_T("Nome > %s.\n"), par_valor);
            
            else
                _tprintf(_T("ERRO - Ao criar o par valor"));
                
        //d)
            if (RegEnumValue(chave, 1, par_nome, &tam, NULL, NULL, NULL, NULL) == ERROR_SUCCESS) {
                //_tprintf(_T("par %d > %"))
                    i++;
                tam = TAM;
            }
           

                

    return 0;
}