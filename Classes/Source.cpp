
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <conio.h>
#include <string>
#include <random>
#include <ctime>
#include "Matrix.h"
using namespace std;
void restart();
double random(double a, double b);
int main()
{
	ofstream fout;
	ifstream fin;
	Matrix matrix;
	int h, n;
	string scale, ar, tr;
	double temp;
	cout << "Select the name of the file with the matrix dimensions: ";
	cin >> scale;
	fin.open(scale);
	fin >> h;
	fin.close();
	cout << "A matrix with dimensions " << h << " by " << h << endl;
	double** A = new double* [h];
	if (A == NULL)
		return -1;
	for (int i = 0; i < h; i++)
	{
		A[i] = new double[h];
		if (A[i] == NULL)
			return -1;
	}
	double** B = new double* [h];
	if (B == NULL)
		return -1;
	for (int i = 0; i < h; i++)
	{
		B[i] = new double[h];
		if (B[i] == NULL)
			return -1;
	}
	cout << "Enter the name of the file for writing the matrix elements: ";
	cin >> ar;
	cout << "Select the input mode of the matrix elements:" << endl << "1. Interactive input" << endl << "2. Set the ranges for random generation" <<
		endl;
	cin >> n;
	if (n == 1)
	{
		cout << "Interactive input." << endl;
		fout.open(ar);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < h; j++)
			{
				cout << "A[" << i << "][" << j << "]= ";
				cin >> temp;
				fout << temp << " ";
			}
			fout << endl;
		}
		fout.close();
		fin.open(ar);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < h; j++)
			{
				fin >> A[i][j];
			}
		}
		fin.close();
	}
	else
	{
		cout << "Random generation" << endl;
		double min, max;
		cout << "Enter ranges:" << endl << "Minimum equals: ";
		cin >> min;
		cout << "Maximum equals: ";
		cin >> max;
		fout.open(ar);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < h; j++)
			{
				temp = random(min, max);
				fout << temp << " ";
				cout << "A[" << i << "][" << j << "]= " << temp << endl;
			}
			fout << endl;
		}
		fout.close();
		fin.open(ar);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < h; j++)
			{
				fin >> A[i][j];
			}
		}
		fin.close();
	}
	cout << "The matrix is obtained:" << endl;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < h; j++)
		{
			cout << fixed << setprecision(2) << A[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "Select the matrix processing mode:" << endl << "1. Reducing to a triangular form" << endl << "2. Search for the number of rows, the arithmetic mean of the elements of which is less than the given value" << endl;
		cin >> n;
	if (n == 1)
	{
		cout << "Enter a file name for recording the triangular matrix: ";
		cin >> tr;
		matrix.triangle(h, A, tr);
		cout << "Triangular matrix:" << endl;
		fin.open(tr);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < h; j++)
			{
				fin >> B[i][j];
				cout << fixed << setprecision(2) << B[i][j] << "\t";
			}
			cout << endl;
		}
		fin.close();
	}
	else
	{
		cout << "Set the value: ";
		cin >> temp;
		cout << "The number of rows, the arithmetic mean of the elements of which is less than " << temp << " equals: " << matrix.quantity(temp, h, A) << endl;
	}
	for (int i = 0; i < h; i++)
		delete[] A[i], B[i];
	restart();
	return 0;
}
void restart()
{
	int n;
	cout << "Do you want to continue?" << endl << "1. Yes" << endl << "2. No" <<
		endl;
	cin >> n;
	if (n == 1)
		main();
	else exit(0);
}
double random(double a, double b)
{
	double i, f = 0;
	int fra, frb;
	int rda = (int)a, rdb = (int)b;
	if (a < 0)
		fra = (a - abs(rda)) * (-100);
	else
		fra = (a - rda) * 100;
	if (b < 0)
		frb = (b - abs(rdb)) * (-100);
	else
		frb = (b - rdb) * 100;
	if (a == b)
		i = a;
	else
	{
		if (rdb == rda)
			i = rda;
		else
		{
			if (rdb != 0)
				i = rand() % rdb + rda;
			else
				i = 0;
		}
		if (frb == fra == 0)
			f = 0;
		else
		{
			if (i != rdb && i != rda)
				f = 0.01 * (rand() % 99);
			else if (i == rdb && i != rda)
				f = 0.01 * (rand() % frb);
			else if (i == rda && i != rdb)
				f = 0.01 * (rand() % 99 + fra);
			else
				f = 0.01 * (rand() % frb + fra);
		}
		i += f;
	}
	return i;
}