// Rectangle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int StrToInt(string &temp, bool &err)
{
	if (temp == "")
		err = true;
	else
	{
		int numb = stoi(temp);
		err = (temp != "0") && (numb == 0);
		return numb;
	}
	return 0;
}

vector<int> SearchComponents(string &str, int len)
{
	vector<int> param;
	string numb;
	int nextNumb;
	bool error;

	while (len < (int)str.size())
	{
		if (isdigit(str[len]) || (str[len] == '-'))
		{
			numb.push_back(str[len]);
		}
		else
		{
			nextNumb = StrToInt(numb, error);
			if (!error)
				param.push_back(nextNumb);
			numb.erase();
		}
		len++;
	}
	nextNumb = StrToInt(numb, error);
	if (!error)
		param.push_back(nextNumb);
	return param;
}

int ParseTheString(string &str, CCRectangle &rect)
{
	vector<int> components;
	size_t it1 = str.find("Rectangle");
	if (it1 != string::npos)
	{
		components = SearchComponents(str, 9);
		if ((int)components.size() == 4)
		{
			CCRectangle newRect(components[0], components[1], components[2], components[3]);
			rect = newRect;
			return 0;
		}
	}
	
	size_t it2 = str.find("Move");
	if (it2 != string::npos)
	{
		components = SearchComponents(str, 4);
		if ((int)components.size() == 2)
		{
			rect.Move(components[0], components[1]);
			return 0;
		}
	}
	
	size_t it3 = str.find("Scale");
	if (it3 != string::npos)
	{
		components = SearchComponents(str, 5);
		if ((int)components.size() == 2)
		{
			rect.Scale(components[0], components[1]);
			return 0;
		}
	}

	cout << "incorrect string : '" << str << " '" << endl;
	return 1;
}

bool ReadFromFile(string const &input, CCRectangle &currentRect)
{		
	ifstream inputFile(input);
	if (inputFile.fail())
	{
		cout << "cannot open " << input << endl;
		return false;
	}

	string str;
	while (!inputFile.eof())
	{
		getline(inputFile, str);
		ParseTheString(str, currentRect);
	}

	inputFile.close();
	return true;
}

void PrintDataRectangle(CCRectangle const &rect)
{
	int left, right, top, bottom;
	rect.GetCoordinate(left, top, right, bottom);

	cout << "\tLeft top: (" << left << "; " << top << ")" << endl;
	cout << "\tSize: " << rect.GetWidth() << " * " << rect.GetHeight() << endl;
	cout << "\tRight bottom: (" << right << "; " << bottom << ")" << endl;
	cout << "\tArea: " << rect.GetArea() << endl;
	cout << "\tPerimeter: " << rect.GetPerimeter() << endl;
}

void SetWidthHeightForCanv(CCRectangle const &rect1, CCRectangle const &rect2, int &width, int &height)
{
	int left1, right1, top1, bottom1;
	int left2, right2, top2, bottom2;
	rect1.GetCoordinate(left1, top1, right1, bottom1);
	rect2.GetCoordinate(left2, top2, right2, bottom2);

	width = right1 < right2 ? right2 : right1;
	height = bottom1 < bottom2 ? bottom2 : bottom1;
}

void FillRect(CCanvas &canv, CCRectangle const &rect, char code)
{
	int left, right, top, bottom;
	rect.GetCoordinate(left, top, right, bottom);
	for (int dy = top; dy != bottom; dy++)
	{
		for (int dx = left; dx != right; dx++)
		{
			canv.SetPixel(dx, dy, code);
		}
	}
}

int main(int argc, char* argv[])
{
	/*if (argc != 3)
	{
		cout << "Must be 3 arguments" << endl;
		return 1;
	}*/
	string inputFile1 = "input1.txt";
	string inputFile2 = "input2.txt";

	CCRectangle rect1(0, 0, 0, 0);
	CCRectangle rect2(0, 0, 0, 0);

	if (!ReadFromFile(inputFile1, rect1))
	{
		return 1;
	}

	if (!ReadFromFile(inputFile2, rect2))
	{
		return 1;
	}
	
	cout << "Rectangle 1:" << endl;
	PrintDataRectangle(rect1);
	cout << "Rectangle 2:" << endl;
	PrintDataRectangle(rect2);

	int width, height;
	SetWidthHeightForCanv(rect1, rect2, width, height);
	CCanvas canv(width, height);
	FillRect(canv, rect1, '+');
	FillRect(canv, rect2, '-');

	if (rect1.Intersect(rect2))
	{
		cout << "Intersection rectangle:" << endl;
		PrintDataRectangle(rect1);
		FillRect(canv, rect1, '#');
	}
	
	canv.Write(cout);
	return 0;
}

