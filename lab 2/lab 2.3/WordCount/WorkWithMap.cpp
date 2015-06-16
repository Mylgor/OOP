#include "stdafx.h"
#include "WokWithMap.h"

bool isWord(char const &sym)
{
	if ((sym >= 'a' && sym <= 'z') || (sym >= 'A' && sym <= 'Z'))
		return true;
	if ((sym >= 'à' && sym <= 'ÿ') || (sym >= 'À' && sym <= 'ß'))
		return true;
	return false;
}

string UpWord(string const &word)
{
	string checkWord;
	for (int i = 0; i < (int)word.size(); i++)
	{
		checkWord += (char)toupper(word[i]);
	}
	return checkWord;
}

void AddWord(string const &word, map<string, int> &arr)
{
	bool isAdd = false;
	if (!word.empty())
	{
		for (auto it = arr.begin(); it != arr.end() && !isAdd; it++)
		{
			if (UpWord(word) == UpWord((*it).first))
			{
				(*it).second++;
				isAdd = true;
			}
		}
		if (!isAdd)
		{
			arr.insert(pair<string, int>(word, 1));
		}
	}
}

map<string, int> CalculFrequencyOfCccurrenceOfWords(string const &str)
{
	map<string, int> arrWords;
	string word;
	int i = 0;

	while (i < (int)str.size())
	{
		if (isWord(str[i]))
		{
			word += str[i];
		}
		else
		{
			AddWord(word, arrWords);
			word.erase();
		}
		i++;
	}

	AddWord(word, arrWords);
	word.erase();
	return arrWords;
}

void PrintMap(map<string, int> &wordsMass)
{
	for (auto it = wordsMass.begin(); it != wordsMass.end(); it++)
	{
		cout << (*it).first << " : " << (*it).second << endl;
	}
}