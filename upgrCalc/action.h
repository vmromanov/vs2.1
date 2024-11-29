#pragma once

#include "functions.h"
#include <iostream>
#include <iomanip>


class Action
{
public:
	virtual ~Action() { }

	virtual void Operate(Function* func) = 0;
	virtual const string& GetName() = 0;
};

class Calculation : public Action
{
private:
	string name;
public:
	Calculation() : name("Calculation") { }

	~Calculation() {}

	const string& GetName() override { return name; }

	void Operate(Function* func_) override;
};

class Tabulation : public Action
{
private:
	string name;
public:
	Tabulation() : name("Tabulation") {}

	~Tabulation() {}

	const string& GetName() override { return name; }

	void Operate(Function* func) override;
};
