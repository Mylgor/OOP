// Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "..\lab 6.1\Triangle.h"
#include <math.h>

BOOST_AUTO_TEST_CASE(WorkClassCTriangle)
{
	CTriangle triangle1(3, 4, 5);
	BOOST_CHECK(triangle1.ReturnSide1() == 3);
	BOOST_CHECK(triangle1.ReturnSide2() == 4);
	BOOST_CHECK(triangle1.ReturnSide3() == 5);
	BOOST_CHECK(triangle1.GetArea() == 6);
	BOOST_CHECK(triangle1.GetPerimetr() == 12);

	CTriangle triangle2(1.98, 4.11, 3.67);
	BOOST_CHECK(triangle2.ReturnSide1() == 1.98);
	BOOST_CHECK(triangle2.ReturnSide2() == 4.11);
	BOOST_CHECK(triangle2.ReturnSide3() == 3.67);
	BOOST_CHECK(round(triangle2.GetArea() * 10) / 10 == 3.6);
	BOOST_CHECK(triangle2.GetPerimetr() == 9.76);

	BOOST_CHECK_NO_THROW(CTriangle trian(3, 4, 5));
	BOOST_CHECK_THROW(CTriangle trian(-1, 2, 3), std::invalid_argument);
	BOOST_CHECK_THROW(CTriangle trian(1, -2, 3), std::invalid_argument);
	BOOST_CHECK_THROW(CTriangle trian(1, 2, -3), std::invalid_argument);
	BOOST_CHECK_THROW(CTriangle trian(1, 2, 10), std::domain_error);
	BOOST_CHECK_THROW(CTriangle trian(1, 10, 2), std::domain_error);
	BOOST_CHECK_THROW(CTriangle trian(10, 2, 1), std::domain_error);
}