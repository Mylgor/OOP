// TestsForRectangle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "..\Rectangle\CRectangle.h";

BOOST_AUTO_TEST_CASE(InitRectangle)
{
	CCRectangle rect(1, 2, 3, 4);
	int left, top, right, bottom;
	rect.GetCoordinate(left, top, right, bottom);
	BOOST_CHECK_EQUAL(left, 1);
	BOOST_CHECK_EQUAL(top, 2);
	BOOST_CHECK_EQUAL(right, 3);
	BOOST_CHECK_EQUAL(bottom, 4);
}