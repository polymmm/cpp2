#include "Vector.h"

int vector(std::string namein, std::string nameout)
{
	using namespace std;
	ofstream fout;
	ifstream fin;
	int n = 0;
	double temp;
	string s;
	fin.open(namein);
	getline(fin, s);
	for (int i = 0; i < s.length(); i++)
		if (s[i] == ' ')
			n++;
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
	double* X = new double[n];
	if (X == NULL)
		return -1;
	for (int i = 0; i < n; i++)
		X[i] = 0.0;
	fin.open(namein);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			fin >> A[i][j];
	fin.close();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			X[i] = X[i] + A[i][j];
		}
		X[i] = X[i] / n;
	}
	for (int i = 0; i < n; i++)
	{
		for (int k = i + 1; k < n; k++)
		{
			if (X[i] < X[k])
			{
				temp = X[i];
				X[i] = X[k];
				X[k] = temp;
			}
		}
	}
	fout.open(nameout);
	for (int i = 0; i < n; i++)
		fout << X[i] << " ";
	fout.close();
	for (int i = 0; i < n; i++)
		delete[] A[i];
	delete[] X;
	return 0;
}
