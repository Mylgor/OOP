#include <iostream>
#include <fstream>

#define Y 3
#define X 3
using namespace std;

void CheckValue(bool &err)
{
	if (err)
	{
		cout << "argument error" << endl;
		exit(1);
	}
}

float StrToFloat(char *str, bool &err)
{
	float param = atof(str);
	err = ((param == 0 && *str != '0') || (*str == '\0'));
	return param;
}

void ReadingMatrix(float matrix[Y][X], ifstream &file)
{
	float numb;
	char nm[10];
	int j = 0, i = 0;
	bool error;

	while (!(file.eof()))
	{
		file >> nm;
		numb = StrToFloat(nm, error);
		CheckValue(error);
		if (j < X)
		{
			matrix[i][j++] = numb;
		}
		else
		{
			j = 0;
			matrix[++i][j++] = numb;
		}
	}
	if ((j != X) || (i != Y - 1))
	{
		cout << "incomplete matrix" << endl;
		exit(1);
	}
}

void SearchMod(float matrix[Y][X], float mod[Y-1][X-1], int arg1, int &arg2)
{
	int countY = 0, countX = 0;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (i != arg1 && j != arg2)
			{
				if (countX < 2)
					mod[countY][countX++] = matrix[i][j];
				else
				{
					countX = 0;
					countY++;
					mod[countY][countX++] = matrix[i][j];
				}
			}
		}
	}
}

float CalculMod(float matrix[Y-1][X-1])
{
	return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
}

float SearchDeterminant(float matrix[Y][X])
{
	float deter = 0;
	float mod[Y - 1][X - 1];
	bool flag = true;

	for (int k = 0; k < X; k++)
	{
		SearchMod(matrix, mod, 0, k);
		if (flag)
			deter += matrix[0][k] * CalculMod(mod);
		else
			deter -= matrix[0][k] * CalculMod(mod);
		flag = !(flag);
	}
	return deter;
}

void MatrixOfCofactors(float matrix[Y][X])
{
	matrix[0][1] = matrix[0][1] * -1.0;
	matrix[1][0] = matrix[1][0] * -1.0;
	matrix[1][2] = matrix[1][2] * -1.0;
	matrix[2][1] = matrix[2][1] * -1.0;
}

void SearchMinor(float matrix[Y][X], float minor[Y][X])
{
	float mod[Y-1][X-1];
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			SearchMod(matrix, mod, i, j);
			minor[i][j] = CalculMod(mod);
		}
	}
	MatrixOfCofactors(minor);
}

void MatrixTransposition(float matrix[Y][X])
{
	float numb;
	for (int i = 0; i < Y; i++)
	{
		for (int j = i; j < X; j++)
		{
			numb = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = numb;
		}
	}
}

void CalculatingTheInverseMatrix(float matrix[Y][X], float minor[Y][X], float &deter)
{
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			matrix[i][j] = minor[i][j] / deter;
		}
	}
}

void PrintfInverseMatrix(float matrix[Y][X])
{
	printf("inverse matrix:\n");
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			printf("%.3f ", matrix[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		cout << "arguments error" << endl;
		return 1;
	}
	ifstream file(argv[1]);
	if (file.fail())
	{
		cout << "cannot open file" << endl;
		return 1;
	}
	
	float matrix[Y][X];
	float minor[Y][X];

	ReadingMatrix(matrix, file); //считывание матрицы
	
	float determinant = SearchDeterminant(matrix);//поиск определителя
	if (determinant == 0)
	{
		cout << "inverse matrix does not exist (determinant = 0)" << endl;
		return 1;
	}

	SearchMinor(matrix, minor);//поиск матрицы миноров
	MatrixTransposition(minor);//транспонирование матрицы
	CalculatingTheInverseMatrix(matrix, minor, determinant);//поиск обратной  матрицы

	PrintfInverseMatrix(matrix);
	return 0;
}