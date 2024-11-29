#include "functions.h"

void Line::SetCoeff()
{
	cout << endl << "Enter a and b" << endl; 
	cout << "a = "; cin >> a; 
	cout << "b = "; cin >> b; 
}

void Exponent::SetCoeff()
{
	;
}

double Exponent::GetValue()
{
	double result = 0;
	double k = 1;
	int i = 1;

	while (k >= 0.0000001)
	{
		result += k;		//k = x^n/n!
		k *= argument;  //k = x^(n+1)/n!
		k /= i++;		//k = x^(n+1)/(n+1)!
	}

	return result;
}

void Polynomial::SetCoeff()
{
	int degree;
	cout << "enter max degree\n-> ";
	cin >> degree;
	if (degree < 0) { cout << "cant take degree less than 0\n"; return; }
	size = degree + 1;
	coefficients = new double[degree + 1];

	cout << "enter arguments, startimng from max degree\n-> ";
	for (int i = 0; i <= degree; i++)
		cin >> coefficients[i];
}

double Polynomial::GetValue()
{
	double result = coefficients[0];

	for (size_t i = 1; i < size; ++i)
	{
		result *= argument;
		result += coefficients[i];
	}

	return result;
}
