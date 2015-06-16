// Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "..\WordCount\WokWithMap.h"

BOOST_AUTO_TEST_CASE(Test)
{
	map<string, int> wordsMass;
	BOOST_CHECK(wordsMass.size() == 0);
	wordsMass = CalculFrequencyOfCccurrenceOfWords("Abc ABC abc");
	BOOST_CHECK(wordsMass.size() == 1);
	BOOST_CHECK((*wordsMass.begin()).first == "Abc");
	BOOST_CHECK((*wordsMass.begin()).second == 3);

	wordsMass = CalculFrequencyOfCccurrenceOfWords("dima lena sasha");
	for (auto it = wordsMass.begin(); it != wordsMass.end(); it++)
	{
		BOOST_CHECK_EQUAL((*it).first == "dima" || (*it).first == "lena" || (*it).first == "sasha", true);
		BOOST_CHECK((*it).second == 1);
	}
}
