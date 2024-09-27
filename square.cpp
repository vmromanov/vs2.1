#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;



int** matrix_creation(const char* file,int size)
{
	FILE* f1 = fopen(file, "r");
	if (f1 == NULL) { printf("cant open file\n"); return NULL; }

	fscanf(f1, "%d", &size);

	int** matrix = new int* [size];
	if (matrix == NULL)return NULL;
	for (int i = 0; i < size; ++i)
	{
		matrix[i] = new int[size];
		if (matrix[i] == NULL)return NULL;
	}
	fclose(f1);
	return matrix;
}

int matrix_input(const char* namef, int& size, int** matrix)
{
	


	FILE* f1 = fopen(namef, "r");
	if (f1 == NULL)return -1;

	fscanf(f1, "%d", &size);

	for (int i = 0; i < size; ++i)
	{
		for (int k = 0; k < size; ++k)
		{
			fscanf(f1, "%d", &matrix[i][k]);
		}
	}

	fclose(f1);
	return 0;
}

bool is_magic_square(int** matrix, int size)
{
	int sum = 0;

	for (int i=0;i<size;++i)
	{
		sum += matrix[0][i];
	}

	int main_diag = 0;
	int side_diag = 0;

	for (int i = 0; i < size; ++i)
	{
		main_diag += matrix[i][i];
		side_diag += matrix[i][size - 1 - i];
	}
	if (main_diag != sum || side_diag != sum)
	{
		return false;
	}

	for (int i = 1; i < size; ++i)
	{
		int row_sum = 0;
		int collumn_sum = 0;
		for (int j = 0; j < size; ++j)
		{
			row_sum += matrix[i][j];
			collumn_sum += matrix[j][i];
		}

		if (row_sum != sum || collumn_sum!= sum)
		{
			return false;
		}
	}



	return true;
}
//int main()
//{
//	char name[] = "File1.txt";
//	int size = 0;
//
//	int** matrix = matrix_creation(name, size);
//	if (matrix == NULL || size <= 0)
//	{
//		printf("cant create matrix");
//		return 0;
//	}
//	int err = matrix_input(name,size,matrix);
//
//
//	return 0;
//}


