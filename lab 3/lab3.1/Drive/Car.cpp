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

	m_isEngineOn = false;
	m_conditionMotion = StateOfMotion::stop;
	m_speed = 0;
	m_transmission = GearBox::neutral;
}

bool CCar::TurnOnEngine()
{
	if (!m_isEngineOn)
	{
		if (m_transmission == GearBox::neutral)
		{
			m_isEngineOn = true;
			m_conditionMotion = StateOfMotion::stop;
			m_speed = 0;
			m_transmission = GearBox::neutral;
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
	if (m_isEngineOn)
	{
		if ((m_speed == 0) && (m_conditionMotion == StateOfMotion::stop))
		{
			m_isEngineOn = false;
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
			if (InSpeedRange(gear, m_speed))
			{
				if (gear == -1 && (m_speed == 0) && ((m_transmission == GearBox::neutral) || (m_transmission == GearBox::first))) // переключние на заднюю
				{
					m_transmission = GearBox(gear);
					return true;
				}
				if ((m_transmission == GearBox::reverse) && ((gear == 1 && m_speed == 0) || (gear == 0) || (gear == -1))) // переключение с задней
				{
					m_transmission = GearBox(gear);
					return true;
				}
				if ((gear != -1) && (m_transmission != GearBox::reverse) && (m_conditionMotion != StateOfMotion::back))
				{
					m_transmission = GearBox(gear);
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
	if ((m_isEngineOn) || (speed <= m_speed))
	{
		if ((InSpeedRange(m_transmission, speed)) && ((!m_transmission == GearBox::neutral) || (speed <= m_speed)))
		{
			if (speed != 0)
			{
				if (m_transmission >= 0)
					m_conditionMotion = StateOfMotion::forward;
				else
					m_conditionMotion = StateOfMotion::back;
			}
			else
			{
				m_conditionMotion = StateOfMotion::stop;
			}
			m_speed = speed;
			return true;
		}
	}
	else
	{
		cout << "Your engine is off" << endl;
	}
	return false;
}

bool CCar::GetCondEngine() const
{
	return m_isEngineOn;
}

int CCar::GetGrear() const
{
	return m_transmission;
}

int CCar::GetSpeed() const
{
	return m_speed;
}

int CCar::GetStateOfMotion() const
{
	return m_conditionMotion;
}