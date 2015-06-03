#pragma once
#include <iostream>
#include <vector>

using namespace std;

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

