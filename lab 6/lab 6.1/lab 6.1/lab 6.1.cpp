// lab 6.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Triangle.h"

bool InputData(double &side1, double &side2, double &side3)
{
	cout << "input side A: ";
	cin >> side1;
	cout << "input side B: ";
	cin >> side2;
	cout << "input side C: ";
	cin >> side3;
	if (side1 == -1 || side2 == -1 || side3 == -1)
	{
		return false;
	}
	return true;
}

void PrintInfo(CTriangle const &triangle)
{
	cout << "side A: " << triangle.ReturnSide1() << endl;
	cout << "side B: " << triangle.ReturnSide2() << endl;
	cout << "side C: " << triangle.ReturnSide3() << endl;
	cout << "Perimetr: " << triangle.GetPerimetr() << endl;
	cout << "Area: " << triangle.GetArea() << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	double side1, side2, side3;
	while (InputData(side1, side2, side3))
	{
		try
		{
			CTriangle triangle(side1, side2, side3);
			PrintInfo(triangle);
		}
		catch (invalid_argument const &ex1)
		{
			cout << "Error: " << ex1.what() << endl;
		}
		catch (domain_error const &ex2)
		{
			cout << "Error: " << ex2.what() << endl;
		}
	}
	return 0;
}

