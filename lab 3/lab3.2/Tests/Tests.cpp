// Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "..\lab 3.2\Rectangle.h"
#include "..\lab 3.2\Canvas.h"

BOOST_AUTO_TEST_CASE(InitRectangle)
{
	CCRectangle rect(1, 2, 3, 4);
	int left, top, right, bottom;
	rect.GetCoordinate(left, top, right, bottom);
	BOOST_CHECK_EQUAL(left, 1);
	BOOST_CHECK_EQUAL(top, 2);
	BOOST_CHECK_EQUAL(bottom, 6);
	BOOST_CHECK_EQUAL(right, 4);
}

BOOST_AUTO_TEST_CASE(MoveRectangle)
{
	CCRectangle rect(1, 2, 3, 4);
	int left, top, right, bottom;
	rect.GetCoordinate(left, top, right, bottom);
	int dx, dy;
	dx = dy = 2;
	rect.Move(dx, dy);

	BOOST_CHECK_EQUAL(left, 1);
	BOOST_CHECK_EQUAL(top, 2);
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
	BOOST_CHECK_EQUAL(right, 4);
	BOOST_CHECK_EQUAL(bottom, 6);

	sx = sy = -2;
	rect.Scale(sx, sy);
	BOOST_CHECK_EQUAL(left, 1);
	BOOST_CHECK_EQUAL(top, 2);
	BOOST_CHECK_EQUAL(rect.GetWidth(), 6);
	BOOST_CHECK_EQUAL(rect.GetHeight(), 8);
	BOOST_CHECK_EQUAL(right, 4);
	BOOST_CHECK_EQUAL(bottom, 6);
}

BOOST_AUTO_TEST_CASE(IntersectRectangles)
{
	CCRectangle rect1(11, 5, 14, 4);
	CCRectangle rect2(5, 2, 9, 5);
	BOOST_CHECK(rect1.Intersect(rect2));

	int left, top, right, bottom;
	rect1.GetCoordinate(left, top, right, bottom);

	BOOST_CHECK_EQUAL(left, 11);
	BOOST_CHECK_EQUAL(top, 5);
	BOOST_CHECK_EQUAL(right, 14);
	BOOST_CHECK_EQUAL(bottom, 7);
	BOOST_CHECK_EQUAL(rect1.GetWidth(), 3);
	BOOST_CHECK_EQUAL(rect1.GetHeight(), 2);
}

BOOST_AUTO_TEST_CASE(InitCanvas)
{
	int height = 2, width = 10;
	CCanvas canv1(10, 2);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			BOOST_CHECK_EQUAL(canv1.GetPixel(j, i), ' ');
		}
	}
	BOOST_CHECK(canv1.GetHeight() == 2);
	BOOST_CHECK(canv1.GetWidth() == 10);
	
	height = -2; width = -5;
	CCanvas canv2(width, height);
	BOOST_CHECK(canv2.GetHeight() == 0);
	BOOST_CHECK(canv2.GetWidth() == 0);
}

BOOST_AUTO_TEST_CASE(FillRect)
{
	CCanvas canv(5, 5);
	canv.SetPixel(1, 2, '+');
	BOOST_CHECK_EQUAL(canv.GetPixel(1, 2), '+');
	canv.SetPixel(4, 1, '+');
	BOOST_CHECK_EQUAL(canv.GetPixel(4, 1), '+');
	canv.SetPixel(0, 0, '+');
	BOOST_CHECK_EQUAL(canv.GetPixel(0, 0), '+');
	BOOST_REQUIRE_NO_THROW(canv.SetPixel(10, 10, '+'));
}
