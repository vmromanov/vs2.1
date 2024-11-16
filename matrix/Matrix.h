#pragma once
#include <iostream>
using namespace std;

class Matrix
{
protected:
	int row;
	int column;
	double** matrix;

public:
	Matrix(int r = 2, int col = 3);
	
	Matrix(const Matrix& other);
	
	virtual ~Matrix();

	void input();

	double* operator[](int i);

	double* operator[](int i) const;

	Matrix& operator=(Matrix& other);
	
	Matrix operator+(Matrix& other) const;

	Matrix& operator+=(Matrix& other);

	Matrix operator-(Matrix& other) const;
	
	Matrix& operator-=(Matrix& other);

	Matrix operator*(Matrix& other) const;

	Matrix& operator*=(Matrix& other);

	Matrix operator/(double el) const;

	Matrix& operator/=(double el);

	Matrix operator*(double el) const;

	Matrix& operator*=(double el);
	
	friend ostream& operator<<(ostream& stream, const Matrix& M);

	friend istream& operator>>(istream& stream, Matrix& M);

	virtual bool operator==(Matrix& other) const;

	bool operator!=(Matrix& other_);

	void set_el(double el, int r, int coll);
	
	double get_el(int r, int c) const;
	
	int get_row() { return row; }

	int get_coll() { return column; }

	virtual void transpon();
	
	void print();
};

double Min(Matrix& matrix_);

