// lab 3.3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CFile.h"

void ReverseMass(vector<int> &mass)
{
	vector<int> revMass;
	int symbol;
	for (int i = mass.size() - 1; i >= 0; i--)
	{
		symbol = mass[i];
		revMass.push_back(symbol);
	}
	mass = revMass;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CCFile file;
	if (!(file.Open("input.txt", "r")))//читаем
	{
		cout << "input file error" << endl;
		return EOF;
	}
	
	vector<int> mass;
	int symbol, count = 0;
	while (!file.IsEndOfFile())
	{
		symbol = file.GetChar();
		if (symbol > 0)
		{
			mass.push_back(symbol);
			count++;
		}
	}

	ReverseMass(mass);//реверсирование
	

	if (!(file.Open("input.txt", "w")))//выводим
	{
		cout << "input file error" << endl;
		return EOF;
	}
	for each (int var in mass)
	{
		file.PutChar(var);
	}
	file.~CCFile();
	return 0;
}

