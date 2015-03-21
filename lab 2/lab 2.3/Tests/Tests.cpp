#include "stdafx.h"
#include "..\Generate\GeneratePrimeNumbers.h"

bool CheckingSet(int arg1, std::set<int> const &arg2)
{
	std::set<int> arr = GeneratePrimeNumbersSet(arg1);
	return (arr == arg2);
}

BOOST_AUTO_TEST_CASE(Simple)
{
	BOOST_CHECK(CheckingSet(10, {2, 3, 5, 7}));
}

BOOST_AUTO_TEST_CASE(InBorder)
{
	BOOST_CHECK(CheckingSet(13, { 2, 3, 5, 7 , 11, 13}));
}

BOOST_AUTO_TEST_CASE(NegativeParam)
{
	BOOST_CHECK(CheckingSet(-1, {}));
}

BOOST_AUTO_TEST_CASE(EmptySet)
{
	std::set<int> emptySet = GeneratePrimeNumbersSet(0);
	BOOST_CHECK(emptySet.empty());
}