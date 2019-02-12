#pragma once
#include "MyException.h"

using namespace std;

class FileService
{
public:
	static string loadFileData(const string&);
	static void insertToFileBefore(const string&, const string&, const string&);
	class fileNotOpened;
	FileService();
	~FileService();
};

class FileService::fileNotOpened : public MyException
{
public:
	fileNotOpened(const string&);
};

