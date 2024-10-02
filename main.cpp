#include <iostream>
#include <stdlib.h>
#include <string.h>
//#include "square.h"
#include "sotrudnik.h"
#include "BASE.h"


using namespace std;

const int maxn = 100;

int main()
{

	// sotrudnik :


	/*sotrudnik arr[maxn];

	int k = 0;
	int err = Sozd_f("File.txt", k, arr);
	printf("err: %d\n", err);
	if (err)
	{
		printf("cant create list from file\n");
		return 0;
	}

	float medium_sal = 0.0;
	int new_size = 0;
	int now_Year = 2024;
	char** new_list = new char* [maxn];
	if (new_list == NULL)
	{
		printf("cant create array for new list\n");
		return 0;
	}
	for (int k = 0; k < maxn; ++k)
	{
		new_list[k] = new char[31];
		if (new_list[k] == NULL)
		{
			printf("cant allocate memmory for newlist member\n");
			return 0;
		}
	}
	medium_sal = request1(arr, maxn, new_size, new_list, now_Year);


	if (new_size != 0) {
		printf("average salary of employees in your request:\n");
		printf("%f\n", medium_sal);

		printf("employees list for your request:\n\n");

		for (int i = 0; i < new_size; ++i)
		{

			printf("%s", new_list[i]);

			printf("\n");
		}
	}
	else
	{
		printf("there are no employees suitable for your request.\n");
	}

	for (int i = 0; i < maxn; i++)
	{
		delete[] new_list[i];
	}
	delete[] new_list;*/
	


	//magic cube


	/*
	int size = 0;
	
	int** matrix = matrix_creation("File1.txt", size);
	
	if (matrix == NULL || size <= 0)
	{
	printf("cant create matrix\n");
	return 0;
	}
	int err = matrix_input("File1.txt",size,matrix);

	if (err)
	{
		printf("cant fill matrix\n");
		return 0;
	}

	bool rez = is_magic_square(matrix, size);

	if (rez == true)
	{
		printf("matrix is magic square\n");
	}
	else
	{
		printf("matrix isnt magic square");
	}*/
	

	//BAZA

	Baza* data_base = new Baza[1];
	int main_option = 0;
	
	int err = 0;

	while (main_option != 5)
	{
		Main_Menu();

		main_option = Option_Choose(5);

		switch (main_option)
		{

		 case 1:
		  {
			
			err = data_base->Create_Baza_F("FIK.txt");

			switch (err)
			{
			case -1:
				printf("File was not found\n");
			
				return -1;

			case -2:
				printf("cant open file\n");
				
				return -2;


			case -3:
				printf("memmory allocating errors while expanding database\n");
				
				return -3;

			case 0:
				printf("Creation was successful\n");
				
				break;
			}

			system("pause");

		 	break;
		  }

		 case 2:
		  {
			data_base->Print_Baza();
			system("pause");
			break;
		  }

		 case 3:
		  {
			How_to_edit_menu();

			int option = 0;
			option = Option_Choose(3);

			switch (option)
			{
			case 1:
			{
				data_base->Baza_del_el();
				printf("Element deleted successfully\n");
				system("pause");
				break;
			}

			case 2:
			{
				data_base->Baza_add();
				printf("Element added successfully\n");
				system("pause");
				break;
				
			}

			case 3:
			{
				data_base->Baza_correction();
				printf("Element changed successfully\n");
				system("pause");
				break;
			}

			system("pause");
			break;

			}

		  }

		 case 4:
		   {
			char filename[255];
			
			printf("Enter file name\n->");
			scanf("%s", filename);

			int err = data_base->Baza_cpy(filename);
			if (err == 0)
			{
				printf("baza copied succsessfully\n");
			}
			system("pause");
		 	break;
		   }

		}
	}
	return 0;

}




