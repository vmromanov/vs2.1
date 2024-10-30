#pragma once

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

	double* operator[](int i);

	Matrix& operator=(Matrix& other);
	
	Matrix& operator+(Matrix& other) const;

	Matrix& operator+=(Matrix& other);

	Matrix& operator-(Matrix& other) const;
	
	Matrix& operator-=(Matrix& other);

	Matrix& operator*(Matrix& other) const;

	Matrix& operator/(double el) const;

	Matrix& operator/=(double el);

	Matrix& operator*(double el) const;

	Matrix& operator*=(double el);
	
	virtual bool operator==(Matrix& other) const;

	bool operator!=(Matrix& other_);

	void set_el(double el, int r, int coll);
	
	double get_el(int r, int c) const;
	
	int get_row() { return row; }

	int get_coll() { return column; }

	virtual void transpon();
	
	void print();
};




