#pragma once

#include <windows.h> 
#include <stdio.h> 
#include <tchar.h>
#include <strsafe.h>


#define BUFSIZE 4096

class ServerLogic
{
public:
	ServerLogic();
	~ServerLogic();
	int LaunchServer();

private:
	BOOL   fConnected;
	DWORD  dwThreadId;
	HANDLE hPipe, hThread;
	LPTSTR lpszPipename;

private:
	static DWORD WINAPI InstanceThread(LPVOID);
	static VOID GetAnswerToRequest(LPTSTR, LPTSTR, LPDWORD);
	static LPTSTR getHASH(LPTSTR);
};

