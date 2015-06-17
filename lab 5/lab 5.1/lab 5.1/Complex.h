#pragma once
class CComplex
{
public:
	// инициализация комплексного числа значениями действительной и мнимой частей
	CComplex(double real = 0, double image = 0) : m_real(real), m_image(image){};
	double Re()const;
	double Im()const;
	double GetMagnitude()const;
	double GetArgument()const;

	CComplex operator +();
	CComplex operator -();

	friend CComplex const operator +(CComplex const &number1, CComplex const &number2);
	friend CComplex const operator -(CComplex const &number1, CComplex const &number2);
	friend CComplex const operator *(CComplex const &number1, CComplex const &number2);
	friend CComplex const operator /(CComplex const &number1, CComplex const &number2);
	friend bool operator ==(CComplex const& number1, CComplex const& number2);
	friend bool operator !=(CComplex const& number1, CComplex const& number2);

	CComplex operator +=(CComplex const& number);
	CComplex operator -=(CComplex const& number);
	CComplex operator *=(CComplex const& number);
	CComplex operator /=(CComplex const& number);

private:
	double m_real, m_image;
};