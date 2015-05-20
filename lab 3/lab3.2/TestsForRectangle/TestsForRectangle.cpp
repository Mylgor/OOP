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

BOOST_AUTO_TEST_CASE(MoveRectangle)
{
	CCRectangle rect(1, 2, 3, 4);
	int left, top, right, bottom;
	rect.GetCoordinate(left, top, right, bottom);
	int dx, dy;
	dx = dy = 2;
	rect.Move(dx, dy);

	BOOST_CHECK_EQUAL(left, 3);
	BOOST_CHECK_EQUAL(top, 4);
	BOOST_CHECK_EQUAL(rect.GetWidth(), 3);
	BOOST_CHECK_EQUAL(rect.GetHeight(), 4);

	dx = dy = -2;
	rect.Move(dx, dy);
	BOOST_CHECK_EQUAL(left, 1);
	BOOST_CHECK_EQUAL(top, 2);
	BOOST_CHECK_EQUAL(rect.GetWidth(), 3);
	BOOST_CHECK_EQUAL(rect.GetHeight(), 4);
}

BOOST_AUTO_TEST_CASE(ScaleRectangle)
{
	CCRectangle rect(1, 2, 3, 4);
	int left, top, right, bottom;
	rect.GetCoordinate(left, top, right, bottom);
	int sx, sy;
	sx = sy = 2;
	rect.Scale(sx, sy);

	BOOST_CHECK_EQUAL(left, 1);
	BOOST_CHECK_EQUAL(top, 2);
	BOOST_CHECK_EQUAL(rect.GetWidth(), 6);
	BOOST_CHECK_EQUAL(rect.GetHeight(), 8);
	BOOST_CHECK_EQUAL(right, 7);
	BOOST_CHECK_EQUAL(bottom, 10);

	sx = sy = -2;
	rect.Scale(sx, sy);
	BOOST_CHECK_EQUAL(left, 1);
	BOOST_CHECK_EQUAL(top, 2);
	BOOST_CHECK_EQUAL(rect.GetWidth(), 3);
	BOOST_CHECK_EQUAL(rect.GetHeight(), 4);
	BOOST_CHECK_EQUAL(right, 4);
	BOOST_CHECK_EQUAL(bottom, 6);
}