#pragma once

#include <windows.h> 
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <fstream>
#include <memory>

#define BUFSIZE 4096

class ClientLogic
{
public:
	int openPipe();
	int sendMessage(const char*);
	int printAnswer();
	ClientLogic();
	~ClientLogic();

private:
	HANDLE hPipe;
	TCHAR  chBuf[BUFSIZE];
	BOOL   fSuccess;
	DWORD  cbRead, cbToWrite, cbWritten, dwMode;
	LPTSTR lpszPipename;

private:
	int changePipeToReadMode();
};

