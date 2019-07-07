#include <windows.h> 
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <fstream>
#include <memory>

#include "FileGuard.h"
#include "ClientLogic.h"


#define BUFSIZE 4096

char * getFileContent(const char*);
int main(int argc, char *argv[])
{
	if (argc != 2) {
		_tprintf("Function get 1 param - path to the file.\r\n");
		return 1; //
	}

	 char* filePath = argv[1];

	_tprintf("The function is used to demonstrate interprocessor interaction so it does not use data more than 4096 bytes.\r\n");
	//char* filePath = "test.txt";
	auto content = make_shared<char *>(getFileContent(filePath)); 

	ClientLogic CL{};
	if (!CL.openPipe()) {
		if (!CL.sendMessage(*content.get())) {
			CL.printAnswer();
		}
	}

	_getch();
	return 0;
}

char * getFileContent(const char * textName)
{
	std::ifstream file(textName);
	if (file)
	{
		SimpleFileGuard FG(file);
		FG.getFile().seekg(0, std::ios::end);
		std::streampos length = FG.getFile().tellg() > BUFSIZE ? BUFSIZE : FG.getFile().tellg();
		FG.getFile().seekg(0, std::ios::beg);

		char* content = new char[length];
		FG.getFile().read(content, length);
		return content;
	}
	return nullptr;
}
