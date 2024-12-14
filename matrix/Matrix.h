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

	friend ifstream& operator>>(ifstream& stream, Matrix& matrix);

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

template <typename InputType, typename OutputType>
OutputType** calculateNeighborAverages(int size, InputType** inputMatrix) {
    OutputType** outputMatrix = new OutputType * [size];
    for (int i = 0; i < size; ++i) {
        outputMatrix[i] = new OutputType[size];
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            OutputType neighborSum = 0;
            int count = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < size && nj >= 0 && nj < size) {
                        neighborSum += inputMatrix[ni][nj];
                        ++count;
                    }
                }
            }
            outputMatrix[i][j] = neighborSum / count;
        }
    }

    return outputMatrix;
}
