#include "pch.h"
#include "xmlParse.h"

xmlParse::xmlParse(const string & fileName)
{
	loadFileData(fileName);
}

xmlParse::xmlParse()
{}

void xmlParse::loadFileData(const string & fileName)
{
	ifstream ifs(fileName);
	if (!ifs.is_open())
		throw fileNotOpened(fileName);
	content.assign((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));
}

void xmlParse::saveDateToFile(const string& fileName, list<unsigned int>& result)
{
	string res;
	for (auto iter : result)
		res += to_string(iter) + ' ';
	res = "\n  <primes> " + res + "</primes>";

	auto pos = content.find_last_of("</root>") - sizeof("<root>");
	content.insert(pos, res);

	ofstream file('n' + fileName);
	if (!file.is_open())
		throw fileNotOpened(fileName);
	file << content;
	file.close();
}

//Returns a substring between first <findTeg> and </findTag>,
//beginPosition - from where will be performed search
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

//Returns list of results find(..).
list<string> xmlParse::findAll(const string & findTag) const
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

//Returns position of first symbol of find tag ('<')
int xmlParse::searchPosition(const string & tag, unsigned int beginPosition) const
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


xmlParse::xmlException::xmlException(const string & msg) :
	message("XML exception: " + msg)
{}

xmlParse::xmlException::~xmlException()
{}

const string & xmlParse::xmlException::getMessage() const
{
	return message;
}

xmlParse::xmlIncorrectContent::xmlIncorrectContent() :
	xmlException("incorrect content for parse.")
{}

xmlParse::xmlEmpty::xmlEmpty() :
	xmlException("attempt to parse the empty file.")
{}

xmlParse::fileNotOpened::fileNotOpened(const string & fileName) :
	xmlException("Failed to open the file \"" + fileName + "\"")
{}