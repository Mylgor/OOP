#pragma once

class CCar
{
public:
	CCar();

	bool TurnOnEngine();
	bool TurnOffEngine();
	void Info();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

private:
	bool InSpeedRange(int gear, int speed);

	enum GearBox {
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
	struct SpeedRange {
		int minSpeed;
		int maxSpeed;
	};
	 map<GearBox, SpeedRange> range;

	bool conditionEngine;		//состояние двигателя
	Condit conditionMotion;		//направление движения
	int targetSpeed;			//текущая скорость движения
	GearBox transmission;		//текущая выбранная передача
};