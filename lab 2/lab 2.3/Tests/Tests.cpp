#include "stdafx.h"
#include "..\WordCount\WokWithMap.h"

bool CheckingMap(string const &arg1, std::map<string, int> const &arg2)
{
	std::map<string, int> arr = FrequencyOfCccurrenceOfWords(arg1);
	return (arr == arg2);
}

BOOST_AUTO_TEST_CASE(CheckWork)
{
	BOOST_CHECK(CheckingMap("ice ice ice fire fire", {{ "ice", 3 }, { "fire", 2 }}));
}

BOOST_AUTO_TEST_CASE(EmptyStr)
{
	BOOST_CHECK(CheckingMap("", {}));
}

BOOST_AUTO_TEST_CASE(LeftSymbols)
{
	BOOST_CHECK(CheckingMap("   !!! ..   \n \n \t \t ", {}));
}