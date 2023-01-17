#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <conio.h>

using namespace std;
ofstream fout;
ifstream fin;

int main()
{
	char namein[50], nameout[50], letters[4] = {'A', 'B', 'C', 'D'};
	double points[4][2], vector[8][2], a, b, c, d, ac, bd;
	cout << "Enter the name of the file with the initial data: ";
	cin.getline(namein, 50);
	cout << "Enter the name of the file to write the data to: ";
	cin.getline(nameout, 50);
	fin.open(namein);
	if (!fin.is_open())
		cout << "The file cannot be opened" << endl;
	else
	{
		fout.open(nameout);
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 0; j <= 1; j++)
			{
				fin >> points[i][j];
				if (j == 0)
				{
					cout << "Point " << letters[i] << " (" << points[i][j]
						<< "; ";
					fout << "Point " << letters[i] << " (" << points[i][j]
						<< "; ";
				}
				else
				{
					cout << points[i][j] << ")";
					fout << points[i][j] << ")";
				}
			}
			cout << endl;
			fout << endl;
		}
		fin.close();
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 0; j <= 3; j++)
			{
				if (i != j && (points[i][0] == points[j][0] && points[i][1] ==
					points[j][1]))
				{
					cout << "The figure is degenerate" << endl;
					fout << "The figure is degenerate" << endl;
					fout.close();
					return 0;
				}
			}
		}

		ac = sqrt(pow((points[2][0] - points[0][0]), 2.0) + pow((points[2][1] -
			                                                        points[0][1]), 2.0));
		bd = sqrt(pow((points[3][0] - points[1][0]), 2.0) + pow((points[3][1] -
			                                                        points[1][1]), 2.0));
		cout << "Diagonal AC = " << ac << endl;
		cout << "Diagonal BD = " << bd << endl;
		fout << "Diagonal AC = " << ac << endl;
		fout << "Diagonal BD = " << bd << endl;

		vector[0][0] = points[1][0] - points[0][0];
		vector[1][0] = points[3][0] - points[0][0];
		vector[0][1] = points[1][1] - points[0][1];
		vector[1][1] = points[3][1] - points[0][1];
		cout << "Vector AB {" << vector[0][0] << "; " << vector[0][1] << "}" <<
			endl;
		cout << "Vector AD {" << vector[1][0] << "; " << vector[1][1] << "}" <<
			endl;
		fout << "Vector AB {" << vector[0][0] << "; " << vector[0][1] << "}" <<
			endl;
		fout << "Vector AD {" << vector[1][0] << "; " << vector[1][1] << "}" <<
			endl;
		a = (vector[0][0] * vector[1][0] + vector[0][1] * vector[1][1]) /
		(sqrt(pow(vector[0][0], 2.0) + pow(vector[0][1], 2.0)) * sqrt(pow(vector[1][0], 2.0) +
			pow(vector[1][1], 2.0)));
		cout << "Angle A is equal to " << acos(a) << " radian" << endl;
		fout << "Angle A is equal to " << acos(a) << " radian" << endl;
		vector[2][0] = points[2][0] - points[1][0];
		vector[3][0] = points[0][0] - points[1][0];
		vector[2][1] = points[2][1] - points[1][1];
		vector[3][1] = points[0][1] - points[1][1];
		cout << "Vector BC {" << vector[2][0] << "; " << vector[2][1] << "}" <<
			endl;
		cout << "Vector BA {" << vector[3][0] << "; " << vector[3][1] << "}" <<
			endl;
		fout << "Vector BC {" << vector[2][0] << "; " << vector[2][1] << "}" <<
			endl;
		fout << "Vector BA {" << vector[3][0] << "; " << vector[3][1] << "}" <<
			endl;
		b = (vector[2][0] * vector[3][0] + vector[2][1] * vector[3][1]) /
		(sqrt(pow(vector[2][0], 2.0) + pow(vector[2][1], 2.0)) * sqrt(pow(vector[3][0], 2.0) +
			pow(vector[3][1], 2.0)));
		cout << "Angle B is equal to " << acos(b) << " radian" << endl;
		fout << "Angle B is equal to " << acos(b) << " radian" << endl;

		vector[4][0] = points[1][0] - points[2][0];
		vector[5][0] = points[3][0] - points[2][0];
		vector[4][1] = points[1][1] - points[2][1];
		vector[5][1] = points[3][1] - points[2][1];
		cout << "Vector CB {" << vector[4][0] << "; " << vector[4][1] << "}" <<
			endl;
		cout << "Vector CD {" << vector[5][0] << "; " << vector[5][1] << "}" <<
			endl;
		fout << "Vector CB {" << vector[4][0] << "; " << vector[4][1] << "}" <<
			endl;
		fout << "Vector CD {" << vector[5][0] << "; " << vector[5][1] << "}" <<
			endl;
		c = (vector[4][0] * vector[5][0] + vector[4][1] * vector[5][1]) /
		(sqrt(pow(vector[4][0], 2.0) + pow(vector[4][1], 2.0)) * sqrt(pow(vector[5][0], 2.0) +
			pow(vector[5][1], 2.0)));
		cout << "Angle C is equal to " << acos(c) << " radian" << endl;
		fout << "Angle C is equal to " << acos(c) << " radian" << endl;
		vector[6][0] = points[2][0] - points[3][0];
		vector[7][0] = points[0][0] - points[3][0];
		vector[6][1] = points[2][1] - points[3][1];
		vector[7][1] = points[0][1] - points[3][1];
		cout << "Vector DC {" << vector[6][0] << "; " << vector[6][1] << "}" <<
			endl;
		cout << "Vector DA {" << vector[7][0] << "; " << vector[7][1] << "}" <<
			endl;
		fout << "Vector DC {" << vector[6][0] << "; " << vector[6][1] << "}" <<
			endl;
		fout << "Vector DA {" << vector[7][0] << "; " << vector[7][1] << "}" <<
			endl;
		d = (vector[6][0] * vector[7][0] + vector[6][1] * vector[7][1]) /
		(sqrt(pow(vector[6][0], 2.0) + pow(vector[6][1], 2.0)) * sqrt(pow(vector[7][0], 2.0) +
			pow(vector[7][1], 2.0)));
		cout << "Angle D is equal to " << acos(d) << " radian" << endl;
		fout << "Angle D is equal to " << acos(d) << " radian" << endl;
		if (((points[2][0] - points[1][0]) * (points[3][1] - points[0][1]) ==
			(points[3][0] - points[0][0]) * (points[2][1] - points[1][1])) || ((points[1][0] -
				points[0][0]) * (points[2][1] - points[3][1]) == (points[2][0] - points[3][0]) *
			(points[1][1] - points[0][1])))
		{
			if (((points[1][0] - points[0][0]) * (points[2][1] - points[3][1]) ==
				(points[2][0] - points[3][0]) * (points[1][1] - points[0][1])) && ((points[2][0] -
					points[1][0]) * (points[3][1] - points[0][1]) == (points[3][0] - points[0][0]) *
				(points[2][1] - points[1][1])))
				if (ac == bd)
				{
					cout << "Type of quadrilateral: rectangle." << endl;
					fout << "Type of quadrilateral: rectangle." << endl;
				}
				else
				{
					cout << "Type of quadrilateral: parallelogram." <<
						endl;
					fout << "Type of quadrilateral: parallelogram" <<
						endl;
				}
			else
			{
				cout << "Type of quadrilateral: trapezoid" << endl;
				fout << "Type of quadrilateral: trapezoid" << endl;
			}
		}
		else
		{
			cout << "Type of quadrilateral: arbitrary" << endl;
			fout << "Type of quadrilateral: arbitrary" << endl;
		}
		fout.close();
	}
	return 0;
}
