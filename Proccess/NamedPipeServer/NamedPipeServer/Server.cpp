#include <winsock2.h>
#include <windows.h>
#include <stdio.h> 
#include <tchar.h>
#include <strsafe.h>
#include "ServerLogic.h"

#define BUFSIZE 4096

DWORD WINAPI InstanceThread(LPVOID);
VOID GetAnswerToRequest(LPTSTR, LPTSTR, LPDWORD);

int main()
{
	ServerLogic SL{};
	SL.LaunchServer();
	return 0;
}