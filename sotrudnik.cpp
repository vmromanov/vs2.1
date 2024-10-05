#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "sotrudnik.h"
using namespace std;

sotrudnik::sotrudnik()
	{
		name = new char[31];
		age = 0;
		sal = 0.0;
		data[0] = '\0';
	}

sotrudnik::sotrudnik(int n)
{
	name = new char[n];
	age = 0;
	sal = 0.0;
	data[0] = '\0';
}

// Конструктор копирования
sotrudnik::sotrudnik(const sotrudnik& b)
{
	name = new char[strlen(b.name) + 1];
	strcpy(name, b.name);
	age = b.age;
	sal = b.sal;
	strcpy(data, b.data);
}


// Перегрузка операции присваивания
const sotrudnik& sotrudnik:: operator = (const sotrudnik& b)
{
	if (&b == this)
		return *this;
	delete[] name;
	name = new char[strlen(b.name) + 1];
	strcpy(name, b.name);
	age = b.age;
	sal = b.sal;
	strcpy(data, b.data);
	return *this;
}

sotrudnik::~sotrudnik()
{
	if (name != NULL)
	{
		delete[] name;
	}
}

void sotrudnik::Set_Name(char* s)
{
	strcpy(name, s);
}

void sotrudnik::Set_Age(int age1)
{
	age = age1;
}

void sotrudnik::Set_sal(float s)
{
	sal = s;
}

void sotrudnik::Set_Data(char* s)
{
	strcpy(data, s);
}

char* sotrudnik::Get_Name()
{
	return name;
}

int sotrudnik::Get_Age()
{
	return age;
}

float sotrudnik::Get_Sal()
{
	return sal;
}

char* sotrudnik::Get_Data()
{
	return data;
}

void sotrudnik::Print()
{
	printf("%-31s %5d %9.5f %13s\n", name, age, sal, data);
}

void sotrudnik::Vvod()
{
	char initials[5];

	printf("Enter employee info\nExample: Last_Name Initials Birth_Year Salary Start_Date \n-> ");

	scanf("%s %s %d %f %s", name, initials, &age, &sal, data);
	strcat(name, " ");
	strcat(name, initials);

}

bool sotrudnik::siv(char* s)
{
	//if (strcmp(name, s)==0) return true;
	return !strcmp(name, s);
}



int Sozd_f(const char* name_file, int& k, sotrudnik* a)
{
	FILE* f = fopen(name_file, "r");
	if (f == NULL) return -1;

	char fio[31];
	char init[5];
	int age1 = 0;
	float salary = 0.0;
	char dat[11];
	while (fscanf(f, "%30s %4s %d %f %10s", fio, init, &age1, &salary, dat) == 5)
	{
		init[4] = '\0';
		strcat(fio, " ");
		strcat(fio, init);
		a[k].Set_Age(age1);
		a[k].Set_Data(dat);
		a[k].Set_Name(fio);
		a[k].Set_sal(salary);
		++k;
	}

	fclose(f);

	return 0;
}

float request1(sotrudnik* arr, int size, int& k, char** Fio_25, int year)
{
	k = 0;
	float salary = 0.0;
	int dat = 0;
	char date[11];

	for (int i = 0; i < size; ++i)
	{
		strcpy(date, arr[i].Get_Data());
		dat = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
		if (year - dat > 25)
		{
			strcpy(Fio_25[k], arr[i].Get_Name());
			k++;
			salary += arr[i].Get_Sal();
		}
	}
	if (k) { salary /= k; }
	return salary;
}






