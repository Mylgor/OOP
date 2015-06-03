// lab 3.3.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	if (!(file.Open("input.txt", "r")))//������
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

	ReverseMass(mass);//��������������
	

	if (!(file.Open("input.txt", "w")))//�������
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

