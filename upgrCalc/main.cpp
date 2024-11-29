#include "Menu.h"
#include "functions.h"

int main()
{
	Line line_func;
	Exponent exp_func;
	Polynomial polym_func;
	Calculation calcculation;
	Tabulation tabulation;

	Function* f_arr[] = { &line_func, &exp_func, &polym_func, nullptr };
	Action* a_arr[] = { &calcculation, &tabulation };

	Menu main_menu(f_arr, a_arr);

	while (Function* f_ptr = main_menu.SelectedFunction())
	{
		Action* a_ptr = main_menu.SelectedAction();
		a_ptr->Operate(f_ptr);
		system("pause");
		system("cls");
	}

	cout << "FIN" << endl;

	return 0;
}