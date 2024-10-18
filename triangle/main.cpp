#include <iostream>
#include "triangle.h"
#include <locale.h>
#include <windows.h>

int Option_Choose(int options_amount)
{
	int choose = 0;
	scanf("%d", &choose);
	while (choose <= 0 || choose > options_amount)
	{
		printf("Incorrect input! try again\n->");
		scanf("%d", &choose);
	}
	return choose;
}

void arr_expancion(Triangle* arr,int& size) 
{
	Triangle* tmp = new Triangle[size * 2];
	if (tmp == nullptr) throw -1;

	for (int i = 0; i < size; ++i)
	{
		tmp[i] = arr[i];
	}

	delete[] arr;
	arr = tmp;

	size *= 2;
}

bool is_triangle(Triangle& a)
{
	double side1 = a.getside1();
	double side2 = a.getside2(); 
	double side3 = a.getside3(); 

	if (side1 + 0.000001 >= side2 + side3 || side2 + 0.000001 >= side3 + side1 || side3 + 0.000001 >= side2 + side1)return false;
	return true;
}

void Menu()
{
	system("cls");
	printf("1 - создать массив треугольников\n");
	printf("2 - добавить треугольник\n");
	printf("3 - показать площядь одного из треугольников\n");
	printf("4 - показать треугольник\n");
	printf("5 - проверить вхождение одного треугольника в другой\n");
	printf("6 - сдвинуть один из треугольников\n");
	printf("7 - сравнить два треугольника по площяди\n");
	printf("8 - удалить треугольник\n");
	printf("9 - показать список треугольников\n");
	printf("10 - выход\n");
	printf("-> ");
}

int main()
{
	setlocale(LC_ALL, ".1251");// c кодировкой .1251 либо "RUS"
	SetConsoleCP(1251);// ввод русских букв 
	SetConsoleOutputCP(1251); // вывод русских букв
	//Triangle a(1,2,1,2,1,2);
	//a.show();

	
	//Triangle c(0, 0, 1, 1, -1, 2);
	//Triangle a(0, 0, 1, 1, 0, 1);
	//printf("k - %d", c.is_contains(a));
	// 
	//int k = b.is_triangle_in(c);
	//printf("\n");
	//printf("k - %d\n", k);*/
	//Triangle b(0, 0, 0, 0, 2, 2); 
	//int k = is_triangle(b);
	//printf(" k - %d", k);

	Triangle* arr=new Triangle[1];
	int main_option=0,option=0;
	int size=0;
	int amount = 0;
	while (main_option != 10)
	{
		Menu();

		main_option = Option_Choose(10);

		switch (main_option)
		{
		case 1:
		{
			delete[] arr;
			printf("введите размер массива: ");
			scanf("%d", &size);
			while (size <= 0)
			{
				printf("Неверный ввод, размер не может быть меньше 0 или равен 0\n->");
				scanf("%d", &size);
			}
			arr = new Triangle[size];

			system("pause");

			break;
		}

		case 2:
			{
			Point pArr[3];
			double x, y;
			for (int i = 1; i <= 3; ++i)
			{
				printf("введите координыты %dй точки. Формат:x y\n", i);
				scanf("%lf %lf", &x, &y);
				pArr[i - 1].set_point(x, y);
			}
			Triangle tmp(pArr[0], pArr[1], pArr[2]);
			int k = is_triangle(tmp);
			if (k == 0)
			{
				printf("фигура с введёными точками не треугольник\n");
				system("pause");
				break;
			}
			if (amount == size)
			{
				arr_expancion(arr, size);
			}

			arr[amount] = tmp;
			++amount;
			}

			system("pause");
			break;

		case 3:
			{
			printf("введите номер треугольника\n");
			int numb = Option_Choose(amount);
			printf("площадь у %s : %lf\n", arr[numb - 1].getname(), arr[numb - 1].Area());
			system("pause");
			break;
			}

		case 4:
			{
			printf("что вы хотите показать?");
			printf("1 - координаты вершин\n");
			printf("2 - площядь и стороны\n");
			printf("-> ");
			option = Option_Choose(2);
			printf(" введите номер треугольника который хотите вывести\n-> ");
			int numbt = Option_Choose(amount);
			switch (option)
			{
			case 1:
				{
				arr[numbt - 1].show();
				system("pause");
				break;
				}
			case 2:
				{
				arr[numbt - 1].show_area_sides();
				system("pause");
				break;
				}
			}


			}

		case 5:
			{
			int numb1, numb2;
			printf("введите номер треугольника, вхождение куда вы хотите проверить\n");
			numb1 = Option_Choose(amount);
			printf("введите номер треугольника, который вы хотите проверить на вхождение\n");
			numb2 = Option_Choose(amount);
			if (arr[numb1 - 1].is_contains(arr[numb2 - 1]))
			{
				printf("да, входит\n");
			}
			else printf("нет, не входит\n");

			system("pause");
			break;
			}

		case 6:
			{
			int numb = 0;
			double dx, dy;
			printf("введите номер треугольника для сдвига\n");
			numb = Option_Choose(amount);
			printf("введите сдвиг: сдвиг_x сдвиг_y\n");
			scanf("%lf %lf", &dx, &dy);

			arr[numb - 1].Move_Triangle(dx, dy);

			printf("сдвиг произведён\n");
			system("pause");
			break;
			}

		case 7:
			{
			int numb1, numb2;
			printf("проверка,площядб треугольника А больше площяди треугольника Б\n");
			printf("введите номер треугольника А\n");
			numb1 = Option_Choose(amount);
			printf("введите номер треугольника Б\n");
			numb2 = Option_Choose(amount);
			if (arr[numb1 - 1] > arr[numb2 - 1]) printf("да, больше\n");
			else printf("нет, не больше\n");

			system("pause");
			break;

			}

		case 8:
			{
			int numb;
			printf("введите номер треугольника для удаления\n");
			numb = Option_Choose(amount);
			for (int i = numb; i <= amount; ++i)
				arr[i] = arr[i + 1];
			
			--amount;

			printf("треугольник удалён\n");

			system("pause");
			break;
			}

		case 9:
			{

			printf("список треугольников:");
			for (int i = 0; i < amount; ++i)
			{
				arr[i].show();
				arr[i].show_area_sides();
				printf("--------\n");
			}
			system("pause");
			break;
			}
		}


	}


	
	return 0;
}