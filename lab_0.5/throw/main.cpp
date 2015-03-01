#include <iostream>
#include <math.h>
#define PI 3.1415926535

using namespace std;

float StrToFloat(char *str, bool &err)
{
	float param = atof(str);
	err = ((param == 0 && *str != '0') || (*str == '\0'));
	return param;
}

int AdditionalChecks(char *str, bool &error, float &arg)
{
	if ((strcmp(str, "exit") == 0) || (strcmp(str, "EXIT") == 0))
		return 1;
	if (error)
		cout << "incorrect value, try again" << endl;
	if (arg < 0 || arg == 0)
	{
		cout << "value must be great than zero" << endl;
		error = true;
	}
	return 0;
}

int EnterTheData(float &speed, float &acceleration)
{
	bool error = true;
	char str[8];
	
	while (error)
	{
		cout << "Enter v0 (or type 'exit') > ";
		cin >> str;
		speed = StrToFloat(str, error);
		if (AdditionalChecks(str, error, speed)) return 1;
	}

	error = true;
	while (error)
	{
		cout << "Enter a0 (or type 'exit') > ";
		cin >> str;
		acceleration = StrToFloat(str, error);
		if (AdditionalChecks(str, error, acceleration)) return 1;
	}
}

float CalculateDistance(const float &v0, const float &a0)
{
	return (pow(v0, 2) * sin((2 * a0 * PI) / 180)) / 9.8;
}

int main(int argc, char *argv[])
{
	float v0, a0;
	while (!EnterTheData(v0, a0))
	{
		cout << "Distance is: " << CalculateDistance(v0, a0) << endl;
	}
	return 0;
}