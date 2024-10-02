#pragma once

#include "Sotrudnik.h"
class Baza
{
private:
	sotrudnik* arr;
	int size;
	int amount;
public:
	Baza();

	Baza(int n);

	~Baza();

	int Create_Baza_F(const char* namefile);

	int Basa_Expansion();

	void Print_Baza();

	void Baza_add();

	void Baza_del_el();

	void Baza_correction();

	int Baza_cpy(char* namef);
};

void Main_Menu();

void How_to_edit_menu();

void Employee_Edit_Menu();

int Option_Choose(int options_amount);

