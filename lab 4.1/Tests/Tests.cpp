// Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "..\lab 4.1\CBody.h"

BOOST_AUTO_TEST_CASE(Sphere)
{
	CCSphere tempBody(2,3);
	BOOST_CHECK(tempBody.GetRadius() == 2);
	BOOST_CHECK(tempBody.GetDensity() == 3);
	BOOST_CHECK((int)tempBody.GetVolume() == 33);
	BOOST_CHECK((int)tempBody.GetWeight() == 100);
}

BOOST_AUTO_TEST_CASE(Parallelepiped)
{
	CCParallelepiped tempBody(2, 2, 2, 10);
	BOOST_CHECK(tempBody.GetHeight() == 2);
	BOOST_CHECK(tempBody.GetWidth() == 2);
	BOOST_CHECK(tempBody.GetDepth() == 2);
	BOOST_CHECK(tempBody.GetDensity() == 10);
	BOOST_CHECK(tempBody.GetVolume() == 8);
	BOOST_CHECK(tempBody.GetWeight() == 80);
}

BOOST_AUTO_TEST_CASE(Cone)
{
	CCone tempBody(5, 10, 6);
	BOOST_CHECK(tempBody.GetRadius() == 5);
	BOOST_CHECK(tempBody.GetHeight() == 10);
	BOOST_CHECK(tempBody.GetDensity() == 6);
	BOOST_CHECK((int)tempBody.GetVolume() == 261);
	BOOST_CHECK((int)tempBody.GetWeight() == 1570);
}

BOOST_AUTO_TEST_CASE(Cylinder)
{
	CCylinder tempBody(2, 4, 6);
	BOOST_CHECK(tempBody.GetRadius() == 2);
	BOOST_CHECK(tempBody.GetHeight() == 4);
	BOOST_CHECK(tempBody.GetDensity() == 6);
	double a = tempBody.GetWeight();
	a = tempBody.GetVolume();
	BOOST_CHECK((int)tempBody.GetVolume() == 50);
	BOOST_CHECK((int)tempBody.GetWeight() == 301);
}