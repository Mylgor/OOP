// Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "..\Drive\Car.h"

map<CCar::GearBox, CCar::SpeedRange> CCar::range;

void FirstTransmission(CCar &car)
{
	car.TurnOnEngine();
	car.SetGear(1);
	car.SetSpeed(30);
}

BOOST_AUTO_TEST_CASE(TestTurnOffEngine)
{
	CCar car;
	FirstTransmission(car);
	BOOST_CHECK_EQUAL(car.TurnOffEngine(), false);
	BOOST_CHECK(car.SetGear(0));
	BOOST_CHECK_EQUAL(car.TurnOffEngine(), false);
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK_EQUAL(car.TurnOffEngine(), true);

	BOOST_CHECK_EQUAL(car.GetCondEngine(), false);
	BOOST_CHECK_EQUAL(car.GetGrear(), 0);
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	BOOST_CHECK_EQUAL(car.GetStateOfMotion(), 0);
}

BOOST_AUTO_TEST_CASE(ChangeValueWhenCarIsOff)
{
	CCar car;
	BOOST_CHECK_EQUAL(car.SetGear(4), false);
	BOOST_CHECK(car.SetSpeed(0), true);
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	BOOST_CHECK(car.SetGear(-1));
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK_EQUAL(car.SetSpeed(10), false);
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
}

BOOST_AUTO_TEST_CASE(RestartingTheEngine)
{
	CCar car;
	BOOST_CHECK_EQUAL(car.TurnOnEngine(), true);
	BOOST_CHECK_EQUAL(car.TurnOnEngine(), false);
	BOOST_CHECK_EQUAL(car.TurnOffEngine(), true);
	BOOST_CHECK_EQUAL(car.TurnOffEngine(), false);
	BOOST_CHECK_EQUAL(car.GetCondEngine(), false);
}

BOOST_AUTO_TEST_CASE(EngineIsOnIFTransmitionOnNeutral)
{
	CCar car;
	BOOST_CHECK_EQUAL(car.SetGear(-1), true);
	BOOST_CHECK_EQUAL(car.TurnOnEngine(), false);
	BOOST_CHECK_EQUAL(car.SetGear(0), true);
	BOOST_CHECK_EQUAL(car.TurnOnEngine(), true);
	BOOST_CHECK_EQUAL(car.GetCondEngine(), true);
}

BOOST_AUTO_TEST_CASE(TestSpeed)
{
	CCar car;
	FirstTransmission(car);
	BOOST_CHECK_EQUAL(car.SetSpeed(50), false);
	BOOST_CHECK(car.SetGear(2));
	BOOST_CHECK(car.SetSpeed(50));
	BOOST_CHECK_EQUAL(car.GetGrear(), 2);
	BOOST_CHECK_EQUAL(car.GetSpeed(), 50);
	BOOST_CHECK_EQUAL(car.SetSpeed(100), false);
	BOOST_CHECK(car.SetGear(0));
	BOOST_CHECK_EQUAL(car.SetSpeed(120), false);
	BOOST_CHECK_EQUAL(car.SetGear(-1), false);
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK(car.SetGear(-1));
	BOOST_CHECK_EQUAL(car.GetGrear(), -1);
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
}

BOOST_AUTO_TEST_CASE(BackDraft)
{
	CCar car;
	FirstTransmission(car);
	BOOST_CHECK_EQUAL(car.SetGear(-1), false);
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK(car.SetGear(-1));
	BOOST_CHECK_EQUAL(car.GetGrear(), -1);
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	BOOST_CHECK(car.SetSpeed(20));
	BOOST_CHECK(car.SetGear(0));
	BOOST_CHECK_EQUAL(car.SetGear(-1), false);
	BOOST_CHECK_EQUAL(car.SetGear(0), false);
	BOOST_CHECK_EQUAL(car.SetGear(1), false);
	BOOST_CHECK_EQUAL(car.GetGrear(), 0);
	BOOST_CHECK_EQUAL(car.GetSpeed(), 20);
}

BOOST_AUTO_TEST_CASE(WhenWeGoOnNEUTRAL)
{
	CCar car;
	FirstTransmission(car);
	BOOST_CHECK_EQUAL(car.SetGear(0), true);
	BOOST_CHECK_EQUAL(car.SetSpeed(20), true);
	BOOST_CHECK_EQUAL(car.SetSpeed(0), true);
	BOOST_CHECK_EQUAL(car.GetGrear(), 0);
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
}