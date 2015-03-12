#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

int CryMixingBits(int sym)
{
	bitset<8> symBits(sym);
	bitset<8> mixBits;
	mixBits[0] = symBits[5];
	mixBits[1] = symBits[6];
	mixBits[2] = symBits[0];
	mixBits[3] = symBits[1];
	mixBits[4] = symBits[2];
	mixBits[5] = symBits[7];
	mixBits[6] = symBits[0];
	mixBits[7] = symBits[4];
	return mixBits.to_ulong();
}

int DecryMixingBits(int sym)
{
	bitset<8> symBits(sym);
	bitset<8> mixBits;
	mixBits[5] = symBits[0];
	mixBits[6] = symBits[1];
	mixBits[0] = symBits[2];
	mixBits[1] = symBits[3];
	mixBits[2] = symBits[4];
	mixBits[7] = symBits[5];
	mixBits[0] = symBits[6];
	mixBits[4] = symBits[7];
	return mixBits.to_ulong();
}

void CryptFile(ifstream &inputFile, ofstream &outputFile, int key)
{
	char symbol;
	while (!inputFile.eof())
	{
		inputFile >> symbol;
		outputFile << (char)CryMixingBits(key ^ symbol);
	}
}

void DecryptFile(ifstream &inputFile, ofstream &outputFile, int key)
{
	char symbol;
	while (!inputFile.eof())
	{
		inputFile >> symbol;
		outputFile << (char)(key ^ DecryMixingBits(symbol));
	}
}

int main(int argc, char *argv[])
{
	if (argc != 5)
	{
		cout << "arguments error (must be 5)" << endl;
		return 1;
	}
	ifstream inputFile(argv[2]);
	if (inputFile.fail())
	{
		cout << "cannot open input file" << endl;
		return 1;
	}
	ofstream outputFile(argv[3]);

	bool error;
	int key = StringToInt(argv[4], error);
	if (error || key > 255 || key < 0)
	{
		cout << "incorrect key" << endl;
		inputFile.close();
		outputFile.close();
		return 1;
	}

	if (strcmp(argv[1], "crypt"))
		CryptFile(inputFile, outputFile, key);
	else
	{
		if (strcmp(argv[1], "decrypt"))
			DecryptFile(inputFile, outputFile, key);
		else
			cout << "arguments error" << endl;
	}

	inputFile.close();
	outputFile.close();
	return 0;
}