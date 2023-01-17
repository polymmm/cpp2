#include "Matrix.h"
int Matrix::triangle(int x, double** M, std::string name)
{
	std::ofstream fout;
	double mu;
	double** Z = new double* [x];
	if (Z == NULL)
		return -1;
	for (int i = 0; i < x; i++)
	{
		Z[i] = new double[x];
		if (Z[i] == NULL)
			return -1;
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			Z[i][j] = M[i][j];
		}
	}
	for (int k = 0; k < x; k++)
	{
		for (int i = k + 1; i < x; i++)
		{
			mu = Z[i][k] / Z[k][k];
			for (int j = 0; j < x; j++)
				Z[i][j] -= Z[k][j] * mu;
		}
	}
	fout.open(name);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			fout << Z[i][j] << " ";
		}
		fout << std::endl;
	}
	fout.close();
	for (int i = 0; i < x; i++)
		delete[] Z[i];
	return 0;
}