#include "pch.h"
#include "MyException.h"

MyException::MyException()
{
	message = "Something went wrong";
}

MyException::MyException(const string& msg) :
	message("exception: " + msg)
{

}

MyException::~MyException()
{

}

const string & MyException::getMessage() const
{
	return message;
}
