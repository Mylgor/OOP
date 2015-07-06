#pragma once
#include <string>

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

class CCBody
{
public:
	CCBody(double density = 0) : m_density(density){};

	void GetData(ostream & data) const;
	double GetDensity() const // ���������
	{
		return m_density;
	}
	virtual double GetVolume() const = 0;// �����
	virtual double GetWeight() const // �����
	{
		return GetVolume() * m_density;
	}

protected:
	double m_density;
	string m_name;
};

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

class CCSphere : public CCBody	//�����
{
public:
	CCSphere(double const& radius, double const &density) 
		: m_radius(radius), CCBody(density)
	{
		m_name = "C����";
	};

	virtual double GetVolume() const
	{
		return (pow(m_radius, 3) * 4 * GetPi()) / 3;
	}

	double GetRadius() const
	{
		return m_radius;
	}
private:
	double m_radius;
};

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

class CCParallelepiped : public CCBody	//��������������
{
public :
	CCParallelepiped(double const& width, double const& height, double const& depth, double const &density)
		: m_width(width), m_height(height), m_depth(depth), CCBody(density)
	{
		m_name = "��������������";
	};
	virtual double GetVolume() const
	{
		return m_width * m_height * m_depth;
	}
	double GetWidth() const
	{
		return m_width;
	}
	double GetHeight() const
	{
		return m_height;
	}
	double GetDepth() const
	{
		return m_depth;
	}
private:
	double m_width, m_height, m_depth;
};

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

class CCone : public CCBody	//�����
{
public :
	CCone(double const& radius, double const& height, double const &density)
		: m_radius(radius), m_height(height), CCBody(density)
	{
		m_name = "�����";
	};
	virtual double GetVolume() const
	{
		return (GetPi() * pow(m_radius, 2) * m_height) / 3;
	}
	double GetHeight() const
	{
		return m_height;
	}
	double GetRadius() const
	{
		return m_radius;
	}

private:
	double m_radius, m_height;
};

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

class CCylinder : public CCBody	//�������
{
public :
	CCylinder(double const& radius, double const& height, double const &density)
		: m_radius(radius), m_height(height), CCBody(density)
	{
		m_name = "�������";
	};
	virtual double GetVolume() const
	{
		return GetPi() * pow(m_radius, 2) * m_height;
	}
	double GetHeight() const
	{
		return m_height;
	}
	double GetRadius() const
	{
		return m_radius;
	}

private:
	double m_radius, m_height;
};

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

/*class CCompound : public CCBody //c�������� ����
{
	CCompound()
	void AddBody(CCBody const& newBody)
	{
		m_weight = newBody.GetWeight();
	}

private:
	vector<CCBody> m_compoudBody;
};
*/
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////