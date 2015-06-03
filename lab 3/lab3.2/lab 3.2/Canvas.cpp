#include "stdafx.h"
#include "Canvas.h"


CCanvas::CCanvas(unsigned width, unsigned height)
{
	m_height = height;
	m_width = width;
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			m_canvas.push_back(' ');
		}
	}
	if (m_canvas.size() == 0)
	{
		m_height = 0;
		m_width = 0;
	}
}

unsigned CCanvas::GetWidth()const
{
	return m_width;
}

unsigned CCanvas::GetHeight()const
{
	return m_height;
}

void CCanvas::Clear(char code)
{
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			if ((code > 0) && (code < ' '))
			{
				m_canvas[i * m_width + j] = code;
			}
		}
	}
}

void CCanvas::SetPixel(int x, int y, char code)
{
	if ((y * m_width + x) < m_canvas.size())
	{
		m_canvas[y * m_width + x] = code;
	}
}

char CCanvas::GetPixel(int x, int y)const
{
	if ((x < 0) || (x > m_width) || (y < 0) || (y > m_height))
	{
		return ' ';
	}
	return m_canvas[y * m_width + x];
}

void CCanvas::Write(std::ostream & ostream)const
{
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			ostream << m_canvas[i * m_width + j];
		}
		ostream << std::endl;
	}
}
