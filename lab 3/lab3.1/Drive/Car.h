#pragma once

class CCar
{
public:
	CCar();

	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

	bool GetCondEngine() const;
	int GetSpeed() const;
	int GetStateOfMotion() const;
	int GetGrear() const;

private:
	bool InSpeedRange(int gear, int speed);

	enum GearBox {
		reverse = -1,
		neutral = 0,
		first = 1,
		second = 2,
		third = 3,
		four = 4,
		five = 5
	};

	enum StateOfMotion {
		back = -1,
		stop = 0,
		forward = 1
	};
	struct SpeedRange {
		int minSpeed;
		int maxSpeed;
	};
	static map<GearBox, SpeedRange> range;

	bool m_isEngineOn;		//состояние двигателя
	StateOfMotion m_conditionMotion;		//направление движения
	int m_speed;			//текущая скорость движения
	GearBox m_transmission;		//текущая выбранная передача
};