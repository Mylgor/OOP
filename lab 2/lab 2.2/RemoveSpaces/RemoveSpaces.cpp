// RemoveSpaces.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "RemoveExtraSpaces.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string line;
	cout << "Enter offer: ";
	getline(cin, line);
	cout << "Resoult: " << RemoveExtraSpaces(line) << endl;
	
	return 0;
}

