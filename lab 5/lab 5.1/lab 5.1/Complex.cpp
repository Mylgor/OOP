#include "stdafx.h"
#include "Complex.h"

double CComplex::Re()const
{
	return m_real;
}

double CComplex::Im()const
{
	return m_image;
}

double CComplex::GetMagnitude()const
{
	return tan(m_image / m_real);
}

double CComplex::GetArgument()const
{
	return sqrt((m_image * m_image) + (m_real * m_real));
}

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

CComplex CComplex::operator +()
{
	return CComplex(m_real ,m_image);
}

CComplex CComplex::operator -()
{
	return CComplex(-m_real, -m_image);
}

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

CComplex const operator +(CComplex const &number1, CComplex const &number2)
{
	return CComplex(number1.Re() + number2.Re(), number1.Im() + number2.Im());
}

CComplex const operator -(CComplex const &number1, CComplex const &number2)
{
	return CComplex(number1.Re() - number2.Re(), number1.Im() - number2.Im());
}

CComplex const operator *(CComplex const &number1, CComplex const &number2)
{
	return CComplex(number1.Re() * number2.Re() - number1.Im() * number2.Im(), number1.Re() * number2.Im() + number1.Im() * number2.Re());
}

CComplex const operator /(CComplex const &number1, CComplex const &number2)
{
	double param1 = (number1.Re() * number2.Re() + number1.Im() * number2.Im()) / ((number2.Re() * number2.Re()) + (number2.Im() * number2.Im()));
	double param2 = (number2.Re() * number1.Im() - number2.Im() * number1.Re()) / ((number2.Re() * number2.Re()) + (number2.Im() * number2.Im()));
	return CComplex(param1, param2);
}

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
/*
CComplex const operator +(double const &number1, CComplex const &number2)
{
	return CComplex(number1) + number2;
}

CComplex const operator +(CComplex const &number1, double const &number2)
{
	return number1 + CComplex(number2);
}

CComplex const operator -(double const &number1, CComplex const &number2)
{
	return CComplex(number1) - number2;
}

CComplex const operator -(CComplex const &number1, double const &number2)
{
	return number1 - CComplex(number2);
}

CComplex const operator *(double const &number1, CComplex const &number2)
{
	return CComplex(number1) * number2;
}

CComplex const operator *(CComplex const &number1, double const &number2)
{
	return number1 * CComplex(number2);
}

CComplex const operator /(double const &number1, CComplex const &number2)
{
	return CComplex(number1) / number2;
}

CComplex const operator /(CComplex const &number1, double const &number2)
{
	return number1 / CComplex(number2);
}
*/
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

CComplex CComplex::operator +=(CComplex const& number)
{
	*this = *this + number;
	return *this;
}

CComplex CComplex::operator -=(CComplex const& number) 
{
	*this = *this - number;
	return *this;
}

CComplex CComplex::operator *=(CComplex const& number)
{
	*this = *this * number;
	return *this;
}

CComplex CComplex::operator /=(CComplex const& number)
{
	*this = *this / number;
	return *this;
}

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

bool operator ==(CComplex const& number1, CComplex const& number2)
{
	return (fabs(number1.Re() - number2.Re()) < DBL_MIN) && (fabs(number1.Im() - number2.Im()) < DBL_MIN);
}

bool operator !=(CComplex const& number1, CComplex const& number2)
{
	return (number1.Im() != number2.Im()) && (number1.Re() != number2.Re());
}