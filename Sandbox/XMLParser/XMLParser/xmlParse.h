#pragma once
#include "pch.h"
#include <string>
#include <list>
using namespace std;

class xmlParse
{
public:
	xmlParse(const string&);
	xmlParse();

	void setString(string &str) { content = str; }
	string getString() const { return string(content); }
	void loadFileData(const string &);
	void saveDateToFile(const string& , list<unsigned int>& );

	string find(const string&, unsigned int = 0) const;
	list<string> findAll(const string&) const;

	class xmlException;
	class xmlIncorrectContent;
	class xmlEmpty;
	class fileNotOpened;
private:
	int searchPosition(const string&, unsigned int = 0) const;
	string content;
};

//Exceptions

class xmlParse::xmlException
{
public:
	xmlException(const string &);
	virtual ~xmlException() = 0;
	const string& getMessage() const;
private:
	string message;
};

class xmlParse::xmlIncorrectContent : public xmlException
{
public:
	xmlIncorrectContent();
};

class xmlParse::xmlEmpty : public xmlException
{
public:
	xmlEmpty();
};

class xmlParse::fileNotOpened : public xmlException
{
public:
	fileNotOpened(const string & fileName);
};