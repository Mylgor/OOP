#include "stdafx.h"
#include "CBody.h"

void CCBody::GetData(ostream & data) const
{
	data << m_name << endl;
	data << "���������: " << GetDensity() << endl;
	data << "�����: " << GetVolume() << endl;
	data << "�����: " << GetWeight() << endl;
}