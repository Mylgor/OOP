// lab 4.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CBody.h"
#include "Interface.h"
#include <vld.h>

double GetPowerArchimedes(double const &v)
{
	return 1000 * 9.8 * v;
}

vector<shared_ptr<CCBody>> SearchMainFigures(vector<shared_ptr<CCBody>> const &figures, size_t const& lenMass)
{
	vector<shared_ptr<CCBody>> mainFigures;
	if (lenMass != 0)
	{
		size_t maxValueMassInd = 0;
		size_t maxValueWeightInWaterInd = 0;
		double weight;
		for (size_t i = 0; i < lenMass; i++)
		{
			weight = (*figures[i]).GetWeight() - GetPowerArchimedes((*figures[i]).GetVolume());
			if (weight < (*figures[maxValueWeightInWaterInd]).GetWeight() - GetPowerArchimedes((*figures[maxValueWeightInWaterInd]).GetVolume()))
			{
				maxValueWeightInWaterInd = i;
			}
			if ((*figures[i]).GetWeight() >(*figures[maxValueMassInd]).GetWeight())
			{
				maxValueMassInd = i;
			}
		}
		mainFigures.push_back(figures[maxValueWeightInWaterInd]);
		mainFigures.push_back(figures[maxValueMassInd]);
	}
	return mainFigures;
}

void AddNewFigures(vector<shared_ptr<CCBody>> &figures)
{
	int step = 0;
	while ((step = InputData()) != 7)
	{
		if (step == 1)
		{
			double radius, density;
			figures.push_back(shared_ptr<CCSphere>(new CCSphere(InputRadius(radius), InputDensity(density))));
		}
		else if (step == 2)
		{
			double width, height, depth, density;
			figures.push_back(shared_ptr<CCParallelepiped>(new CCParallelepiped(InputWidth(width), InputHeight(height), InputDepth(depth), InputDensity(density))));
		}
		else if (step == 3)
		{
			double height, radius, density;
			figures.push_back(shared_ptr<CCone>(new CCone(InputRadius(radius), InputHeight(height), InputDensity(density))));
		}
		else if (step == 4)
		{
			double height, radius, density;
			figures.push_back(shared_ptr<CCylinder>(new CCylinder(InputRadius(radius), InputHeight(height), InputDensity(density))));
		}
		else if (step == 5)
		{
			//составное тело
		}
		else if (step == 6)
		{
			size_t lenMass = figures.size();
			if (lenMass != 0)
			{
				vector<shared_ptr<CCBody>> mainFigures = SearchMainFigures(figures, lenMass);
				PrintLeaderFigures(mainFigures);
			}
			else
			{
				cout << "Пустой массив" << endl;
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	vector<shared_ptr<CCBody>> figures;
	AddNewFigures(figures);
	return 0;
}

