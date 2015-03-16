#include "stdafx.h"
#include "..\MultMass\WorkWithArray.h"

using namespace std;

bool CheckingVector(vector<double> arg1, vector<double> arg2)
{
	vector<double> arr(arg1);
	MultEachElem(arr);
	return (arr == arg2);
}

BOOST_AUTO_TEST_CASE(OrdinaryNumbers)
{
	BOOST_CHECK(CheckingVector({ 1, 2, 3, 4 }, { 1, 2, 3, 4 }));
}

BOOST_AUTO_TEST_CASE(NegativeNumbers)
{
	BOOST_CHECK(CheckingVector({ -1, -2, -3, -4 }, { 4, 8, 12, 16 }));
}

BOOST_AUTO_TEST_CASE(EmptyVectorProducesEmptyVector)
{
	vector<double> emptyVector;
	MultEachElem(emptyVector);
	BOOST_CHECK(emptyVector.empty());
}

BOOST_AUTO_TEST_CASE(Zero)
{
	BOOST_CHECK(CheckingVector({ 0 }, { 0 }));
}



