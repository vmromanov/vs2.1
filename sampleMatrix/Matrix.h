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
	Matrix<T>(int r = 2, int col = 3)
	{
		{
			if (r < 0 || col < 0)
				throw 1;
			row = r; column = col;
			matrix = new T * [row];
			for (int i = 0; i < row; ++i)
				matrix[i] = new T[column];
			for (int i = 0; i < row; ++i)
				for (int j = 0; j < column; ++j)
				{
					matrix[i][j] = (T)0.0;
				}
		}
	}
	
	Matrix<T>(const Matrix& other)
	{
		row = other.row;
		column = other.column;
		matrix = new T * [row];
		for (int i = 0; i < row; ++i)
			matrix[i] = new T[column];

		for (int i = 0; i < row; ++i)
			for (int j = 0; j < column; ++j)
			{
				matrix[i][j] = other.matrix[i][j];
			}
	}
	
	virtual ~Matrix<T>()
	{
		for (int i = 0; i < row; ++i)
			delete[] matrix[i];
		delete[] matrix;
	}

	T* operator[](int i)
	{
		if (i < 0 || i >= row) throw 4;

		return matrix[i];
	}

	T* operator[](int i) const
	{
		if (i < 0 || i >= row) throw 4;

		return matrix[i];
	}

	Matrix<T>& operator=(Matrix<T>& other)
	{
		if (row != other.row || column != other.column)
		{
			delete[] matrix;
			row = other.row;
			column = other.column;
			matrix = new T * [row];
			for (int i = 0; i < row; i++)
				matrix[i] = new T[column];
		}

		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				matrix[i][j] = other[i][j];

		return *this;
	}
	
	Matrix<T> operator+(Matrix<T>& other) const
	{
		if (row != other.row || column != other.column)
			throw 2;

		Matrix res(row, column);
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < column; ++j)
				res[i][j] = matrix[i][j] + other[i][j];
		return res;
	}

	Matrix<T>& operator+=(Matrix<T>& other)
	{
		if (row != other.row || column != other.column)
			throw 2;

		for (int i = 0; i < row; ++i)
			for (int j = 0; j < column; ++j)
				matrix[i][j] += other.matrix[i][j];

		return *this;
	}

	Matrix<T> operator-(Matrix<T>& other) const
	{
		if (row != other.row || column != other.column)
			throw 2;

		Matrix res(row, column);
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < column; ++j)
				res.matrix[i][j] = matrix[i][j] - other[i][j];
		return res;
	}
	
	Matrix<T>& operator-=(Matrix<T>& other)
	{
		if (row != other.row || column != other.column)
			throw 2;

		for (int i = 0; i < row; ++i)
			for (int j = 0; j < column; ++j)
				matrix[i][j] -= other[i][j];

		return *this;
	}

	Matrix<T> operator*(Matrix<T>& other) const
	{
		if (row != other.column || column != other.row)
			throw 3;

		Matrix res(row, other.column);

		for (int i = 0; i < row; ++i)
			for (int j = 0; j < res.column; ++j)
				for (int k = 0; k < column; ++k)
					res[i][j] = matrix[i][k] * other[k][j];

		return res;
	}

	Matrix<T>& operator*=(Matrix<T>& other)
	{
		if (row != other.column || column != other.row)
			throw 3;

		Matrix res(row, other.column);

		for (int i = 0; i < row; ++i)
			for (int j = 0; j < res.column; ++j)
				for (int k = 0; k < column; ++k)
					res[i][j] = matrix[i][k] * other[k][j];

		*this = res;

		return (*this);
	}

	Matrix<T> operator/(double el) const
	{
		Matrix res(row, column);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				res[i][j] = matrix[i][j] / el;
		return res;
	}

	Matrix<T>& operator/=(double el)
	{
		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				matrix[i][j] /= el;
		return *this;
	}

	Matrix<T> operator*(double el) const
	{
		Matrix res(row, column);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				res[i][j] = matrix[i][j] * el;
		return res;
	}

	Matrix<T>& operator*=(double el)
	{
		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				matrix[i][j] *= el;
		return *this;
	}
	
	friend ostream& operator<<(ostream& stream, const Matrix<T>& M)
	{
		for (int i = 0; i < M.row; i++)
		{
			for (int j = 0; j < M.column; j++)
				stream << M[i][j] << ' ';
			stream << endl;
		}
		stream << endl;

		return stream;
	}

	friend istream& operator>>(istream& stream, Matrix<T>& M)
	{
		for (int i = 0; i < M.row; i++)
			for (int j = 0; j < M.column; j++)
				stream >> M[i][j];

		return stream;
	}

	virtual bool operator==(Matrix<T>& other) const
	{
		if (other.column != column || other.row != row)
			return false;

		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; ++j)
				if (matrix[i][j] != other[i][j])
					return false;
		return true;
	}

	bool operator!=(Matrix<T>& other)
	{
		if (other.column != column || other.row != row)
			return true;

		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; ++j)
				if (matrix[i][j] != other[i][j])
					return true;
		return false;
	}
	
	int get_row() { return row; }

	int get_coll() { return column; }

	virtual void transpon()
	{
		Matrix temp(*this);

		delete[] matrix;
		row = temp.column;
		column = temp.row;

		matrix = new T * [row];
		for (int i = 0; i < row; i++)
			matrix[i] = new T[column];

		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				matrix[i][j] = temp[j][i];
	}
	

};

//template <typename T>
//ostream& operator<<(ostream& stream, const Matrix<T>& M)
//{
//	
//}

//template <typename T>
//istream& operator>>(istream& stream, Matrix<T>& M)
//{
//	
//}

template <typename T>
double Min(Matrix<T>& matrix_)
{
	double min = matrix_[0][0];

	int row = matrix_.get_row();
	int column = matrix_.get_coll();
	for (int i = 1; i < row; i++)
		for (int j = 0; j < column; j++)
			if (min > matrix_[i][j]) min = matrix_[i][j];

	return min;
}

