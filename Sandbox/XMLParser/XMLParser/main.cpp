#include "pch.h"
#include <string>
#include <list>
#include <thread>
#include <mutex>
#include "interval.h"
#include "xmlParse.h"
using namespace std;

void defineIntervals(xmlParse & xmlParser, list<interval>& interList);
void findPrimes(const interval, list<unsigned int>&, mutex&);
inline bool is_prime(unsigned int);

int main(int argc, char* argv[])
{
	auto fileName = "file.xml";
	xmlParse xmlParser{};


	list<interval> intervalList;
	defineIntervals(xmlParser, intervalList);

	list<unsigned int> resultList;
	list<thread> threads;
	mutex access;
	for (auto iter : intervalList)
		threads.push_back(thread(findPrimes, iter, ref(resultList), ref(access)));
	for (auto &thr : threads)
		if (thr.joinable()) thr.join();

	resultList.sort();
	resultList.unique();
	xmlParser.loadFileData(fileName);
	xmlParser.saveDateToFile(fileName, resultList);

	return 0;
}

void defineIntervals(xmlParse & xmlParser, list<interval>& interList)
{
	try
	{
		xmlParser.loadFileData("file.xml");
		string intervals = xmlParser.find("intervals");
		xmlParser.setString(intervals);

		list<string> stringsList = xmlParser.findAll("interval");
		auto left = 0, right = 0;
		for (auto iterInter = stringsList.begin(); iterInter != stringsList.end(); iterInter++)
		{
			xmlParser.setString(*iterInter);
			left = atoi(xmlParser.find("low").c_str());
			right = atoi(xmlParser.find("high").c_str());
			interList.push_back(interval(left, right));
		}
	}
	catch (const xmlParse::xmlException& exp)
	{
		cerr << exp.getMessage() << endl;
	}
	catch (const std::exception & exp)
	{
		cerr << exp.what() << endl;
	}
	catch (...)
	{
		cerr << "Unknown error!\n";
	}
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

