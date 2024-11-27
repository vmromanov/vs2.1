#include "functions.h"


int main()
{
	Line line_f;
	Exponent exp_f;
	Polynom pol_f;

	Function* arr[]= { &line_f , &exp_f, &pol_f, nullptr };
	
	Menu menu(arr);

	while (Function* obj = menu.SelectedFunction())
	{
		obj->Calculate();
		system("pause");
		system("cls");
	}

	cout << "FIN" << endl;

	return 0;
}









// дано натур число n, выбросить из записи этого числа цифры 3 и 7 оставив прежним порядок ост цифр
//3171507377->1150