// RemoveSpaces.cpp: определяет точку входа для консольного приложения.
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

