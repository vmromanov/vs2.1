#include <iostream>
#include "Matrix.h"
#include "Sq_matrix.h"
using namespace std;
int main()
{
	Sq_matrix A(3);
	Matrix U(3);
	
	A.input();
	U.input();
	cout << endl;
	A.print();
	U.print();
	cout << endl;
	A = U;
	Matrix B(U += A);
	U.print();
	B.print();
	B.transpon();
	B.print();

	return 0;
}