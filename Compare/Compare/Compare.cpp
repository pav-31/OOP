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

int FileComparison(istream & file1, istream & file2)
{
	string stringFromFile1;
	string stringFromFile2;

	int lineNumber = 1;
	
	while ((!file1.eof()) || (!file2.eof()))
	{
		getline(file1, stringFromFile1);
		getline(file2, stringFromFile2);

		if (stringFromFile1 != stringFromFile2)
		{
			return lineNumber;
		}
		else
		{
			++lineNumber;
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count" << endl
			<< "Usage: compare.exe <input file1> <input file2>" << endl;
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

	int resultOfComparsion = FileComparison(file1, file2);
	
	if (resultOfComparsion != 0)
	{
		cout << "Files are different. Line number is " << resultOfComparsion << endl;
		return 1;
	}

	cout << "Files are equal" << endl;

	return 0;
}
