// lab 7.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "FindMax.h"

using namespace std;

struct StudentData
{
	string name;
	double height, weight;
};

bool FindMaxHeight(StudentData const &param1, StudentData const &param2)
{
	return param1.height > param2.height;
}

bool FindMaxWeight(StudentData const &param1, StudentData const &param2)
{
	return param1.weight > param2.weight;
}

void PrintDataStudent(StudentData const& stud)
{
	cout << "Name: " << stud.name << endl;
	cout << "Height: " << stud.height << endl;
	cout << "Weight: " << stud.weight << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<StudentData> students = {
		{"Dima Vasuykov", 170, 60 },
		{"Lesha Kluzhev", 175, 64},
		{"Tahir Nafikov", 172, 70}
	};

	StudentData maxValue;
	
	if (FindMax(students, maxValue, FindMaxHeight))
		PrintDataStudent(maxValue);

	cout << endl;

	if (FindMax(students, maxValue, FindMaxWeight))
		PrintDataStudent(maxValue);
	return 0;
}

