
#include "functions.h"

Line::Line()
{
	a = 0;
	b = 0;

	name = new char[7];
	strcpy(name, "ax + b");
}

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

int Menu::GetFunctionIndex(size_t options_amount_)
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

Function* Menu::SelectedFunction()
{
	int option = 0;
	int arr_size = sizeof(**obj_ptr) / sizeof(Function*);

	cout << "Which Function Do You Want To Use?" << endl;

	for (size_t i = 0; i < arr_size; ++i)
		cout << i + 1 << ". " << obj_ptr[i]->GetName() << endl;

	cout << arr_size + 1 << ". Exit" << endl << "> ";

	return obj_ptr[GetFunctionIndex(arr_size + 1) - 1];
}


