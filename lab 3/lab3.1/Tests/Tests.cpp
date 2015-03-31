// Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "..\Drive\Car.h"

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
	car.SetGear(0);
	BOOST_CHECK_EQUAL(car.TurnOffEngine(), false);
	car.SetSpeed(0);
	BOOST_CHECK_EQUAL(car.TurnOffEngine(), true);
}

BOOST_AUTO_TEST_CASE(ChangeValueWhenCarIsOff)
{
	CCar car;
	BOOST_CHECK_EQUAL(car.SetGear(4), true);
	BOOST_CHECK_EQUAL(car.SetGear(-1), true);
	BOOST_CHECK_EQUAL(car.SetSpeed(0), true);
	BOOST_CHECK_EQUAL(car.SetSpeed(10), false);
}

BOOST_AUTO_TEST_CASE(RestartingTheEngine)
{
	CCar car;
	BOOST_CHECK_EQUAL(car.TurnOnEngine(), true);
	BOOST_CHECK_EQUAL(car.TurnOnEngine(), false);
	BOOST_CHECK_EQUAL(car.TurnOffEngine(), true);
	BOOST_CHECK_EQUAL(car.TurnOffEngine(), false);
}

BOOST_AUTO_TEST_CASE(EngineIsOnIFTransmitionOnNeutral)
{
	CCar car;
	BOOST_CHECK_EQUAL(car.SetGear(-1), true);
	BOOST_CHECK_EQUAL(car.TurnOnEngine(), false);
	BOOST_CHECK_EQUAL(car.SetGear(0), true);
	BOOST_CHECK_EQUAL(car.TurnOnEngine(), true);
}

BOOST_AUTO_TEST_CASE(TestSpeed)
{
	CCar car;
	FirstTransmission(car);
	BOOST_CHECK_EQUAL(car.SetSpeed(50), false);
	BOOST_CHECK_EQUAL(car.SetGear(2), true);
	BOOST_CHECK_EQUAL(car.SetSpeed(50), true);
	BOOST_CHECK_EQUAL(car.SetSpeed(100), false);
	BOOST_CHECK_EQUAL(car.SetGear(0), true);
	BOOST_CHECK_EQUAL(car.SetSpeed(120), false);
	BOOST_CHECK_EQUAL(car.SetGear(-1), false);
	BOOST_CHECK_EQUAL(car.SetSpeed(0), true);
	BOOST_CHECK_EQUAL(car.SetGear(-1), true);
}

BOOST_AUTO_TEST_CASE(BackDraft)
{
	CCar car;
	FirstTransmission(car);
	BOOST_CHECK_EQUAL(car.SetGear(-1), false);
	BOOST_CHECK_EQUAL(car.SetSpeed(0), true);
	BOOST_CHECK_EQUAL(car.SetGear(-1), true);
	BOOST_CHECK_EQUAL(car.SetSpeed(20), true);
	BOOST_CHECK_EQUAL(car.SetGear(0), true);
	BOOST_CHECK_EQUAL(car.SetGear(-1), true);
	car.SetGear(0);
	BOOST_CHECK_EQUAL(car.SetGear(1), false);
}