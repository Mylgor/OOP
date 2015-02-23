#include <iostream>

using namespace std;

int SearchRoots(int A, int B, int C, FILE *f)
{
	int flag = 0;
	if (A == 0)
	{
		cout << "Error (A = 0)";
		return 1;
	}
	if (B == 0)
	{
		if (A < 0 && C > 0)
		{
			fprintf(f, "%.4f, %.4f", sqrt(C / (A * -1.0)) , sqrt(C / (A * -1)) * (-1.0));
		}
		if (A > 0 && C < 0)
		{
			fprintf(f, "%.4f, %.4f", sqrt((C * -1.0) / A), sqrt((C * -1.0) / A) * (-1.0));
		}
		else
		{
			fprintf(f, "%.4f, %.4f", sqrt(C / A), sqrt(C / A) * (-1.0));
		}
		return 1;
	}
	if (C == 0)
	{
		fprintf(f, "%.4f, %.4f", (B * -1.0) / A, 0);
		return 1;
	}
	if (B < 0)
	{
		flag = 1;
		B = B * (-1);
	}
	float D = pow(B, 2) - (4.0 * A * C);
	if (flag)
		B = B * (-1);
	if (D < 0)
	{
		cout << "There is no real root" << endl;
		return 1;
	}
	if (D == 0)
	{
		fprintf(f, "%.4f", B * (-1.0) / (2.0 * A));
		return 1;
	}
	if (D > 0)
	{
		fprintf(f, "%.4f,", (B * (-1.0) + sqrt(D)) / (2.0 * A));
		fprintf(f, " %.4f", (B * (-1.0) - sqrt(D)) / (2.0 * A));
		return 1;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		printf("Agruments error");
		return 1;
	}

	FILE *f = fopen("output.txt", "wb");
	if (f == NULL)
	{
		printf("Cannot search output file");
		return 1;
	}

	int A, B, C;
	A = atoi(argv[1]); B = atoi(argv[2]); C = atoi(argv[3]);
	SearchRoots(A, B, C, f);

	fclose(f);
	f = NULL;
	return 0;
}