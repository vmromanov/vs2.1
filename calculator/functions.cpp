
#include "functions.h"

Line::Line()
{
	a = 0;
	b = 0;

	name = new char[7];
	strcpy(name, "ax + b");
}

Line::Line(double args, double a_, double b_):Function(args)
{
	a = a_;
	b = b_;

	name = new char[7];
	strcpy(name, "ax + b");
}

void Line::Calculate()
{
	cout << "Enter a and b" << endl << "-> ";
	cin >> a >> b;

	cout << "Enter x" << endl << "-> ";
	cin >> argument;

	cout << "y = " << (a * argument + b)<< endl;

}

Exponent::Exponent()
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
	cout << "y = " << res << endl;
}

Polynom::Polynom()
{
	koef = nullptr;
	name = new char[20];
	strcpy(name, "a_nx^n + ... + a_0");
}

void Polynom::Calculate()
{
	int degree ;
	cout << "enter max degree\n-> ";
	cin >> degree;
	if (degree < 0) { cout << "cant take degree less than 0\n"; return; }
	koef = new double[degree + 1];
	cout << "enter arguments, startimng from max degree\n-> ";
	for (int i = 0; i <= degree; i++)
		cin >> koef[i];

	cout << "enter x\n-> ";
	cin >> argument;

	double res = koef[0];

	for (int i = 0; i < degree; i++)
	{
		res *= argument;
		res += koef[i + 1];
	}

	cout << "y = " << res<<endl;
}

int Menu::Option_Choose(size_t options_amount_)
{
	int option = 0;
	cin >> option;

	while (option <= 0 || option > options_amount_)
	{
		cout << "!!!Incorrect Input !!! Try Again" << endl << "> ";
		cin >> option;
	}

	return option;
}

Function* Menu::Selection()
{
	int option = 0;
	
	cout << "Which Function Do You Want To Use?" << endl;

	for (size_t i = 0; i < size; ++i)
		cout << i + 1 << ". "<<"y(x) = " << obj_ptr[i]->GetName() << endl;

	cout << size + 1 << ". Exit" << endl << "> ";
	option = Option_Choose(size + 1);

	if (option == (size + 1))return nullptr;

	return obj_ptr[option - 1];
}

X_cubed::X_cubed()
{
	name = new char[4];
	strcpy(name, "x^3");
}

void X_cubed::Calculate()
{
	cout << "Enter x: ";
	cin >> argument;
	cout << "y = " << (argument * argument * argument)<<endl;
}
