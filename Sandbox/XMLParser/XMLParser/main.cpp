#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <thread>
#include <mutex>
#include "interval.h"
#include "xmlParser.h"
using namespace std;

bool loadFile(const string&, string&);
bool saveData(const string&, list<unsigned int>&, string&);
bool defineIntervals(const string&, list<interval>&);
void findPrimes(const interval, list<unsigned int>&, mutex&);
inline bool is_prime(unsigned int);

int main(int argc, char* argv[])
{
	auto fileName = "file.xml";
	string content;
	if (!loadFile(fileName, content))
	{
		cerr << "File \"" << fileName << "\" not found.";
		return 0;
	}

	list<interval> intervalList;
	if (!defineIntervals(content, intervalList))
	{
		return 1;
	}

	//------------
	list<unsigned int> resultList;
	list<thread> threads;
	mutex access;
	for (auto iter : intervalList)
		threads.push_back(thread(findPrimes, iter, ref(resultList), ref(access)));
	for (auto &thr : threads)
		if (thr.joinable()) thr.join();
	//------------

	resultList.sort();
	resultList.unique();
	saveData(fileName, resultList, content);

	cin.ignore();
	return 0;
}

//load all data from file to 'fileContent'
bool loadFile(const string& fileName, string& fileContent)
{
	ifstream file(fileName);
	if (!file.is_open())
		return false;
	getline(file, fileContent, '\0');
	file.close();
	return true;
}

//save all data to xml-file
bool saveData(const string& fileName, list<unsigned int>& result, string& content)
{
	string res;
	for (auto iter : result)
		res += to_string(iter) + ' ';
	res = "\n  <primes> " + res + "</primes>";

	auto pos = content.find_last_of("</root>") - sizeof("<root>");
	content.insert(pos, res);

	ofstream file('n' + fileName);
	if (!file.is_open())
		return false;
	file << content;
	file.close();
	return true;
}

//load intervals to 'interList'
bool defineIntervals(const string& fileContent, list<interval>& interList)
{
	try
	{
		xmlParse parse(fileContent);
		string intervals = parse.find("intervals");
		parse.setString(intervals);

		list<string> stringsList = parse.findAll("interval");
		auto left = 0, right = 0;
		for (auto iterInter = stringsList.begin(); iterInter != stringsList.end(); iterInter++)
		{
			parse.setString(*iterInter);
			left = atoi(parse.find("low").c_str());
			right = atoi(parse.find("high").c_str());
			interList.push_back(interval(left, right));
		}
	}
	catch (const xmlParse::xmlException& exp)
	{
		cerr << exp.getMessage() << endl;
		return false;
	}
	catch (const std::exception & exp)
	{
		cerr << exp.what() << endl;
		return false;
	}
	catch (...)
	{
		cerr << "Unknown error!\n";
		return false;
	}
	return true;
}

//creates new thread and calculate all primes at interval
void findPrimes(const interval inter, list<unsigned int>& result, mutex& access)
{
	access.lock();
	cout << "Thread " << this_thread::get_id() << ":\t started \t(" << inter.getLeft() << " - " << inter.getRight() << ')' << endl;
	access.unlock();

	for (unsigned int idx = inter.getLeft(); idx < inter.getRight(); idx++)
	{
		if (is_prime(idx))
		{
			access.lock();
			result.push_back(idx);
			access.unlock();
		}
	}

	access.lock();
	cout << "Thread " << this_thread::get_id() << ":\t finish \t(" << inter.getLeft() << " - " << inter.getRight() << ')' << endl;
	access.unlock();
}

//returns true if number is prime
inline bool is_prime(unsigned int number)
{
	for (auto i = 2; i < sqrt(number) + 1; i++)
		if (number%i == 0)
			return false;
	return true;
}

