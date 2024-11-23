#include "Sq_matrix.h"
#include <iostream>
using namespace std;
Sq_matrix::Sq_matrix(Sq_matrix& other):Matrix(other.row,other.row)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			matrix[i][j] = other[i][j];
}

Sq_matrix::Sq_matrix(Matrix& other)
{
	int size;
	if ((size=other.get_coll()) != other.get_row()) throw 1;

	matrix = new double* [size];
	for (int i = 0; i < size; i++)
		matrix[i] = new double[size];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = other[i][j];
}

void Sq_matrix::transpon()
{
	double tmp;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < i; j++)
		{
			tmp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = tmp;
		}
}

double Sq_matrix::Determinant()
{
	double determinant = 0;

	if (row == 1)
		return matrix[0][0];

	Sq_matrix tmp_matrix(row - 1);

	for (int i = 0; i < row; i++)
	{
		int subi = 0;
		for (int v = 1; v < row; v++)
		{
			int subj = 0;
			for (int w = (subj == i) ? (1) : (0); w < row; (subj == i) ? (w = w + 2) : (w++))
			{
				tmp_matrix[subi][subj] = matrix[v][w];
				subj++;
			}
			subi++;
		}
		determinant += ((i % 2 ? -1 : 1) * matrix[0][i]) * tmp_matrix.Determinant();
	}


	return determinant;
}

//Sq_matrix Sq_matrix::operator*(Sq_matrix& other)
//{
//	Sq_matrix res(row);
//
//	for (int i = 0; i < row; ++i) 
//		for (int j = 0; j < res.column; ++j) 
//			for (int k = 0; k < column; ++k) 
//				res[i][j] += matrix[i][k] * other[k][j]; 
//	 
//	return res; 
//}

Sq_matrix& Sq_matrix::operator*=(double el)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			matrix[i][j] *= el;

	return (*this);
}

//Sq_matrix Sq_matrix::operator*(double el)
//{
//	Sq_matrix res(row);
//
//	for (int i = 0; i < row; i++)
//		for (int j = 0; j < row; j++)
//			res[i][j] = matrix[i][j] * el;
//
//	return res;
//}

//Sq_matrix Sq_matrix::operator+(Sq_matrix& other)
//{
//	Sq_matrix res(row);
//	for (int i = 0; i < row; ++i)
//		for (int j = 0; j < column; ++j)
//			res.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
//	return res;
//}

Sq_matrix& Sq_matrix::operator+=(Sq_matrix& other)
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			matrix[i][j] += other[i][j];

	return(*this);
}

//Sq_matrix Sq_matrix::operator-(Sq_matrix& other)
//{
//	Sq_matrix res(row);
//	for (int i = 0; i < row; ++i)
//		for (int j = 0; j < column; ++j)
//			res.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
//	return res;
//}

Sq_matrix& Sq_matrix::operator-=(Sq_matrix& other)
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			 matrix[i][j] -= other.matrix[i][j];

	return *this;
}

bool Sq_matrix::operator==(Sq_matrix& other)
{
	if (row != other.row) return false;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			if (matrix[i][j] != other[i][j])return false;
	return true;
}

bool Sq_matrix::operator!=(Sq_matrix& other)
{
	if (row != other.row) return true;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			if (matrix[i][j] != other[i][j])return true;
	return false;
}

Sq_matrix& Sq_matrix::operator*=(Sq_matrix& other)
{
	if (row != other.row)throw 3;

	Sq_matrix res(row);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < res.column; ++j)
			for (int k = 0; k < column; ++k)
				res[i][j] += matrix[i][k] * other[k][j];

	*this = res;
	
	return (*this);
}

Sq_matrix Sq_matrix::pow(int k)
{
	if (k < 0)throw 5;

	Sq_matrix res(row);

	for (int i = 0; i < row; i++)
		res[i][i] = 1;

		for (int i = 1; i <= k; i++)
			res *= (*this);

	return res;
}

double* Sq_matrix::operator[](int i)
{
	if (i < 0 || i >= row) throw 4;

	return matrix[i];
}

Sq_matrix& Sq_matrix::operator=(const Sq_matrix& other)
{
	if (&other == this)return *this;

	if (row != other.row)
	{
		row = other.row;
		column = other.column;
		for (int i = 0; i < row; i++) delete[] matrix[i];
		delete[] matrix;
		matrix = new double* [row];
		for (int i = 0; i < row; i++)
			matrix[i] = new double[row];
	}
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			matrix[i][j] = other[i][j];

	return *this;

}

Sq_matrix Sq_matrix::operator^(int k)
{
	if (k < 0)throw 5;

	Sq_matrix res(row);

	for (int i = 0; i < row; i++)
		res[i][i] = 1;
	
		for (int i = 1; i <= k; i++)
			res *= (*this);
			
		

	

	return res;
}

Vector Max_from_Diagonals(Sq_matrix& matr)
{
	int size = matr.get_row() * 2 - 1;
	Vector array(nullptr, size);

	int index = 0;
	int rv = matr.get_row();
	for (int i = rv - 1; i >= 0; i--)
	{
		double diagonal1 = 0;
		double diagonal2 = 0;
		int temp = i;

		for (int j = 0; j < rv - i; j++)
		{
			if (diagonal1 < matr[temp][j]) diagonal1 = matr[temp][j];
			if (diagonal2 < matr[j][temp]) diagonal2 = matr[j][temp];

			temp++;
		}

		array[index] = diagonal1;
		if (i != 0)
			array[size - 1 - index] = diagonal2;
		index++;
	}


	return array;
}
