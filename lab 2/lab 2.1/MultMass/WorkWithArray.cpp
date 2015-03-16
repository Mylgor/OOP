#include "WorkWithArray.h"
#include <functional>
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;

void ReadArray(vector<double> &arr1)
{
	cout << "Enter elements of the array: ";
	vector<double> arr2(istream_iterator<double>(cin), (istream_iterator<double>()));
	arr1.reserve(arr2.size() + arr1.size());
	arr1.insert(arr1.end(), arr2.begin(), arr2.end());
}

void MultEachElem(vector<double> &arr)
{
	if (!arr.empty())
	{
		double minElem = *min_element(arr.begin(), arr.end());
		transform(arr.begin(), arr.end(), arr.begin(), bind2nd(multiplies<double>(), minElem));
	}
}

void PrintArray(std::vector<double> &arr)
{
	if (!arr.empty())
	{
		cout << "Sort and processed array: ";
		copy(arr.begin(), arr.end() - 1, ostream_iterator<double>(cout, ", "));
		cout << arr[arr.size() - 1] << endl;
	}
	else
		cout << "empty array" << endl;
}