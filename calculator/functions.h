#pragma once

#include <iostream>

using namespace std;

class Function
{
protected:
	char* name;
	double argument;
public:
	Function() { name = new char[1];name[0]='\0'; argument = 0; }

	Function(double argument_) { name = new char; name[0] = '\0'; argument = argument_; }

	virtual ~Function() { delete[] name; };

	virtual void Calculate() = 0;

	virtual char* GetName() = 0;
};

class Line : public Function
{
private:
	double a;
	double b;
public:
	Line();

	Line(double args, double a_, double b_);

	~Line() override { ; }

	char* GetName() override { return name; }

	void Calculate() override;
};

class Exponent : public Function
{

public:
	Exponent();

	~Exponent() override { delete[] name; }

	char* GetName() override { return name; }

	void Calculate() override;
};

class Polynom :public Function
{
	double* koef;
public:
	Polynom();

	~Polynom() override

	{
		delete[] koef;
	}

	char* GetName() override { return name; }

	void Calculate() override;
};

class Menu
{
private:
	Function** obj_ptr;

	int GetFunctionIndex(size_t options_amount_);
public:
	Menu() { obj_ptr = nullptr; }

	Menu(Function** func_arr_) { obj_ptr = func_arr_; }

	Function* SelectedFunction();
};

