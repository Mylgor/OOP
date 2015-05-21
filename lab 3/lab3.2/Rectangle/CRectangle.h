#pragma once
#include <iostream>
#include <vector>

using namespace std;

class CCRectangle
{
public:
	CCRectangle(int left, int top, int width, int height);
	~CCRectangle();

	int GetArea() const;
	int GetPerimeter() const;
	void GetCoordinate(int &left, int &top, int &right, int &bottom) const;
	int GetWidth() const;
	int GetHeight() const;

	void Move(int &dx, int &dy);
	void Scale(int &sx, int &sy);
	bool Intersect(CCRectangle const& other);

	struct CoordinateRectng
	{
		int left;	//���������� X ������ ����
		int top;	//���������� Y �������� ����
		int right;	//���������� X ������� ����
		int bottom;	//���������� Y ������ �������
	};

	CoordinateRectng m_coordinate;

private:
	void Update();

	int m_width;	//������
	int m_height;	//������

	int m_area;		//�������
	int m_perimeter;//��������
};

class CCanvas
{
public:
	CCanvas(unsigned width, unsigned height);

	unsigned GetWidth()const;
	unsigned GetHeight()const;
	
	void Clear(char code = ' ');
	void SetPixel(int x, int y, char code);
	char GetPixel(int x, int y)const;
	void Write(ostream & ostream)const;
private:
	int m_width;
	int m_height;
	vector<char> m_canvas;
};
