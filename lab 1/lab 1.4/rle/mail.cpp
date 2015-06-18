#include <iostream>
#include <fstream>

using namespace std;

void PackFile(ifstream &inputFile, ofstream &outputFile)
{
	char symbol, nextSymbol;
	int count = 1;
	
	inputFile.get(symbol);
	if (!inputFile.eof())
	{
		while (!inputFile.eof())
		{
			inputFile.get(nextSymbol);
			if (symbol == nextSymbol && count != 255)
			{
				count++;
			}
			else
			{
				if (symbol == '\n')
					outputFile << count << ", \\n" << ", " << symbol;
				else
					outputFile << count << ", " << symbol << ", ";
				symbol = nextSymbol;
				count = 1;
			}
		}
		if (count != 1)
			outputFile << count << ", " << symbol;
	}
	else
		cout << "file is empty" << endl;
}

int CharToInt(char &symbol, bool &err)
{
	int numb = atoi(&symbol);
	err = ((numb == 0 && symbol != '0') || (symbol == '\0'));
	return numb;
}

void UnpackFile(ifstream &inputFile, ofstream &outputFile)
{
	char symbol;
	int count, numb;
	bool error, flag = false;

	inputFile.get(symbol);
	while (!inputFile.eof())
	{
		count = CharToInt(symbol, error);
		if (error)
		{
			if (symbol != ',' && symbol != ' ')
			{
				if (symbol == '\n')
					outputFile << symbol;
				else
				{
					if (!flag)
					{
						cout << "error" << endl;
						outputFile.close();
						inputFile.close();
						exit(1);
					}
					else
					{
						for (; numb > 0; numb--)
						{
							outputFile << symbol;
						}
						flag = false;
					}
				}
			}
		}
		else
		{
			numb = count;
			flag = true;
		}
		inputFile.get(symbol);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		cout << "arguments error" << endl;
		return 1;
	}
	ifstream input(argv[2]);
	ofstream output(argv[3]);
	if (input.fail())
	{
		cout << "cannot open file: " << argv[2] << endl;
		return 1;
	}

	if (!strcmp(argv[1], "pack"))
	{
		PackFile(input, output);
	}
	else
	{
		if (!strcmp(argv[1], "unpack"))
		{
			UnpackFile(input, output);
		}
		else
		{
			cout << "argument error" << endl;
			return 1;
		}
	}

	output.close();
	input.close();
	return 0;
}