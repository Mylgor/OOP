#include "stdafx.h"
#include "Triangle.h"

using namespace std;

CTriangle::CTriangle(double const &side1, double const &side2, double const &side3)
	: m_side1(side1), m_side2(side2), m_side3(side3)
{
	if ((side1 <= 0) || (side2 <= 0) || (side3 <= 0))
	{
		throw invalid_argument("aguments must be > 0");
	}

	if ((side1 > (side2 + side3)) || (side2 > (side1 + side3)) || (side3 > (side2 + side1)))
	{
		throw domain_error("incorrect side ('side A' must be low that 'side B' + 'side C')");
	}
};

double CTriangle::ReturnSide1() const
{
	return m_side1;
}

double CTriangle::ReturnSide2() const
{
	return m_side2;
}

double CTriangle::ReturnSide3() const
{
	return m_side3;
}

double CTriangle::GetPerimetr() const
{
	return m_side1 + m_side2 + m_side3;
}

double CTriangle::GetArea() const
{
	double perimetr = GetPerimetr() / 2;
	return sqrt(perimetr * (perimetr - m_side1) * (perimetr - m_side2) * (perimetr - m_side3));
}