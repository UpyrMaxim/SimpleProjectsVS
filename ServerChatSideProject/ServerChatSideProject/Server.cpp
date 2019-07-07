#include "Server.h"



int Server::getPort()
{
	return portName;
}

void Server::setPort(int port)
{
	portName = port;
}

int Server::getBuffSize()
{
	return buffSize;
}

void Server::setBuffSize(int size)
{
	buffSize = size;
}

int Server::prepereServer()
{
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);
	int IResult = WSAStartup(ver, &wsData);
	if (IResult != 0)
	{
		std::cerr << "Error: Cant Initialize winSock!" << std::endl;
		return IResult;
	}

	createListeningSocket(); 
	initListeningSocket();

	return 0;
}

Server::Server() : portName(5740), buffSize(2048), ver(MAKEWORD(2, 2))
{
	FD_ZERO(&mainFD);
}


Server::~Server()
{
	std::string extMessage = "Someone write \\q, so server have to shutDown";
	while (mainFD.fd_count > 0)
	{
		// Get the socket number
		SOCKET sock = mainFD.fd_array[0];
		// Send the goodbye message
		send(sock, extMessage.c_str(), extMessage.size() + 1, 0);
		// Remove it from the master file list and close the socket
		FD_CLR(sock, &mainFD);
		closesocket(sock);		
	}

	if (mainFD.fd_count = 0)
		std::cout << "all sockets closed" << std::endl;
	WSACleanup();
}

void Server::addNewClient()
{
	// Accept a new connection
	SOCKET client = accept(listening, nullptr, nullptr);
	// Add the new connection to the list of connected clients
	FD_SET(client, &mainFD);

	// Send a welcome message to the connected client
	std::ostringstream ss;
	ss << "Welcome to Server!\r\nNow we have " << mainFD.fd_count - 1 << " users\r\n" << "Press \\q to shutDown the server\r\n";
	std::string welcomeMsg = ss.str();
	send(client, welcomeMsg.c_str(), welcomeMsg.size() + 1, 0);
}

int Server::createListeningSocket()
{
	listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET)
	{
		std::cerr << "Error: Cant create socket!" << std::endl;
	}
	return listening;
}

void Server::initListeningSocket()
{
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(5740);
	hint.sin_addr.S_un.S_addr = INADDR_ANY;

	bind(listening, (sockaddr*)&hint, sizeof(hint));

	// Tell Winsock the socket is for listening 
	int res = listen(listening, SOMAXCONN);
	// set FD by listening
	FD_SET(listening, &mainFD);
}

int Server::startJob()
{
	bool workInProccess = true;
	while (workInProccess)
	{
		// Make a copy of the master file descriptor, in other case we will lost clients
		fd_set copy = mainFD;

		// Check who's talking to us
		int socketCount = select(0, &copy, nullptr, nullptr, nullptr);
		// may be problems with a large number, but better than streams
		for (int i = 0; i < socketCount; i++)
		{
			SOCKET socket = copy.fd_array[i];
			// If is it an inbound communication
			if (socket == listening)
			{
				addNewClient();
			}
			else 
			{
				char * messageBuf = new char[getBuffSize()];
				ZeroMemory(messageBuf, getBuffSize());
				// Receive message
				int bytesIn = recv(socket, messageBuf, getBuffSize(), 0);
				if (bytesIn <= 0)
				{
					closesocket(socket);
					FD_CLR(socket, &mainFD);
				}
				else
				{
					// Check to exit comand
					if (messageBuf[0] == '\\')
					{
						std::string cmd = std::string(messageBuf, bytesIn);
						if (cmd == "\\q\r\n")
						{
							workInProccess = false;
							delete[] messageBuf;
							break;
						}
					}
					// Send messages to all clients except listening
					for (size_t i = 0; i < mainFD.fd_count; i++)
					{
						SOCKET outSock = mainFD.fd_array[i];
						if (outSock != listening && outSock != socket)
						{
							std::ostringstream ss;
							ss << socket << ": " << messageBuf << std::endl; // Bug with str end :( sometimes create empty string
							std::string strOut = ss.str();
							send(outSock, strOut.c_str(), strOut.size() + 1, 0);
						}
					}
				}
				delete[] messageBuf;
			}
		}
	}
	return 0;
}
