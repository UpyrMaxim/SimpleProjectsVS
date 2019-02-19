#include "pch.h"
#include "FileService.h"


string FileService::loadFileData(const string& fileName)
{
	string content;
	ifstream ifile(fileName);
	if (!ifile.is_open())
		throw fileNotOpened(fileName);
	content.assign((std::istreambuf_iterator<char>(ifile)),
		(std::istreambuf_iterator<char>()));
	return forward<string>(content);
}

void FileService::insertToFileBefore(const string& fileName, const string& stringData, const string& beforeXmlElement = "root")
{
	string content = loadFileData(fileName);
	auto pos = content.find_last_of("</" + beforeXmlElement + ">") - ("</" + beforeXmlElement  + ">").size();
	content.insert(pos, stringData);

	ofstream file(fileName);
	if (!file.is_open())
		throw fileNotOpened(fileName);
	file << content;
	file.close();
}

FileService::FileService()
{
}


FileService::~FileService()
{
}

FileService::fileNotOpened::fileNotOpened(const string& fileName) :
	MyException("Failed to open the file \"" + fileName + "\"")
{
}
