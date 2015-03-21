// WordCount.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "WokWithMap.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	string str;
	cout << "enter offer: ";
	getline(cin, str);
	
	map<string, int> wordsMass = FrequencyOfCccurrenceOfWords(str);
	PrintMap(wordsMass);

	return 0;
}

