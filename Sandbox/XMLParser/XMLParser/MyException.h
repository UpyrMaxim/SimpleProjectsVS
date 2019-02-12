#pragma once
#include <string>
#include <list>
using namespace std;

class MyException
{
public:
	MyException();
	MyException(const string&);
	virtual ~MyException() = 0;
	const string& getMessage() const;
private:
	string message;
};

