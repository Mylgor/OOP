#include "stdafx.h"
#include "CBody.h"

void CCBody::GetData(ostream & data) const
{
	data << m_name << endl;
	data << "Плотность: " << GetDensity() << endl;
	data << "Объем: " << GetVolume() << endl;
	data << "Масса: " << GetWeight() << endl;
}