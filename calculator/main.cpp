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









// ���� ����� ����� n, ��������� �� ������ ����� ����� ����� 3 � 7 ������� ������� ������� ��� ����
//3171507377->1150