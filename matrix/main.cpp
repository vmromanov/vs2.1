#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include "Sq_matrix.h"
#include <locale.h>
#include <windows.h>

using namespace std;




int main()
{
	setlocale(LC_ALL, ".1251");// c ���������� .1251 ���� "RUS"
	SetConsoleCP(1251);// ���� ������� ���� 
	SetConsoleOutputCP(1251); // ����� ������� ����

	// 5 -���������� � ������������� �������
	// 4 - ��������� �� ������������� ������� operator[]
	// 3 - ������������ �������� ������ � ��������� */*=
	// 2 - ������������ �������� ������ � �������� +/+=/-/-=
	// 1 - ��������� � �������� � ������. ���������  set el/get el

	Matrix a(3, 4);
	Matrix b(2, 3);
	Matrix c(3, 4);
	Sq_matrix A(2);
	Sq_matrix C(2); 
	Sq_matrix B(3);
	cout << "input a(3*4), b(2*3), c(3*4):\n";
	cin >> a >> b >> c;

	cout << "input A(2), B(3), C(2):\n";
	cin >> A >> C >> B;

	cout << endl;
	cout <<"A:\n" << A <<"B:\n"<< B<<"C:\n"<<C;
	cout << "a:\n" << a << "b:\n" << b << "c:\n" << c;
	try {
		cout << "A*B:\n" << (A * C);
	}
	catch (const int)
	{
		cout << "������������ �������� ��� ���������\n";
	}
	cout << "A determ:" << A.Determinant() << endl;
	cout << "max_from diag: ";
	Max_from_Diagonals(B).Print_vector();
	cout << "min elem in A: " << Min(A)<<endl;

	try
	{
		cout << "a+c:\n";
		cout<< (a + c);
		cout << "a+b:\n";
		cout<< (a + b);
	}
	catch (const int)
	{
		cout << "������ ���������� ������� ������� �������\n";
	}

	try {
		cout << "a-c:\n";
		cout<< (a - c);
		cout << "a-b:\n";
		cout<< (a - b);
	}
	catch (const int)
	{
		cout << "������ �������� ������� ������ ��������\n";
	}

	try
	{
		cout << "a[1][1]:\n";
		cout<< a[1][1] << endl;
		cout << "a[5][4]:\n";
		cout << a[5][4] << endl;
	}
	catch(...)
	{
		cout << "��������� � �������� � �������� �� ��������� ������ �������\n";
	}

	try
	{
		cout << "a:\n" << a;
		a.set_el(100, 0,0);
		cout << a;
		b.set_el(100, 5, 0);
		cout << b;
	}
	catch (...)
	{
		cout << "������� �������� ������� �� ������������� �������\n";
	}

	try
	{
		cout << "A*A:\n" << (A * A);
		cout << "A^3:\n";
		cout << (A^3);
		cout << "B^-1:\n";
		cout << (B ^ -1);
	}
	catch (...)
	{
		cout << "������ ��������� � ������������� �������\n";
	}


	return 0;
}