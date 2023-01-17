#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <conio.h>

using namespace std;
int parts(int inwi);

int main()
{
	double s, mt, nt;
	int wi, pr;
	cout << "Set the accuracy and width of the field: ";
	cin >> pr >> wi;
	cout << setw(wi) << "The accuracy is set " << pr << " decimal places; the width of the field is set " << wi << endl;
	mt = pow((7.002 * pow(0.1, 1.0 / 3.0) - 1 + (pow(M_E, 2.0) + pow(M_E, -2.0)) / 10.0), 1.0 / 5.0);
	cout << setw(wi) << scientific << setprecision(pr) << "m(t) = " << mt << endl;
	cout << setw(wi) << fixed << "m(t) = " << mt << endl;
	nt = log(3.0) * (cos(M_PI / 5.0) + cos(3.0 * M_PI / 5.0));
	cout << setw(wi) << scientific << "n(t) = " << nt << endl;
	cout << setw(wi) << fixed << "n(t) = " << nt << endl;
	if (pow(mt, 2.0) + pow(nt, 2.0) > 0.1)
		s = atan(5.0 * pow(mt, 2.0) + 5.0 * pow(nt, 2.0));
	else
		s = asin(5.0 * pow(mt, 2.0) + 5.0 * pow(nt, 2.0));
	cout << setw(wi) << scientific << "s = " << s << endl;
	cout << setw(wi) << fixed << "s = " << s << endl << endl;

	parts(wi);
	return 0;
}

int parts(int inwi)
{
	double a, b, c, f, x, z;
	cout << setw(inwi) << "Input a: ";
	cin >> a;
	cout << setw(inwi) << "a = " << a << endl;
	cout << setw(inwi) << "Input b: ";
	cin >> b;
	cout << setw(inwi) << "b = " << b << endl;
	cout << setw(inwi) << "Input c: ";
	cin >> c;
	cout << setw(inwi) << "c = " << c << endl;
	cout << setw(inwi) << "Input x: ";
	cin >> x;
	cout << setw(inwi) << "x = " << x << endl << endl;
	if (a + pow(x, 2) <= 0 || b == 0 || x == sqrt(abs(x - b)) || x + a < 0)
	{
		cout << setw(inwi) << "Incorrect data entered, try again." << endl;
		parts(inwi);
	}
	else
	{
		f = log(a + pow(x, 2.0)) + pow(sin(x / b), 2.0);
		cout << setw(inwi) << scientific << "f = " << f << endl;
		cout << setw(inwi) << fixed << "f = " << f << endl;
		z = pow(M_E, -c * x) * (x + sqrt(x + a)) / (x - sqrt(abs(x - b)));
		cout << setw(inwi) << scientific << "z = " << z << endl;
		cout << setw(inwi) << fixed << "z = " << z << endl;
	}
	return 0;
}
