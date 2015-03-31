#pragma once
#include <string>
#include <map>
#include <vector>

using namespace std;

class CCar
{
public:
	CCar();

	enum Speeds {
		reverse = -1,
		neutral = 0,
		first = 1,
		second = 2,
		third = 3,
		four = 4,
		five = 5,
	};

	enum Condit {
		back = -1,
		stop = 0,
		forward = 1,
	};

	map<Speeds, vector<int>> range;

	bool TurnOnEngine();
	bool TurnOffEngine();
	void Info();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

private:
	bool conditionEngine;		//состояние двигателя
	Condit conditionMotion;		//направление движения
	int targetSpeed;			//текущая скорость движения
	Speeds transmission;		//текущая выбранная передача
};