#include "pch.h"
#include "xmlParse.h"

xmlParse::xmlParse()
{
}

xmlParse::xmlParse(const string& strContent) : content(strContent)
{
}


string xmlParse::makeXMLString(list<unsigned int>& contentList)
{
	string resStr;
	for (auto iter : contentList) {
		resStr += to_string(iter) + ' ';
	}
	resStr = "\n  <primes> " + resStr + "</primes>";
	return forward<string>(resStr);
}

string xmlParse::find(const string& findTag, unsigned int beginPosition) const
{
	if (content.length() == 0)
		throw xmlEmpty();

	auto tagBegin = '<' + findTag + '>';
	auto tagEnd = "</" + findTag + '>';
	int begin = beginPosition, end = 0;

	begin = searchPosition(tagBegin, beginPosition);
	if (begin == -1)
		return "";
	begin += tagBegin.length();

	end = searchPosition(tagEnd, begin);
	if (end == -1)
		throw xmlIncorrectContent();

	return string(content, begin, end - begin);
}

list<string> xmlParse::findAll(const string& findTag) const
{
	if (content.length() == 0)
		throw xmlEmpty();

	auto tagEnd = "</" + findTag + '>';
	list<string> searchedList;
	auto position = 0;
	string iterationResult;
	for (;;)
	{
		iterationResult = find(findTag, position);
		if (iterationResult == "")
			break;
		searchedList.push_back(iterationResult);
		position = searchPosition(tagEnd, position + tagEnd.length());
	}
	return list<string>(searchedList);
}

int xmlParse::searchPosition(const string& tag, unsigned int beginPosition) const
{
	bool successful = false;
	for (auto i = beginPosition; i < content.length(); i++)
	{
		if (content[i] == tag[0])
		{
			successful = true;
			for (auto j = 1; j < tag.length(); j++)
			{
				if (content[i + j] != tag[j])
				{
					successful = false;
					break;
				}
			}
			if (successful)
				return i;
		}
	}
	return -1;
}


xmlParse::xmlIncorrectContent::xmlIncorrectContent() :
	MyException("Incorrect content for parse.")
{
}

xmlParse::xmlEmpty::xmlEmpty() :
	MyException("Attempt to parse the empty file.")
{
}

xmlParse::fileNotOpened::fileNotOpened(const string& fileName) :
	MyException("Failed to open the file \"" + fileName + "\"")
{
}