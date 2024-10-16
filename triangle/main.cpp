#include <iostream>
#include "triangle.h"
#include <locale.h>
#include <windows.h>



int main()
{
	setlocale(LC_ALL, ".1251");// c кодировкой .1251 либо "RUS"
	SetConsoleCP(1251);// ввод русских букв 
	SetConsoleOutputCP(1251); // вывод русских букв


	Triangle a(1,2,1,2,1,2);
	a.show();

	Triangle b(0, 0, 0, 3, 2, 2);
	Triangle c(0, 0, 0, 0.0005, -1, 2);
	int k = b.is_triangle_in(c);
	printf("\n");
	printf("k - %d\n", k);

	return 0;
}