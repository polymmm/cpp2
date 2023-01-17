#include "Matrix.h"

int matrix(std::string namein, std::string nameout)
{
	using namespace std;
	ofstream fout;
	ifstream fin;
	int n;
	fin.open(namein);
	fin >> n;
	fin.close();
	double** A = new double*[n];
	if (A == NULL)
		return -1;
	for (int i = 0; i < n; i++)
	{
		A[i] = new double[n];
		if (A[i] == NULL)
			return -1;
	}
	fout.open(nameout);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = (abs(j - 3) - 1.3) * (6.5 - j) * pow(2, j - 1) * (2 *
				abs(3.3 - i) - 1.5);
			fout << A[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();
	for (int i = 0; i < n; i++)
		delete[] A[i];
	return 0;
}
