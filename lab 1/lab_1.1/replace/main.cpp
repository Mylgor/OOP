#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;
void WriteWordInFile(string Word, FILE *outputFile)
{
	int count = 0;
	while (Word[count] != '\0')
	{
		fputc(Word[count++], outputFile);
	}
}

void ReadingStr(FILE *inputFile, char *StrFromFile, int &count)
{
	char symbol = fgetc(inputFile);
	while (symbol != '\n' && symbol != EOF)
	{
		StrFromFile[count] = symbol;
		count++;
		symbol = fgetc(inputFile);
	}
	if (symbol == '\n')
	{
		StrFromFile[count++] = '\n';
	}
	StrFromFile[count] = '\0';
}

void MatchesTheFirstLetter(char *StrFromFile, int *indexs, int &count, const char &letter)
{
	for (int l = 0; StrFromFile[l] != '\0'; l++)
	{
		if (StrFromFile[l] == letter)
		{
			indexs[count] = l;
			count++;
		}
	}
}

void WriteInFile(int &start, int &end, char *str, FILE *f)
{
	while (start != end)
	{
		fputc(str[start], f);
		start++;
	}
}

void Replace(FILE *inputFile, FILE *outputFile, const string &searchWord, const string &replaceWord)
{	
	while (!feof(inputFile))
	{
		int countForFirstLetter = 0, countForStr = 0;
		int *indexs = new int[200];
		char *StrFromFile = new char[200];

		ReadingStr(inputFile, StrFromFile, countForStr);//считывание строки
		MatchesTheFirstLetter(StrFromFile, indexs, countForFirstLetter, searchWord[0]);//считывание индексов
		

		int k = 0, PositionInStr = 0;
		for (int i = 0; i < countForFirstLetter; i++)
		{
			for (int j = indexs[i]; j < indexs[i] + searchWord.size(); j++)
			{
				if (StrFromFile[j] == searchWord[k])
				{
					k++;
					if (k == searchWord.size())
					{
						WriteInFile(PositionInStr, indexs[i], StrFromFile, outputFile);
						WriteWordInFile(replaceWord, outputFile);
						PositionInStr += searchWord.size();
					}
				}
				else
				{
					k = 0;
					break;
				}
			}
		}
		WriteInFile(PositionInStr, countForStr, StrFromFile, outputFile);
		delete[] StrFromFile;
		delete[] indexs;
		StrFromFile = NULL;
		indexs = NULL;
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
	/*FILE *inputFile = fopen("input.txt", "rb");
	FILE *outputFile = fopen("output.txt", "wb");
	Replace(inputFile, outputFile, "MICRO", "BIG");*/

	fclose(inputFile);
	fclose(outputFile);
	inputFile = NULL;
	outputFile = NULL;
	return 0;
}