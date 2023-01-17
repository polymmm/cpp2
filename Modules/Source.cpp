#include <iostream>
#include "Matrix.h"
#include "Value.h"
#include "Vector.h"

int main()
{
	using namespace std;
	string fone, ftwo, fthree, ffour;
	cout << "Enter the name of the first file: ";
	cin >> fone;
	cout << "Enter the name of the second file: ";
	cin >> ftwo;
	cout << "Enter the name of the third file: ";
	cin >> fthree;
	cout << "Enter the name of the fourth file: ";
	cin >> ffour;
	matrix(fone, ftwo);
	vector(ftwo, fthree);
	value(fthree, ffour);
	return 0;
}
