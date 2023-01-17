#include "Value.h"

int value(std::string namein, std::string nameout)
{
	using namespace std;
	ofstream fout;
	ifstream fin;
	int n = 0;
	double u, max;
	string s;
	fin.open(namein);
	getline(fin, s);
	for (int i = 0; i < s.length(); i++)
		if (s[i] == ' ')
			n++;
	fin.close();
	double* X = new double[n];
	if (X == NULL)
		return -1;
	fin.open(namein);
	for (int i = 0; i < n; i++)
		fin >> X[i];
	fin.close();
	max = abs(X[0] + 1.0) - abs(X[0]);
	for (int i = 0; i < n; i++)
	{
		u = abs(X[i] + 1.0) - abs(X[i]);
		if (u >= max)
			max = u;
	}
	fout.open(nameout);
	fout << max;
	fout.close();
	return 0;
}
