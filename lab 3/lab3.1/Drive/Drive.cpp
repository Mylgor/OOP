// Drive.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Car.h"
#include <iostream>

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
			driver.Info();
			cout << endl;
			break;

		case 2:
			if (driver.TurnOnEngine())
				cout << "the engine is running" << endl;
			else
				cout << "the engine is already running" << endl;
			cout << endl;
			break;

		case 3:
			if (driver.TurnOffEngine())
				cout << "the engine is off" << endl;
			else
				cout << "the engine can not be switched off ( car must be stoped, engine is running and transmition = neutral )" << endl;
			cout << endl;
			break;

		case 4:
			cout << "Enter the gear: ";
			cin >> gear;
			if (driver.SetGear(gear))
				cout << "the gear is change" << endl;
			else
				cout << "the gear can't be change" << endl;
			cout << endl;
			break;

		case 5:
			cout << "Enter the speed: ";
			cin >> speed;
			if (driver.SetSpeed(speed))
				cout << "the speed is change" << endl;
			else
				cout << "the speed can't be change" << endl;
			cout << endl;
			break;
		}
	}

	return 0;
}

