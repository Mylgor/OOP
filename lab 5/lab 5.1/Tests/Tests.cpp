// Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "..\lab 5.1\Complex.h"

BOOST_AUTO_TEST_CASE(Plus)
{
	CComplex number(5, -6);
	BOOST_CHECK(number.Re() == 5);
	BOOST_CHECK(number.Im() == -6);

	number = number + CComplex(2, 2);
	BOOST_CHECK(number.Re() == 7);
	BOOST_CHECK(number.Im() == -4);

	number += CComplex(-3, -2);
	BOOST_CHECK(number.Re() == 4);
	BOOST_CHECK(number.Im() == -6);

	number = +number;
	BOOST_CHECK(number.Re() == 4);
	BOOST_CHECK(number.Im() == -6);
}

BOOST_AUTO_TEST_CASE(Minus)
{
	CComplex number(5, -6);
	BOOST_CHECK(number.Re() == 5);
	BOOST_CHECK(number.Im() == -6);

	number = number - CComplex(2, 2);
	BOOST_CHECK(number.Re() == 3);
	BOOST_CHECK(number.Im() == -8);

	number -= CComplex(-3, -2);
	BOOST_CHECK(number.Re() == 6);
	BOOST_CHECK(number.Im() == -6);

	number = -number;
	BOOST_CHECK(number.Re() == -6);
	BOOST_CHECK(number.Im() == 6);
}

BOOST_AUTO_TEST_CASE(Multiplication)
{
	CComplex number(5, -6);
	BOOST_CHECK(number.Re() == 5);
	BOOST_CHECK(number.Im() == -6);

	number = number * CComplex(2, 2);
	BOOST_CHECK(number.Re() == 22);
	BOOST_CHECK(number.Im() == -2);

	number *= CComplex(-3, -2);
	BOOST_CHECK(number.Re() == -70);
	BOOST_CHECK(number.Im() == -38);
}

BOOST_AUTO_TEST_CASE(Division)
{
	CComplex number(5, -6);
	BOOST_CHECK(number.Re() == 5);
	BOOST_CHECK(number.Im() == -6);

	number = number / CComplex(2, 2);
	BOOST_CHECK(number.Re() == -0.25);
	BOOST_CHECK(number.Im() == -2.75);

	number /= CComplex(-0.25, -0.25);
	BOOST_CHECK(number.Re() == 6);
	BOOST_CHECK(number.Im() == 5);
}

BOOST_AUTO_TEST_CASE(EqualAndNotEqual)
{
	CComplex number1(5, -6);
	CComplex number2(5, -6);
	BOOST_CHECK_EQUAL(number1 == number2, true);
	BOOST_CHECK_EQUAL(number1 != number2, false);
	number2 = -number2;
	BOOST_CHECK(number2.Re() == -5);
	BOOST_CHECK(number2.Im() == 6);
	BOOST_CHECK_EQUAL(number1 != number2, true);
	BOOST_CHECK_EQUAL(number1 == number2, false);
}