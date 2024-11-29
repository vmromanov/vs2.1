#include "Action.h"

void Calculation::Operate(Function* func)
{
	cout << "\nCalculate Function y = ";
	cout << func->GetName() << endl;

	func->SetCoeff();

	double x = 0;
	cout << endl << "Enter x" << endl;
	cout << "x = "; cin >> x;
	func->SetArg(x);

	cout << endl << "y = " << func->GetValue() << endl;
}

void Tabulation::Operate(Function* func)
{
	cout << "\nTabulation For Function y = ";
	cout << func->GetName() << endl;

	func->SetCoeff();

	double begin, step, end;
	cout << endl << "Enter Begin, Step, End" << endl;
	cout << "begin = "; cin >> begin;
	cout << "step = ";	cin >> step;
	cout << "end = ";	cin >> end;

	double x = begin;

	while (x <= end)
	{
		func->SetArg(x);
		cout << setw(6) << x << "|" << setw(14) << func->GetValue() << endl;

		x += step;
	}

}