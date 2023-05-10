/*
#include <windows.h>
#include <tchar.h>
#include <math.h>

#include <stdio.h>
#include <fcntl.h> 
#include <io.h>

#define fileName TEXT("alfabeto.txt")


int _tmain(int argc, TCHAR* argv[]) {


	HANDLE ficheiro;
	HANDLE mapping;
	char* buf;
	TCHAR auxt, aux;



#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);
#endif

	

	ficheiro = CreateFile(
		fileName,
		GENERIC_WRITE | GENERIC_READ,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,                   // default security
		OPEN_EXISTING,             // create new file only
		FILE_ATTRIBUTE_NORMAL,  // normal file
		NULL
	);
	

	if (ficheiro == INVALID_HANDLE_VALUE)
	{
		_tprintf(TEXT("Terminal failure: Unable to open.\n"));
		return;
	}
	
	_tprintf(TEXT("Writing...\n"));

	mapping = CreateFileMapping(
		ficheiro,
		NULL,
		PAGE_READWRITE,
		0,
		26,
		NULL
	);

	if (mapping == NULL)
	{
		_tprintf(TEXT("Terminal failure: Unable to open!"));
		return;
	}
	_tprintf(TEXT("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));

	buf = (char*)MapViewOfFile(mapping, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 26);

	if (buf == NULL)
	{
		_tprintf(TEXT("Terminal failure: Unable to open!"));
		CloseHandle(ficheiro);
		return;
	}

	for (unsigned int i = 0; i < 26/2; i++) {
		aux = buf[i];
		buf[i] = buf[26 - 1 - i];
		buf[26 - 1 - i]=aux;
	}

	for (unsigned int i = 0; i < 26; i++) {
		auxt = buf[i];
		_tprintf(TEXT("%c"), auxt);
	}

	_tprintf(TEXT("\ndone\n"));
	UnmapViewOfFile(buf);
	CloseHandle(mapping);
	CloseHandle(ficheiro);



	return 0;
}*/