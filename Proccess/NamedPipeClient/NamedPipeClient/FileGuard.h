#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class SimpleFileGuard {
public:
	SimpleFileGuard(ifstream &file) : fileUnderProtect(&file) { }
	ifstream &getFile() {
		return *fileUnderProtect;
	}

	~SimpleFileGuard() {
		if (fileUnderProtect != nullptr)
		{
			fileUnderProtect->close();
			cout << "File was closed" << endl;
		}
	}

private:
	ifstream *fileUnderProtect;
};