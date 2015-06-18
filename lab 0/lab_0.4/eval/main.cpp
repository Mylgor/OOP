#include <iostream>
#include <windows.h>

using namespace std;

float StrToFloat(char *str, bool &err)
{
	float param = atof(str);
	err = ((param == 0 && *str != '0') || (*str == '\0'));
	return param;
}

int IdentificationMark(char *mark, char &symbol)
{
	if ((*mark == '/') || (*mark == '*') || (*mark == '-') || (*mark == '+'))
	{
		symbol = *mark;
		return 1;
	}
	else
		return 0;
}

void Calculation(float &answer, float &numb, const char &symbol)
{
	switch (symbol)
	{
	case '/':
		if (numb == 0)
		{
			cout << "division by zero" << endl;
			exit(1);
		}
		answer /= numb;
		break;
	case '*':
		answer *= numb;
		break;
	case '+':
		answer += numb;
		break;
	case '-':
		answer -= numb;
		break;
	default:
		cout << "error" << endl;
		exit(1);
	}
}

void PrintAnswer(const float &answer, int &i)
{
	if ((i-1) < 3)
	{
		cout << "error" << endl;
	}
	else
	{
		printf("Answer: %.4f", answer);
	}
}

int main(int argc, char* argv[])
{
	bool error;
	float numb, answer;
	char symbol;
	int i;
	for (i = 1; i < argc; i++)
	{
		numb = StrToFloat(argv[i], error);
		if (error)
		{
			if (!IdentificationMark(argv[i], symbol) || i % 2 == 1)
			{
				cout << "error" << endl;
				exit(1);
			}
		}
		else
		{
			if (i == 1)
				answer = numb;
			else
				Calculation(answer, numb, symbol);
		}
	}

	PrintAnswer(answer, i);
	return 0;
}