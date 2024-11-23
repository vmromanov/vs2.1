
#include "functions.h"

Line::Line(double args, double a, double b):Function(args)
{
	a = a;
	b = b;

	name = new char[7];
	strcpy(name, "ax + b");
}

void Line::Calculate()
{
	cout << "Enter a and b" << endl << "-> ";
	cin >> a >> b;

	cout << "Enter x" << endl << "-> ";
	cin >> argument;

	cout << "y = " << (a * argument + b);

}

Exponent::Exponent(double args):Function(args)
{
	name = new char[4];
	strcpy(name, "e^x");
}

void Exponent::Calculate()
{
	cout << "Enter x" << endl << "-> ";
	cin >> argument;

	double k = 1.0;
	double res = 0;
	int i = 1;
	while (k >= 0.0000001)
	{
		res += k;		//k = x^n/n!
		k *= argument;  //k = x^(n+1)/n!
		k /= i++;		//k = x^(n+1)/(n+1)!
	}
	cout << "y = " << res;
}

Polynom::Polynom(double arg):Function(arg)
{
	koef = nullptr;
	size = 0;
	name = new char[19];
	strcpy(name, "an*x^n+...+a1*x+a0");
}

void Polynom::Calculate()
{
	int degree ;
	cout << "enter max degree\n-> ";
	cin >> degree;
	if (degree < 0) { cout << "нельзя брать степень < 0"; return; }
	koef = new double[degree + 1];
	cout << "введите аргументы начиная с наибольшей степени х:\n-> ";
	for (int i = 0; i <= degree; i++)
		cin >> koef[i];

	cout << "введите х\n-> ";
	cin >> argument;

	double res = koef[0];
	for (int i = 0; i < degree; i++)
	{
		res *= argument;
		res += koef[i + 1];
	}

	cout << "y = " << res;
}

int Menu::SelectItem(size_t options_amount_)
{
	int option = 0;
	cin >> option;

	while (option <= 0 && option > options_amount_)
	{
		cout << "!!!Incorrect Input !!! Try Again" << endl << "-> ";
		cin >> option;
	}

	return option;
}


