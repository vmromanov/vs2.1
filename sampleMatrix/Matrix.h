#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Matrix
{
protected:
	int row;
	int column;
	T** matrix;

public:
	Matrix<T>(int r = 2, int col = 3);
	
	Matrix<T>(const Matrix& other);
	
	virtual ~Matrix<T>();

	T* operator[](int i);

	T* operator[](int i) const;

	Matrix<T>& operator=(Matrix<T>& other);
	
	Matrix<T> operator+(Matrix<T>& other) const;

	Matrix<T>& operator+=(Matrix<T>& other);

	Matrix<T> operator-(Matrix<T>& other) const;
	
	//Matrix<T>& operator-=(Matrix<T>& other);

	Matrix<T> operator*(Matrix<T>& other) const;

	//Matrix<T>& operator*=(Matrix<T>& other);

	Matrix<T> operator/(double el) const;

	//Matrix<T>& operator/=(double el);

	Matrix<T> operator*(double el) const;

	//Matrix<T>& operator*=(double el);
	
	friend ostream& operator<<(ostream& stream, const Matrix<T>& M);

	friend istream& operator>>(istream& stream, Matrix<T>& M);

	virtual bool operator==(Matrix<T>& other) const;

	bool operator!=(Matrix<T>& other_);

	//void set_el(T el, int r, int coll);
	
	//T get_el(int r, int c) const;
	
	int get_row() { return row; }

	int get_coll() { return column; }

	//virtual void transpon();
	
	//void print();
};



