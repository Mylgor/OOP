#pragma once
class CTriangle
{
public:
	CTriangle(double const &side1 = 0, double const &side2 = 0, double const &side3 = 0);

	double ReturnSide1() const;
	double ReturnSide2() const;
	double ReturnSide3() const;
	
	double GetPerimetr() const;
	double GetArea() const;

private:
	double m_side1, m_side2, m_side3;
};