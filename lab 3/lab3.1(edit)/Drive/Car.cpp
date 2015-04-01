#include "stdafx.h"
#include "Car.h"

bool CCar::InSpeedRange(int gear, int speed)
{
	if ((speed >= range[GearBox(gear)].minSpeed) && (speed <= range[GearBox(gear)].maxSpeed))
		return true;
	return false;
}

CCar::CCar()
{
	range[GearBox::reverse] = {0, 20};
	range[GearBox::neutral] = { 0, 150 };
	range[GearBox::first] = { 0, 30 };
	range[GearBox::second] = { 20, 50 };
	range[GearBox::third] = { 30, 60 };
	range[GearBox::four] = { 40, 90 };
	range[GearBox::five] = { 50, 150 };

	conditionEngine = false;
	conditionMotion = Condit::stop;
	targetSpeed = 0;
	transmission = GearBox::neutral;
}

bool CCar::TurnOnEngine()
{
	if (!conditionEngine)
	{
		if (transmission == GearBox::neutral)
		{
			conditionEngine = true;
			conditionMotion = Condit::stop;
			targetSpeed = 0;
			transmission = GearBox::neutral;
			return true;
		}
		else
		{
			cout << "Transmission must be on NEUTRAL" << endl;
		}
	}
	else
	{
		cout << "Engine is already working" << endl;
	}
	return false;
}

bool CCar::TurnOffEngine()
{
	if (conditionEngine)
	{
		if ((targetSpeed == 0) && (conditionMotion == Condit::stop))
		{
			conditionEngine = false;
			return true;
		}
		else
		{
			cout << "Speed = 0 and car must be stoped" << endl;
		}
	}
	else
	{
		cout << "Engine is already turn off" << endl;
	}
	return false;
}

bool CCar::SetGear(int gear)
{
		if ((gear >= -1) && (gear <= 5))
		{
			if (InSpeedRange(gear, targetSpeed))
			{
				if (gear == -1 && ((transmission == GearBox::neutral) || (transmission == GearBox::first && targetSpeed == 0))) // переключние на заднюю
				{
					transmission = GearBox(gear);
					return true;
				}
				if ((transmission == GearBox::reverse) && ((gear == 1 && targetSpeed == 0) || (gear == 0) || (gear == -1))) // переключение с задней
				{
					transmission = GearBox(gear);
					return true;
				}
				if ((gear != -1) && (transmission != GearBox::reverse) && (conditionMotion != Condit::back))
				{
					transmission = GearBox(gear);
					return true;
				}
			}
			else
			{
				cout << "Gear is unsuitable for your speed" << endl;
			}
		}
		else
		{
			cout << "Incorect gear ( great >= -1 and great <= 5 )" << endl;
		}
	return false;
}

bool CCar::SetSpeed(int speed)
{
	if ((conditionEngine) || (speed <= targetSpeed))
	{
		if ((InSpeedRange(transmission, speed)) && ((!transmission == GearBox::neutral) || (speed <= targetSpeed)))
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
	else
	{
		cout << "Your engine is off" << endl;
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