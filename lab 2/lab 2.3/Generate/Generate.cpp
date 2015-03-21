// Generate.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "GeneratePrimeNumbers.h"
#include <iostream>
#define maxVal 100000000

int StrToInt(const char *str, bool &err)
{
	char *pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = (((*str == '\0') || (*pLastChar != '\0')) && param <= maxVal);
	return param;
}

void PrintfSet(const set<int> &arr)
{
	if (!arr.empty())
	{
		
		for (set<int>::const_iterator it = arr.begin(); it != arr.end(); it++)
		{
			if (it == arr.begin())
				cout << *it;
			else
				cout << ", " << *it;
		}
		cout << endl;
	}
	else
	{
		cout << "set is empty" << endl;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "numb of arguments error(must be 2)" << endl;
		return 1;
	}

	bool error;
	int border = StrToInt(argv[1], error);
	if (error)
	{
		cout << "argument error" << endl << "must be greate as " << maxVal << " add be a number" << endl;
		return 1;
	}

	PrintfSet(GeneratePrimeNumbersSet(border));
	return 0;
}

