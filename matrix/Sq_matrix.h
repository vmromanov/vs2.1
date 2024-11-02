#pragma once
#include "Matrix.h"

class Sq_matrix : public Matrix
{
public:
	Sq_matrix(int n = 2) :Matrix(n, n) {};

	Sq_matrix(Sq_matrix& other);

	Sq_matrix(Matrix& other);

	void transpon() override;

	Sq_matrix pow(int i);

	double* operator[](int i);

	double* operator[](int i) const { return matrix[i]; }

	Sq_matrix& operator=(const Sq_matrix& other);

	Sq_matrix operator^(int i);

	Sq_matrix& operator*=(Sq_matrix& other);

	Sq_matrix operator*(Sq_matrix& other);

	Sq_matrix& operator*=(double el);

	Sq_matrix operator*(double el);

	Sq_matrix operator+(Sq_matrix& other);

	Sq_matrix& operator+=(Sq_matrix& other);

	Sq_matrix operator-(Sq_matrix& other);

	Sq_matrix& operator-=(Sq_matrix& other);

	bool operator==(Sq_matrix& other);

	bool operator!=(Sq_matrix& other);
};

