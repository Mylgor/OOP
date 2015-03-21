#include "stdafx.h"
#include "GeneratePrimeNumbers.h"

bool isSimple(int &par)
{
	for (int i = 2; i <= sqrt(par); i++)
		if (par % i == 0)
			return false;
	return true;
}

set<int> GeneratePrimeNumbersSet(int upperBound)
{
	set<int> arr;
	for (int i = 2; i <= upperBound; i++)
	{
		if (isSimple(i))
			arr.insert(i);
	}
	return arr;
}