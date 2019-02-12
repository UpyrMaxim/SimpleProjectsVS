#pragma once
#include "pch.h"
#include "MyException.h"
#include <string>
#include <list>

using namespace std;

class xmlParse
{
public:
	xmlParse();
	xmlParse(const string& str);

	void setString(string& str) { content = str; }
	string getString() const { return string(content); }
	string makeXMLString(list<unsigned int>& result);
	string find(const string&, unsigned int = 0) const;
	list<string> findAll(const string&) const;

	class xmlIncorrectContent;
	class xmlEmpty;
	class fileNotOpened;
private:
	int searchPosition(const string&, unsigned int = 0) const;
	string content;
};

//Exceptions

class xmlParse::xmlIncorrectContent : public MyException
{
public:
	xmlIncorrectContent();
};

class xmlParse::xmlEmpty : public MyException
{
public:
	xmlEmpty();
};

class xmlParse::fileNotOpened : public MyException
{
public:
	fileNotOpened(const string&);
};