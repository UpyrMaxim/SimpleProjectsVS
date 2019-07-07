#pragma once
#include <iostream>
#include <WS2tcpip.h>
#include <string>
#include <sstream>

#pragma comment (lib, "ws2_32.lib")
class Server
{
//methods
public:
	int getPort();
	void setPort(int port);
	int getBuffSize();
	void setBuffSize(int size);
	int prepereServer();
	int startJob();
	Server();
	~Server();

//fields
private:
	int portName;
	int buffSize;
	WSADATA wsData;
	WORD ver;
	SOCKET listening;
	fd_set mainFD;

//methods
private:
	void addNewClient();
	int createListeningSocket();
	void initListeningSocket();
};

