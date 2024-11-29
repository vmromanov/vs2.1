#pragma once

#include <iostream>

using namespace std;

class Function
{
protected:
	double argument;
public:
	Function() { argument = 0; }

	virtual ~Function() {};

	void SetArg(double arg) { argument = arg; }

	virtual void SetCoeff() = 0;

	virtual double GetValue() = 0;

	virtual const string& GetName() const = 0;
};

class Line : public Function
{
private:
	string name;
	double a;
	double b;
public:
	Line() : name("ax + b") { a = 0; b = 0; }

	~Line() {}

	void SetCoeff() override;

	const string& GetName() const override { return name; }

	double GetValue() override { return a * argument + b; }
};

class Exponent : public Function
{
private:
	string name;

public:
	Exponent() : name("e^x") {;};

	~Exponent() {}

	void SetCoeff() override;

	const string& GetName() const override { return name; }

	double GetValue() override;
};

class Polynomial : public Function
{
private:
	string name;
	double* coefficients;
	size_t size;
public:
	Polynomial() : name("a(n)x^n + ... + a(0)") { coefficients = nullptr; size = 0; }

	~Polynomial() { delete[] coefficients; }

	void SetCoeff() override;

	const string& GetName() const override { return name; }

	double GetValue() override;
};
