#pragma once


class sotrudnik
{
private:
	char* name;
	int age;
	float sal;
	char data[11];
public:
	
	sotrudnik();

	sotrudnik(int n);

	sotrudnik(const sotrudnik& b);
	
	const sotrudnik& operator = (const sotrudnik& b);

	~sotrudnik();
	
	void Set_Name(char* s);

	void Set_Age(int age1);
	
	void Set_sal(float s);
	
	void Set_Data(char* s);
	
	char* Get_Name();
	
	int Get_Age();
	
	float Get_Sal();
	
	char* Get_Data();
	
	void Print();
	
	void Vvod();
	
	bool siv(char* s);
};

int Sozd_f(const char* name_file, int& k, sotrudnik* a);


float request1(sotrudnik* arr, int size, int& k, char** Fio_25, int year);

