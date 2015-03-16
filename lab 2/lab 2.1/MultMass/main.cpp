#include "WorkWithArray.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool ChechElements(double i, double j)
{
	return (i < j);
}

int main()
{
	vector<double> mass;
	ReadArray(mass);
	MultEachElem(mass);
	sort(mass.begin(), mass.end(), ChechElements);
	PrintArray(mass);
	
	return 0;
}