#include "stdafx.h"
#include "Car.h"
#include <iostream>

CCar::CCar()
{
	range[Speeds::reverse] = {0, 20};
	range[Speeds::neutral] = { 0, 150 };
	range[Speeds::first] = { 0, 30 };
	range[Speeds::second] = { 20, 50 };
	range[Speeds::third] = { 30, 60 };
	range[Speeds::four] = { 40, 90 };
	range[Speeds::five] = { 50, 150 };

	conditionEngine = false;
	conditionMotion = Condit::stop;
	targetSpeed = 0;
	transmission = Speeds::neutral;
}

bool CCar::TurnOnEngine()
{
	if (!conditionEngine)
	{
		if (transmission == Speeds::neutral)
		{
			conditionEngine = true;
			conditionMotion = Condit::stop;
			targetSpeed = 0;
			transmission = Speeds::neutral;
			return true;
		}
		else
			cout << "Transmission must be on NEUTRAL" << endl;
	}
	return false;
}

bool CCar::TurnOffEngine()
{
	if (conditionEngine && targetSpeed == 0 && conditionMotion == Condit::stop)
	{
		conditionEngine = false;
		return true;
	}
	return false;
}

bool CCar::SetGear(int gear)
{
		if (gear >= -1 && gear <= 5)
		{
			if ((targetSpeed >= range[Speeds(gear)][0] && targetSpeed <= range[Speeds(gear)][1]) || !conditionEngine)
			{
				if (gear == -1 && (transmission == Speeds::neutral || (transmission == Speeds::first && targetSpeed == 0) || !conditionEngine)) // переключние на заднюю
				{
					transmission = Speeds(gear);
					return true;
				}
				if (transmission == Speeds::reverse && ((gear == 1 && targetSpeed == 0) || gear == 0 || gear == -1)) // переключение с задней
				{
					transmission = Speeds(gear);
					return true;
				}
				if (gear != -1 && transmission != Speeds::reverse && conditionMotion != Condit::back)
				{
					transmission = Speeds(gear);
					return true;
				}
			}
		}
		else
			cout << "Incorect gear ( great >= -1 and great <= 5 )" << endl;
	return false;
}

bool CCar::SetSpeed(int speed)
{
	if (conditionEngine || speed == 0)
	{
		if (speed >= range[transmission][0] && speed <= range[transmission][1] && (!transmission == Speeds::neutral || speed == 0))
		{
			if (speed != 0)
			{
				if (transmission > 0)
					conditionMotion = Condit::forward;
				else
					conditionMotion = Condit::back;
			}
			else
			{
				conditionMotion = Condit::stop;
			}
			targetSpeed = speed;
			return true;
		}
	}
	return false;
}

void CCar::Info()
{
	cout << boolalpha;
	switch (conditionMotion)
	{
	case -1:
		cout << "Condition Motion: " << "goes back" << endl;
		break;
	case 0:
		cout << "Condition Motion: " << "is worth" << endl;
		break;
	case 1:
		cout << "Condition Motion: " << "goes forward" << endl;
		break;
	}
	cout << "Condition Engine: " << conditionEngine << endl;
	cout << "Speed: " << targetSpeed << endl;
	cout << "Gear: " << transmission << endl;
}