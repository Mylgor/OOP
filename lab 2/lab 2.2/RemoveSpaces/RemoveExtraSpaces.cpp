#include "stdafx.h"
#include "RemoveExtraSpaces.h"

using namespace std;

void RemoveSpacesInBeginAndEnd(string &arg)
{
	if (arg[0] == ' ')
		arg.erase(0, 1);
	if (arg.length() > 0)
		if (arg[arg.length() - 1] == ' ')
			arg.erase(arg.length() - 1, 1);
}

string RemoveExtraSpaces(string const &arg)
{
	string str = arg;
	int i = 0;
	int strLen = str.length() - 1;
	while (i < strLen - 1)
	{
		if ((str[i] == ' ') && (str[i + 1] == ' '))
		{
			str.erase(i, 1);
			strLen = str.length() - 1;
		}
		else
		{
			i++;
		}
	}
	
	RemoveSpacesInBeginAndEnd(str);
	return str;
}