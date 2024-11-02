#include <iostream>
#include "Matrix.h"
#include "Sq_matrix.h"
using namespace std;




int main()
{
	Sq_matrix A(2);
	Sq_matrix B(2);
	cin >> A >> B;
	cout << endl;
	cout << A  << B ;
	cout << (A * B);


	return 0;
}