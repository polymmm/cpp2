#include "Matrix.h"
int Matrix::quantity(double z, int x, double** M)
{
	double* Aver = new double[x];
	int q = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			Aver[i] += M[i][j];
		}
		Aver[i] /= x;
	}
	for (int i = 0; i < x; i++)
	{
		if (Aver[i] < z)
		{
			q++;
		}
	}
	delete[] Aver;
	return q;
}