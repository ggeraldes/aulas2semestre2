#include <windows.h>
#include <tchar.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <string>

using namespace std;

//Permitir que o mesmo código possa funcionar para ASCII ou UNICODE
#ifdef UNICODE 
#define tcout wcout
#define tcin wcin
#define tstring wstring
#else
#define tcout cout
#define tcin cin
#define tstring string
#endif
//ficha1-----------------------------------------------
//ex5

//a)
/*
int _tmain(int argc, LPTSTR argv[]) {

    TCHAR BUFFER[256];
#ifdef UNICODE 
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
#endif
    
    GetModuleFileName(NULL, BUFFER, 256);
    tcout << lpFilename;
    
    return 0;
}
*/

//b)
/*
int _tmain(int argc, LPTSTR argv[]) {

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    TCHAR str[255];

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

#ifdef UNICODE 
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
#endif

    do {
        _fgetts(str, 255, stdin);
        str[_tcslen(str) - 1] = '\0';
        //Maiúsculas
        ZeroMemory(&si, sizeof(si));

        if (CreateProcess(NULL,   // No module name (use command line)
            str,        // Command line
            NULL,           // Process handle not inheritable
            NULL,           // Thread handle not inheritable
            0,          // Set handle inheritance to FALSE
            0,              // No creation flags
            NULL,           // Use parent's environment block
            NULL,           // Use parent's starting directory 
            &si,            // Pointer to STARTUPINFO structure
            &pi))           // Pointer to PROCESS_INFORMATION structure
                tcout << str << TEXT(" Executado\n");
    } while (str != TEXT("FIM"));

    return 0;
}
*/

//c)
/*
int _tmain(int argc, LPTSTR argv[]) {

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    TCHAR str[255], param[255];
    int k;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

#ifdef UNICODE 
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
#endif

    do {
        
        _fgetts(str, 255, stdin);
        str[_tcslen(str) - 1] = '\0';

        //Maiúsculas
        ZeroMemory(&si, sizeof(si));

        if (CreateProcess(NULL,   // No module name (use command line)
            str,        // Command line
            NULL,           // Process handle not inheritable
            NULL,           // Thread handle not inheritable
            0,          // Set handle inheritance to FALSE
            0,              // No creation flags
            NULL,           // Use parent's environment block
            NULL,           // Use parent's starting directory 
            &si,            // Pointer to STARTUPINFO structure
            &pi))           // Pointer to PROCESS_INFORMATION structure
            tcout << TEXT("\n") << str << TEXT(" Executado\n");
    } while (str != TEXT("FIM"));

    return 0;
}
*/

//d)

int _tmain(int argc, LPTSTR argv[]) {

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    TCHAR str[255], param[255];
    int vezes;

    

#ifdef UNICODE 
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
#endif
    GetModuleFileName(NULL, str, 255);

    if (argc == 1)
        vezes = 3;
    else
        vezes = _ttoi(argv[1]);
    if(vezes>0)
    {
        _tprintf(TEXT("fALTAM %d\n"), vezes);
        vezes--;
        //Maiúsculas
        _stprintf_s(str, 255, TEXT("%s %d"), str, vezes);
        ZeroMemory(&si, sizeof(STARTUPINFO));
        
        if (CreateProcess(NULL,   // No module name (use command line)
            str,        // Command line
            NULL,           // Process handle not inheritable
            NULL,           // Thread handle not inheritable
            0,          // Set handle inheritance to FALSE
            0,              // No creation flags
            NULL,           // Use parent's environment block
            NULL,           // Use parent's starting directory 
            &si,            // Pointer to STARTUPINFO structure
            &pi))           // Pointer to PROCESS_INFORMATION structure
            tcout << TEXT("\n") << str << TEXT(" Executado\n");

        WaitForSingleObject(pi.hProcess
            , INFINITE);
    }

    return 0;
}