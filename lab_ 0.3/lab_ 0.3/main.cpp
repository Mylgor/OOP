#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

void Fib(const int &limit)
{
	int previous, current, next , i;
	previous = next = i = 0;
	current = 1;
	while (next <= limit)
	{
		cout << next;
		i++;
		next = current + previous;
		previous = current;
		current = next;
		if (next < 0)
		{
			cout << endl << "error" << endl;
			break;
		}
		if (next <= limit)
			cout << ", ";
		else
			cout << endl;
		if (i % 5 == 0)
		{
			cout << endl;
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "input error" << endl;
		return 0;
	}

	bool error;
	int numb = StringToInt(argv[1], error);
	if (error)
	{
		cout << "Argument error" << endl;
		return 1;
	}

	if (numb <= 0)
	{
		cout << "Number must be greater than 0" << endl;
		return 1;
	}

	Fib(numb);
	_getch();
	return 0;
}