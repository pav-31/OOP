#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool CheckFileOpening(ifstream & file)
{
	if (!file.is_open())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool FileComparison(ifstream & file1, ifstream & file2, int & lineNumber)
{
	string stringFromFile1;
	string stringFromFile2;

	while ((!file1.eof()) || (!file2.eof()))
	{
		getline(file1, stringFromFile1);
		getline(file2, stringFromFile2);

		if (stringFromFile1 == stringFromFile2)
		{
			++lineNumber;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count" << endl
			<< "Usage: copyfile.exe <input file1> <input file2>" << endl;
		return 1;
	}

	ifstream file1(argv[1]);

	if (!CheckFileOpening(file1))
	{
		cout << "Failed to open " << argv[1] << " for reading" << endl;
		return 1;
	}

	ifstream file2(argv[2]);

	if (!CheckFileOpening(file2))
	{
		cout << "Failed to open " << argv[2] << " for reading" << endl;
		return 1;
	}

	int lineNumber = 1;

	if (!FileComparison(file1, file2, lineNumber))
	{
		cout << "Files are different. Line number is " << lineNumber << endl;
		return 1;
	}
	else
	{
		cout << "Files are equal" << endl;
	}

	return 0;
}