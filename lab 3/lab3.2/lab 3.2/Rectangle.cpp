#include "stdafx.h"
#include "Rectangle.h"

CCRectangle::CCRectangle(int left, int top, int width, int height)
{
	width < 0 ? m_width = 0 : m_width = width;
	height < 0 ? m_height = 0 : m_height = height;

	left < 0 ? m_coordinate.left = 0 : m_coordinate.left = left;
	top < 0 ? m_coordinate.top = 0 : m_coordinate.top = top;

	Update();
}

void CCRectangle::GetCoordinate(int &left, int &top, int &right, int &bottom) const
{
	m_coordinate.left < 0 ? left = 0 : left = m_coordinate.left;
	m_coordinate.top < 0 ? top = 0 : top = m_coordinate.top;
	m_coordinate.right < 0 ? right = 0 : right = m_coordinate.right;
	m_coordinate.bottom < 0 ? bottom = 0 : bottom = m_coordinate.bottom;
}

int CCRectangle::GetArea() const
{
	return m_area;
}

int CCRectangle::GetPerimeter() const
{
	return m_perimeter;
}

int CCRectangle::GetWidth() const
{
	return m_width;
}

int CCRectangle::GetHeight() const
{
	return m_height;
}

void CCRectangle::Move(int &dx, int &dy)
{
	m_coordinate.left += dx;
	m_coordinate.top += dy;
	Update();
}

void CCRectangle::Scale(int &sx, int &sy)
{
	if ((sx > 0) && (sy > 0))
	{
		m_width *= sx;
		m_height *= sy;
		Update();
	}
}

bool CCRectangle::Intersect(CCRectangle const &other)
{
	int leftOther, rightOther, topOther, bottomOther;
	other.GetCoordinate(leftOther, topOther, rightOther, bottomOther);

	if (!((m_coordinate.left > rightOther) || (m_coordinate.right < leftOther) || (m_coordinate.top > bottomOther) || (m_coordinate.bottom < topOther)))
	{
		m_coordinate.left > leftOther ? m_coordinate.left : m_coordinate.left = leftOther;
		m_coordinate.top > topOther ? m_coordinate.top : m_coordinate.top = topOther;

		m_coordinate.right < rightOther ? m_width = m_coordinate.right : m_width = rightOther;
		m_coordinate.bottom < bottomOther ? m_height = m_coordinate.bottom : m_height = bottomOther;
		m_width -= m_coordinate.left;
		m_height -= m_coordinate.top;
		Update();
		return true;
	}

	m_width = 0;
	m_height = 0;
	Update();
	return false;

}

void CCRectangle::Update()
{
	m_coordinate.right = m_coordinate.left + m_width;
	m_coordinate.bottom = m_coordinate.top + m_height;
	m_area = m_width * m_height;
	m_perimeter = 2 * (m_width + m_height);
}

CCRectangle::~CCRectangle()
{
}
