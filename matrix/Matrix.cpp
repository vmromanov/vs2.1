#include "Matrix.h"

Matrix::Matrix(int r, int col)
{
	{
		if (r < 0 || col < 0)
			throw 1;
		row = r; column = col;
		matrix = new double* [row];
		for (int i = 0; i < row; ++i)
			matrix[i] = new double[column];
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < column; ++j)
			{
				matrix[i][j] = 0.0;
			}
	}
}

Matrix::Matrix(const Matrix& other)
{
	row = other.row;
	column = other.column;
	matrix = new double* [row];
	for (int i = 0; i < row; ++i)
		matrix[i] = new double[column];

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
		{
			matrix[i][j] = other.matrix[i][j];
		}
}

Matrix::~Matrix()
{
	for (int i = 0; i < row; ++i)
		delete[] matrix[i];
	delete[] matrix;
}

void Matrix::input()
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			if (!scanf_s("%lf", &matrix[i][j])) throw 4;
}

void Matrix::transpon()
{
	Matrix temp(*this);

	delete[] matrix;
	row = temp.column;
	column = temp.row;

	matrix = new double* [row];
	for (int i = 0; i < row; i++)
		matrix[i] = new double[column];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matrix[i][j] = temp[j][i];
}



double* Matrix::operator[](int i)
{
	if (i<0 || i>=row) throw 4;

	return matrix[i];
}

double* Matrix::operator[](int i) const
{
	if (i < 0 || i >= row) throw 4;

	return matrix[i];
}

Matrix& Matrix::operator=(Matrix& other)
{
	if (row != other.row || column != other.column)
	{
		delete[] matrix;
		row = other.row;
		column = other.column;
		matrix = new double* [row];
		for (int i = 0; i < row; i++)
			matrix[i] = new double[column];
	}

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matrix[i][j] = other[i][j];

	return *this;
}

Matrix& Matrix::operator+(Matrix& other) const
{
	if (row != other.row || column != other.column)
		throw 2;

	Matrix res(row, column);
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			res.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
	return res;
}

Matrix& Matrix::operator+=(Matrix& other)
{
	if (row != other.row || column != other.column)
		throw 2;

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			matrix[i][j] +=other.matrix[i][j];

	return *this;
}

Matrix& Matrix::operator-(Matrix& other) const
{
	if (row != other.row || column != other.column)
		throw 2;

	Matrix res(row, column);
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			res.matrix[i][j] = matrix[i][j] - other[i][j];
	return res;
}

Matrix& Matrix::operator-=(Matrix& other)
{
	if (row != other.row || column != other.column)
		throw 2;

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			matrix[i][j] -= other[i][j];

	return *this;
}

Matrix& Matrix::operator*(Matrix& other) const
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

Matrix Matrix::operator*=(Matrix& other) 
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

Matrix& Matrix::operator*(double el) const
{
	Matrix res(row, column);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			res[i][j] = matrix[i][j] * el;
	return res;
}

Matrix& Matrix::operator*=(double el)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matrix[i][j] *= el;
	return *this;
}

Matrix& Matrix::operator/(double el) const
{
	Matrix res(row, column);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			res[i][j] = matrix[i][j] / el;
	return res;
}

Matrix& Matrix::operator/=(double el)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matrix[i][j] /= el;
	return *this;
}

bool Matrix::operator==(Matrix& other) const
{
	if (other.column != column || other.row != row)
		return false;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; ++j)
			if (matrix[i][j] != other[i][j])
				return false;
	return true;
}

bool Matrix::operator!=(Matrix& other)
{
	if (other.column != column || other.row != row)
		return true;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; ++j)
			if (matrix[i][j] != other[i][j])
				return true;
	return false;
}

ostream& operator<<(ostream& stream, const Matrix& M)
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

istream& operator>>(istream& stream, Matrix& M)
{
	for (int i = 0; i < M.row; i++)
		for (int j = 0; j < M.column; j++)
			stream >> M[i][j];

	return stream;
}

void Matrix::set_el(double el, int r, int coll)
{
	if (r < 0 || r >= row || coll < 0 || coll >= column)
		throw 1;
	matrix[r][coll] = el;
}

double Matrix::get_el(int r, int c) const
{
	if (r < 0 || r >= row || c < 0 || c >= column)
		throw 1;
	return matrix[r][c];
}

void Matrix::print()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			std::cout << matrix[i][j]<<' ';
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

double Min(Matrix& matrix_)
{
	double min = matrix_[0][0];

	int row = matrix_.get_row();
	int column = matrix_.get_coll();
	for (int i = 1; i < row; i++)
		for (int j = 0; j < column; j++)
			if (min > matrix_[i][j]) min = matrix_[i][j];

	return min;
}