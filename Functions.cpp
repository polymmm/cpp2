#include <iostream>
#include <vector>

using namespace std;

vector<double> Y;
double max1 = 0, a, b, amin, amax, bmin, bmax, da, db, rez;
int i, n, k = 0;


void Global()
{
	cout << "Input amin, da, amax, bmin, db, bmax, n\n";
	cin >> amin >> da >> amax;
	cin >> bmin >> db >> bmax;
	cin >> n;
	cout << "|       a      |       b      | i |      Yi      |      U       |\n";
	for (a = amin; a <= amax; a = a + da)
	{
		for (b = bmin; b <= bmax; b = b + db)
		{
			for (i = 1; i <= n; i++)
			{
				if (a > 0)
				{
					rez = (i * a * a + pow(-1.0, (i + 1.0)) * i * i * (b - a)) / sqrt(
						5.0 * a * a + a * i + b * b * i * i);
				}
				else
				{
					rez = (i * a * a + i * i * (b - a)) / sqrt(5.0 * a * a - a * i + b * b * i * i);
				}
				if (abs(rez) > 2)
				{
					rez = 0.5;
				}
				if (abs(rez) > max1)
				{
					max1 = abs(rez);
				}
				if (i != n)
					cout << scientific << "| " << a << " | " << b << " | " << i << " | " << abs(rez) <<
						" |              |\n";
				else
					cout << scientific << "| " << a << " | " << b << " | " << i << " | " << abs(rez) << " | " << max1 <<
						" |\n";
			}
			Y.push_back(max1);
			max1 = 0;
		}
	}
}


void Znach(double amin1, double amax1, double bmin1, double bmax1, double da1, double db1, int n1)
{
	double a2, b2, rez2 = 0, max3 = 0;
	int i, k1;
	for (a2 = amin1; a2 <= amax1; a2 = a2 + da1)
	{
		for (b2 = bmin1; b2 <= bmax1; b2 = b2 + db1)
		{
			for (i = 1; i <= n1; i++)
			{
				if (a2 > 0)
				{
					rez2 = (i * a2 * a2 + pow(-1.0, (i + 1.0)) * i * i * (b2 - a2)) / sqrt(
						5.0 * a2 * a2 + a2 * i + b2 * b2 * i * i);
				}
				else
				{
					rez2 = (i * a2 * a2 + i * i * (b2 - a2)) / sqrt(5.0 * a2 * a2 - a2 * i + b2 * b2 * i * i);
				}
				if (abs(rez2) > 2)
				{
					rez2 = 0.5;
				}
				if (abs(rez2) > max3)
				{
					max3 = abs(rez2);
				}
				if (i != n1)
					cout << scientific << a2 << " | " << b2 << " | " << i << " | " << abs(rez) << " | " "\n";
				else
					cout << scientific << a2 << " | " << b2 << " | " << i << " | " << abs(rez) << " | " << max3 << "\n";
			}
			Y.push_back(max3);
			max3 = 0;
		}
	}
}


void SSylka(double& amin1, double& amax1, double& bmin1, double& bmax1, double& da1, double& db1, int& n1)
{
	double a2, b2, rez2 = 0, max3 = 0;
	int i, k1 = 0;
	for (a2 = amin1; a2 <= amax1; a2 = a2 + da1)
	{
		for (b2 = bmin1; b2 <= bmax1; b2 = b2 + db1)
		{
			for (i = 1; i <= n1; i++)
			{
				if (a2 > 0)
				{
					rez2 = (i * a2 * a2 + pow(-1.0, (i + 1.0)) * i * i * (b2 - a2)) / sqrt(
						5.0 * a2 * a2 + a2 * i + b2 * b2 * i * i);
				}
				else
				{
					rez2 = (i * a2 * a2 + i * i * (b2 - a2)) / sqrt(5.0 * a2 * a2 - a2 * i + b2 * b2 * i * i);
				}
				if (abs(rez2) > 2)
				{
					rez2 = 0.5;
				}
				if (abs(rez2) > max3)
				{
					max3 = abs(rez2);
				}
				if (i != n1)
					cout << scientific << a2 << " | " << b2 << " | " << i << " | " << abs(rez) << " | " "\n";
				else
					cout << scientific << a2 << " | " << b2 << " | " << i << " | " << abs(rez) << " | " << max3 << "\n";
			}
			Y.push_back(max3);
			max3 = 0;
		}
	}
}

int main()
{
	double amin1, amax1, bmin1, bmax1, da1, db1;
	int n1, o;

	cout << "Enter the transfer method number" << endl << "1 - Global variables 2 - By value 3 - By link" <<
		endl;
	cin >> o;
	switch (o)
	{
	case 1: Global();
		break;

	case 2: cout << "Input amin, da, amax, bmin, db, bmax, n";
		cin >> amin1 >> da1 >> amax1 >> bmin1 >> db1 >> bmax1 >> n1;
		Znach(amin1, amax1, bmin1, bmax1, da1, db1, n1);
		break;

	case 3: cout << "Input amin, da, amax, bmin, db, bmax, n";
		cin >> amin1 >> da1 >> amax1 >> bmin1 >> db1 >> bmax1 >> n1;
		SSylka(amin1, amax1, bmin1, bmax1, da1, db1, n1);
		break;

	default: cout << "Wrong number" << endl;
	}
}
