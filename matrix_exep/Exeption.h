#pragma once
#include <iostream>
using namespace std;

class B_exeption
{
public:
	virtual ~B_exeption() { ; }
	virtual void print() = 0;
};

class Out_Of_Range :public B_exeption
{
public:
	~Out_Of_Range() { ; }
	void print() { cout << "Error: Index out of range\n"; }
};

class Different_Size :public B_exeption
{
public:
	~Different_Size() { ; }
	void print() { cout << "Error: size missmatch\n"; }
};

class Multiple_exeption :public B_exeption
{
public:
	~Multiple_exeption() { ; }
	void print() { cout << "Error: size mismatch for multiplication\n"; }
};

class Incorrect_Size :public B_exeption
{
public:
	~Incorrect_Size() { ; }
	void print() { cout << "Error: incorrect size entered\n"; }
};

class Input_Error :public B_exeption
{
public:
	~Input_Error() { ; }
	void print() { cout << "Error: input error\n"; }
};

class div_zero :public B_exeption
{
public:
	~div_zero() { ; }
	void print() { cout << "Error: cant divide by 0\n"; }
};

class negative_degree :public B_exeption
{
public:
	~negative_degree() { ; }
	void print() { cout << "Error: raising to a negative degree\n"; }
};