#include "BASE.h"
#include "sotrudnik.h"
#include <iostream>

Baza::Baza() //obiedinit s konstruktorom s parametrom
{
	size = 100;
	amount = 0;
	arr = new sotrudnik[size];
}

Baza::Baza(int n)
{
	arr = new sotrudnik[n];
	size = 100;
	amount = 0;
}

Baza::~Baza()
{
	if (arr != nullptr)
	{
		delete[] arr;
	}
}

int Baza::Basa_Expansion()
{
	sotrudnik* tmp = new sotrudnik[size * 2];
	if (tmp == nullptr) return -1;

	for (int i = 0; i < amount; ++i)
	{
		tmp[i] = arr[i];
	}

	delete[] arr;
	arr = tmp;

	size *= 2;

	return 0;
}

int Baza::Create_Baza_F(const char* namefile)
{
	if (!namefile)
		return -1;

	FILE* f = fopen(namefile, "r");

	if (f==nullptr) 
	{
		return -2;
	}

	char fio[31];
	char init[5];
	int age1 = 0;
	float salary = 0.0;
	char dat[11];
	while (fscanf(f, "%s %s %d %f %s", fio, init, &age1, &salary, dat) == 5)
	{ 
		init[4] = '\0';
		strcat(fio, " ");
		strcat(fio, init);
		arr[amount].Set_Age(age1);
		arr[amount].Set_Data(dat);
		arr[amount].Set_Name(fio);
		arr[amount].Set_sal(salary);
		++amount;

		if (amount == size)
		{
			int rez = Basa_Expansion();//change size
			if (rez != 0) 
			{
				fclose(f);
				return -3; 
			}

		}

	}

	fclose(f);

	return 0;
}

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

void Baza::Print_Baza()
{
	for (int i = 0; i < amount; ++i)
	{
		printf("%5d ", i);
		arr[i].Print();
	}
}

void Baza::Baza_add(sotrudnik emp)
{

	/*arr[amount].Vvod();
	++amount;*/
	
	if (amount == size)
	{
		int err = Basa_Expansion();
		if (err)
		printf("cant expand base after adding new employee\n");
	}

	int numb = 0;

	for (int i = 0; i < amount; ++i)
	{
		if (strcmp(arr[i].Get_Name(), emp.Get_Name()) > 0)
		{
			break;
		}
		else
		{
			numb++;
		}
	}

	for (int i = amount; i > numb; --i)
	{
		arr[i] = arr[i - 1];
	}
	
	arr[numb] = emp;
}

void Baza::Baza_del_el(char* name)
{
	if (amount == 0)
	{
		printf("Baza is empty\n");
		return;
	}


	for (int i = 0; i < amount; ++i)
	{
		if (arr[i].siv(name) == true)
		{
			for (int j = i; j < amount; ++j)
				arr[j] = arr[j + 1];
			--amount;
			break;
		}
	}
}

void Employee_Edit_Menu()
{
	system("cls");
	printf("what do you want to change?\n");
	printf("1 - Name\n");
	printf("2 - Salary\n");
	printf("-> ");
	
}

void Baza::Baza_correction(char* name1)//peredel na 2 funktsii
{
	printf("Enter name and initials of employee you want to change\n");

	char name1[31];
	char inits[5];

	scanf("%s %s", name1, inits);
	inits[4] = '\0';
	strcat(name1, " ");
	strcat(name1, inits);

    int num = -1;
	for (int i = 0; i < amount; ++i)
	{
		if (arr[i].siv(name1)==true)
		{
			num = i;
			printf("%d", i);
			break;
		}
		if (i == amount - 1 && num == -1)
		{
			printf("Employee with name you inserted does not exist");
			return;
		}
	}

	int choose = 0;

	Employee_Edit_Menu();

	choose = Option_Choose(2);

	switch (choose)
	{
	case 1:
	{
		printf("Enter new name and initials\n-> ");

		scanf("%s %s", name1, inits);
		strcat(name1, " ");
		strcat(name1, inits);

		arr[num].Set_Name(name1);

		break;
	}
	case 2:
	{
		float sal = 0.0;

		printf("Enter new salary\n-> ");
		scanf("%f", &sal);

		arr[num].Set_sal(sal);

		break;
	}

	}

	return;
}

int Baza::Baza_cpy(char* namef)
{
	if (namef == NULL)
	{
		printf("Filename incorrect\n");
		return -1;
	}

	FILE* f = fopen(namef, "w");
	if (f == NULL)
	{
		printf("Cant open file\n");
		return -2;
	}

	for (int i = 0; i < amount; ++i)
	{
		fprintf(f, "%s %d %f %s\n", arr[i].Get_Name(), arr[i].Get_Age(), arr[i].Get_Sal(), arr[i].Get_Data());
	}

	fclose(f);
	return 0;
}  

void Main_Menu()
{
	system("cls");
	printf("what do you want to do?\n");
	printf("1 - Create data base from file\n");
	printf("2 - Print data base\n");
	printf("3 - edit data base\n");
	printf("4 - Print base to file\n");
	printf("5 - exit\n");
	printf("-> ");
}

void How_to_edit_menu()
{
	printf("what do you want to do?\n");
	printf("1 - delete element from base\n");
	printf("2 - add element\n");
	printf("3 - edit element\n");
	printf("-> ");
}




