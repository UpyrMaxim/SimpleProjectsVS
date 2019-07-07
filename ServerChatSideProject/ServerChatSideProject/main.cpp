
#include "server.h"


using namespace std;

void main()
{
	Server server;
	server.prepereServer(); // by default port == 5740, buffSize == 2048
	server.startJob();
}