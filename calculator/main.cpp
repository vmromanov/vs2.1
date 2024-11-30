#include "functions.h"


int main()
{
	Line line_f;
	Exponent exp_f;
	Polynom pol_f;
	X_cubed cube_f;

	Function* arr[]= { &line_f , &exp_f, &pol_f, &cube_f };
	int size = sizeof(arr) / sizeof(Function*);

	Menu menu(arr, size);

	while (Function* obj = menu.Selection())
	{
		obj->Calculate();
		system("pause");
		cout << "\033[2J\033[1;1H"; //system("cls");
	}

	return 0;
}









