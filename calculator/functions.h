#pragma once

#include <iostream>

using namespace std;

class Function
{
protected:
	char* name;
	double argument;
public:
	Function(double argument_ = 0) { name[0] = '\0'; argument = argument_; }

	virtual ~Function() {};

	virtual void Calculate() = 0;

	virtual char* GetName() = 0;
};

class Line : protected Function
{
private:
	double a;
	double b;
public:
	Line(double a_ = 0, double b_ = 0, double args);

	~Line() override { delete[] name; }

	char* GetName() override { return name; }

	void Calculate() override;
};

class Exponent : protected Function
{
private:
	double eps;

public:
	Exponent(double argument_ = 0);

	~Exponent() override { delete[] name; }

	char* GetName() override { return name; }

	void Calculate() override;
};

class Polynom :protected Function
{
	double* koef;
	int size;
public:
	Polynom(double arg = 0);

	~Polynom() override
	{
		delete[] name;
		delete[] koef;
	}

	char* GetName() override { return name; }

	void Calculate() override;
};

class Menu
{
private:
	Function** obj_ptr;
	size_t options_amount;

	int SelectItem(size_t options_amount_);
public:
	Menu()
	{
		options_amount = 3;

		Line line_function;
		Exponent exponent_function;

		obj_ptr = new Function * [3];
	}

	Function* SelectedFunction()
	{
		int option = 0;

		cout << "Which function do you want to use?" << endl << endl;

		for (size_t i = 0; i < options_amount - 1; ++i)
			cout << i + 1 << ". " << obj_ptr[i]->GetName() << endl;

		cout << options_amount << ". Exit" << endl << "-> ";

		return obj_ptr[SelectItem(options_amount) - 1];
	}
};

