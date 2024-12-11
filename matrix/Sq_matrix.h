#pragma once
#include "Matrix.h"
#include "Vector.h"

class Sq_matrix : public Matrix
{
public:
	Sq_matrix(int n = 2) :Matrix(n, n) {};

	Sq_matrix(Sq_matrix& other);

	Sq_matrix(Matrix& other);

	void transpon() override;

	double Determinant();

	Sq_matrix pow(int i);

	double* operator[](int i);

	double* operator[](int i) const { return matrix[i]; }
	using Matrix::operator*;
	using Matrix::operator+;
	using Matrix::operator-;

	Sq_matrix& operator=(const Sq_matrix& other);

	Sq_matrix operator^(int i);

	Sq_matrix& operator*=(Sq_matrix& other);

	Sq_matrix& operator*=(double el);

	Sq_matrix& operator+=(Sq_matrix& other);

	Sq_matrix& operator-=(Sq_matrix& other);

	bool operator==(Sq_matrix& other);

	bool operator!=(Sq_matrix& other);
};

Vector Max_from_Diagonals(Sq_matrix& matrix_);

Vector tracematrix(SquareMatrix& matrix,int n)
{
  if (n <= 0)
  {
    throw 5;
  }
  double trace = 0;
  Vector result(n);
  SquareMatrix duplicate = matrix;
  for (int i = 0; i <n; i++)
  {
    result[i] = duplicate.trace();
    duplicate = duplicate * matrix;
  }
  return result;
}
