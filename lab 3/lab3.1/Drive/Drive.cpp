// Drive.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Car.h"

map<CCar::GearBox, CCar::SpeedRange> CCar::range;

int RetAnsw()
{
	cout << "1: Info" << endl;
	cout << "2: Engine On" << endl;
	cout << "3: Engine Off" << endl;
	cout << "4: Change gear" << endl;
	cout << "5: Change speed" << endl;
	cout << "6: Exit" << endl;
	int answer = 0;
	while (answer < 1 || answer > 6)
	{
		cout << "Answer: ";
		cin >> answer;
	}
	return answer;
}

void Info(CCar const &drive)
{
	cout << boolalpha;
	int condMotion = drive.GetStateOfMotion();
	switch (condMotion)
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
	cout << "Condition Engine: " << drive.GetCondEngine() << endl;
	cout << "Speed: " << drive.GetSpeed() << endl;
	cout << "Gear: " << drive.GetGrear() << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Welcome to the driving simulator" << endl;
	CCar driver;

	int doIt = 0, gear, speed;
	while (doIt != 6)
	{
		doIt = RetAnsw();
		switch (doIt)
		{
		case 1:
			Info(driver);
			break;

		case 2:
			if (driver.TurnOnEngine())
				cout << "the engine is running" << endl;
			else
				cout << "the engine can't be running" << endl;
			break;

		case 3:
			if (driver.TurnOffEngine())
				cout << "the engine is off" << endl;
			else
				cout << "the engine can't be switched off" << endl;
			break;

		case 4:
			cout << "Enter the gear: ";
			cin >> gear;
			if (driver.SetGear(gear))
				cout << "the gear is change" << endl;
			else
				cout << "the gear can't be change" << endl;
			break;

		case 5:
			cout << "Enter the speed: ";
			cin >> speed;
			if (driver.SetSpeed(speed))
				cout << "the speed is change" << endl;
			else
				cout << "the speed can't be change" << endl;
			break;
		}
		cout << endl;
	}

	return 0;
}

