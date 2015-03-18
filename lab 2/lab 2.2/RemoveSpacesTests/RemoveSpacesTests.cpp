// RemoveSpacesTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "..\RemoveSpaces\RemoveExtraSpaces.h"

bool CheckingString(std::string const &arg1, std::string const &arg2)
{
	std::string str(arg1);
	RemoveExtraSpaces(str);
	return (str == arg1);
}

BOOST_AUTO_TEST_CASE(OneSpace)
{
	BOOST_CHECK(CheckingString(" ", " "));
}

BOOST_AUTO_TEST_CASE(NegativeNumbers)
{
	BOOST_CHECK(CheckingString(" A   B ", "A B"));
}

BOOST_AUTO_TEST_CASE(EmptyStr)
{
	std::string emptyStr;
	RemoveExtraSpaces(emptyStr);
	BOOST_CHECK(emptyStr.empty());
}

BOOST_AUTO_TEST_CASE(SpacesInBegin)
{
	BOOST_CHECK(CheckingString("            A", "A"));
}

BOOST_AUTO_TEST_CASE(SpacesInEnd)
{
	BOOST_CHECK(CheckingString("B       ", "B"));
}
