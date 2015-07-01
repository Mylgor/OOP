#include "stdafx.h"
#include "CBody.h"

void CCBody::GetData(ostream & data)
{
	data << "���������: " << GetDensity() << endl;
	data << "�����: " << GetVolume() << endl;
	data << "�����: " << GetWeight() << endl;
}

double CCBody::GetDensity() const
{
	return m_density;
}

double CCBody::GetVolume() const
{
	return m_volume;
}

double CCBody::GetWeight() const
{
	return m_weight;
}