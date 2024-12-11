#include <iostream>
#include "Matrix.h"

#include <locale.h>
#include <windows.h>

using namespace std;




int main()
{
	setlocale(LC_ALL, ".1251");// c кодировкой .1251 либо "RUS"
	SetConsoleCP(1251);// ввод русских букв 
	SetConsoleOutputCP(1251); // вывод русских букв

	// 5 -возведение в отрицательную степень
	// 4 - обращение по неправильному индексу operator[]
	// 3 - несовпадение размеров матриц в умножении */*=
	// 2 - несовпадение размеров матриц в сложении +/+=/-/-=
	// 1 - обращение к элементу с неправ. индексами  set el/get el

	Matrix<int> a(2, 2);
	Matrix<double> b(2, 3);
	Matrix<int> c(2, 2);
	Matrix<double> d(2, 3);

	cout << "input a(2*2), b(2*3), c(2*2), d(2*3):\n";
	cin >> a >> b >> c >> d;

	cout << endl;

	cout << "a:\n" << a << "b:\n" << b << "c:\n" << c << "d:\n" << d;

	try
	{
		cout << "a+c:\n";
		cout << (a + c);
		cout << "a+b:\n";
		cout<< (b + d);

	}
	catch (const int)
	{
		cout << "нельзя складывать матрицы разного размера\n";
	}
	
	try {
		cout << "a-c:\n";
		cout << (a - c);
		cout << "a-b:\n";
		cout<< (b - d);
	}
	catch (const int)
	{
		cout << "нельзя вычитать матрицы разных размеров\n";
	}
	
	try
	{
		cout << "a[1][1]:\n";
		cout << a[1][1] << endl;
		cout << "a[5][4]:\n";
		cout << a[5][4] << endl;
	}
	catch(...)
	{
		cout << "обращение к элементу с индексом за пределами границ массива\n";
	}

	/*try
	{
		cout << "a:\n" << a;
		a.set_el(100, 0,0);
		cout << a;
		b.set_el(100, 5, 0);
		cout << b;
	}
	catch (...)
	{
		cout << "попытка изменить элемент по неправильному индексу\n";
	}*/

	return 0;
}