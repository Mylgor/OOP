#include "stdafx.h"
#include "CBody.h"



void CheckParam(double &param)
{
	cin >> param;
	while (param <= 0)
	{
		cout << "неправильная величина" << endl;
		cin >> param;
	}
}

double InputWidth(double &width)
{
	cout << "Введите шиниру: ";
	CheckParam(width);
	return width;
}

double InputHeight(double &height)
{
	cout << "Введите высоту: ";
	CheckParam(height);
	return height;
}

double InputRadius(double &radius)
{
	cout << "Введите радиус: ";
	CheckParam(radius);
	return radius;
}

double InputDensity(double &density)
{
	cout << "Введите плотность: ";
	CheckParam(density);
	return density;
}

double InputDepth(double &depth)
{
	cout << "Введите глубину: ";
	CheckParam(depth);
	return depth;
}

void InputParam(int &answer)
{
	cout << "Ответ: ";
	cin >> answer;
}

int InputData()
{
	cout << endl << "Выберите фигуру:" << endl;
	cout << "1) Cфера" << endl;
	cout << "2) Параллепипед" << endl;
	cout << "3) Конус" << endl;
	cout << "4) Цилиндр" << endl;
	cout << "5) Составное тело" << endl;
	cout << "6) Вывести особые фигуры" << endl;
	cout << "7) Выход" << endl << endl;
	int answer;
	InputParam(answer);
	while (answer < 1 || answer > 7)
	{
		cout << "Неправильное действие" << endl;
		InputParam(answer);
	}
	return answer;
}

void PrintLeaderFigures(vector<shared_ptr<CCBody>> &mainFigures)
{
	cout << endl << "Тело с наименьшей весом в воде:" << endl;
	(*mainFigures[0]).GetData(cout);

	cout << endl << "Тело с наибольшей массой:" << endl;
	(*mainFigures[1]).GetData(cout);
}