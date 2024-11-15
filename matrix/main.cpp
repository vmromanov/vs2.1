#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include "Sq_matrix.h"
using namespace std;




int main()
{
	Sq_matrix A(2);
	Sq_matrix C(2);
	Sq_matrix B(3);
	cin >> A >> C >> B;
	cout << endl;
	cout <<"A:\n" << A <<"B:\n"<< B<<"C:\n"<<C;
	cout <<"A*B:\n" << (A * C);
	cout << "A determ:" << A.Determinant() << endl;
	cout << "max_from diag:";
	Max_from_Diagonals(B).Print_vector();
	cout << "min elem in A:" << Min(A);










	return 0;
}