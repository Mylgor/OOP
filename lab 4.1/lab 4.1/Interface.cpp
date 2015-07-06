#include "stdafx.h"
#include "CBody.h"



void CheckParam(double &param)
{
	cin >> param;
	while (param <= 0)
	{
		cout << "������������ ��������" << endl;
		cin >> param;
	}
}

double InputWidth(double &width)
{
	cout << "������� ������: ";
	CheckParam(width);
	return width;
}

double InputHeight(double &height)
{
	cout << "������� ������: ";
	CheckParam(height);
	return height;
}

double InputRadius(double &radius)
{
	cout << "������� ������: ";
	CheckParam(radius);
	return radius;
}

double InputDensity(double &density)
{
	cout << "������� ���������: ";
	CheckParam(density);
	return density;
}

double InputDepth(double &depth)
{
	cout << "������� �������: ";
	CheckParam(depth);
	return depth;
}

void InputParam(int &answer)
{
	cout << "�����: ";
	cin >> answer;
}

int InputData()
{
	cout << endl << "�������� ������:" << endl;
	cout << "1) C����" << endl;
	cout << "2) ������������" << endl;
	cout << "3) �����" << endl;
	cout << "4) �������" << endl;
	cout << "5) ��������� ����" << endl;
	cout << "6) ������� ������ ������" << endl;
	cout << "7) �����" << endl << endl;
	int answer;
	InputParam(answer);
	while (answer < 1 || answer > 7)
	{
		cout << "������������ ��������" << endl;
		InputParam(answer);
	}
	return answer;
}

void PrintLeaderFigures(vector<shared_ptr<CCBody>> &mainFigures)
{
	cout << endl << "���� � ���������� ����� � ����:" << endl;
	(*mainFigures[0]).GetData(cout);

	cout << endl << "���� � ���������� ������:" << endl;
	(*mainFigures[1]).GetData(cout);
}