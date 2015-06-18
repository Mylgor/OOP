#pragma once
#include "stdafx.h"

template < typename T, typename Less>
bool FindMax(std::vector<T> const& arr, T& maxValue, Less less(T const &param1, T const &param2))
{
	int lenMass = arr.size();
	if (lenMass == 0)
	{
		return false;
	}

	maxValue = arr[0];
	for (int i = 0; i < lenMass; i++)
	{
		if (less(arr[i], maxValue))
			maxValue = arr[i];
	}
	return true;
}