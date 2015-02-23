#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

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
		cout << "input error";
		return 0;
	}

	int numb = atoi(argv[1]);
	if (numb <= 0)
	{
		cout << "Number must be greater than 0" << endl;
		return 0;
	}

	Fib(numb);
	_getch();
	return 0;
}