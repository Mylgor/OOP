#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

void WriteWordInFile(string replaceWord, FILE *outputFile)
{
	int count = 0;
	while (replaceWord[count] != '\0')
	{
		fprintf(outputFile, "%c", replaceWord[count++]);
	}
}

void Replace(FILE *inputFile, FILE *outputFile, const string &searchWord, const string &replaceWord)
{
	char symbol, *str = new char;
	int i = 0;
	int searchWordLen = searchWord.size();
	str[i] = '\0';

	while ((symbol = fgetc(inputFile)) != EOF)
	{
		if (symbol == searchWord[i])
		{
			str[i] = symbol;
			i++;
			if (i == searchWordLen)
			{
				WriteWordInFile(replaceWord, outputFile);
				i = 0;
				str[i] = '\0';
			}
		}
		else
		{
			if (*str != '\0')
			{
				str[i] = '\0';
				WriteWordInFile(str, outputFile);
				str[0] = '\0';
			}
			i = 0;
			fprintf(outputFile, "%c", symbol);
		}
	}

	if (*str != '\0')
	{
		str[i] = '\0';
		WriteWordInFile(str, outputFile);
	}
}

void Tests(FILE *inputFile, FILE *outputFile, string arg1, string arg2)
{
	if (inputFile == NULL)
	{
		cout << "Cannot open input file" << endl;
		_getch();
		exit(1);
	}
	if (outputFile == NULL)
	{
		cout << "Cannot open output file" << endl;
		fclose(inputFile);
		inputFile = NULL;
		_getch();
		exit(1);
	}
	if ((arg1.size() == 0) || (arg2.size() == 0))
	{
		cout << "word lenght must be greater than zero" << endl;
		exit(1);
	}
}

int main(int argc, char* argv[])
{	
	if (argc != 5)
	{
		cout << "Arguments error" << endl;
		_getch();
		return 1;
	}

	FILE *inputFile = fopen(argv[1], "rb");
	FILE *outputFile = fopen(argv[2], "wb");

	Tests(inputFile, outputFile, argv[3], argv[4]);
	Replace(inputFile, outputFile, argv[3], argv[4]);

	fclose(inputFile);
	fclose(outputFile);
	inputFile = NULL;
	outputFile = NULL;
	return 0;
}