
#include "functions.h"

Line::Line(double a, double b, double args):Function(args)
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
	cout << "Enter polynom.example:3x^5+7x^2-3" << endl << "-> ";
	double coef = 0;
	char buff;
	while (cin.peek())
	{
		cin >> coef;
		if (cin.peek() != 'x')// если после числа не стоит х => ввод koef => просто свободный член
		{
			cin >> buff;
			if (!cin.peek())
			{
				koef = new double[1];
				koef[0] = coef;
				cout << "y = " << koef[0];
				return;
			}

			cout << "incorrect input";
			return;

		}
		cin.ignore(); //пропускаем x
		if (buff=cin.peek() != '^')
		{
			if (buff != '+' && buff != '-')
			{
				if (!cin.peek()) // значит ввод был koef*x => 2 коэфа a0=0 и a1=koef
				{

				}
			}
		}

	}





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


