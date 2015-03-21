#include "stdafx.h"
#include "WokWithMap.h"

bool isWord(char const &sym)
{
	if ((sym >= 'a' && sym <= 'z') || (sym >= 'A' && sym <= 'Z'))
		return true;
	return false;
}

void AddWord(string const &word, map<string, int> &arr)
{
	if (arr.find(word) != arr.end())
	{
		arr[word]++;
	}
	else
	{
		arr.insert(pair<string, int>(word, 1));
	}
}

map<string, int> FrequencyOfCccurrenceOfWords(string const &str)
{
	map<string, int> arrWords;
	string word;
	int i = 0;

	while (i < (int)str.size())
	{
		if (isWord(str[i]))
		{
			while ((str[i] != ' ') && (str[i] != '\n') && (str[i] != '\t') && (i < (int)str.size()))
			{
				word += str[i];
				i++;
			}
			if (!word.empty())
				AddWord(word, arrWords);
			word.erase();
		}
		i++;
	}

	return arrWords;
}

void PrintMap(map<string, int> &wordsMass)
{
	for (auto it = wordsMass.begin(); it != wordsMass.end(); it++)
	{
		cout << (*it).first << " : " << (*it).second << endl;
	}
}