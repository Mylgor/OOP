#include <iostream>
#include <conio.h>
#define maxN 995

int SumDigits(int i)
{
	int sum = 0;
	// цикл продолжается до тех пор, пока число не станет равным 0
	while (i != 0)
	{
		sum += i % 10;
		i /= 10;
	}
	return sum;
}

int main(int argc, char* argv[])
{
	for (int k = 1; k <= maxN; k++)
	{
		if ((k % SumDigits(k)) == 0)
		{
			if (k == 1) std::cout << k;
			else std::cout << ", " << k;
		}
	}

	_getch();
	return 1;
}