#pragma once

#include <iostream>
#include <math.h>
class Point
{
	double x;
	double y;
public:

	Point(double a = 0, double b = 0)
	{
		x = a;
		y = b;
	}

	void set_x(double a)
	{
		x = a;
	}

	void set_y(double a)
	{
		y = a;
	}

	void set_point(double a, double b)
	{
		x = a;
		y = b;
	}

	double Get_x()
	{
		return x;
	}

	double Get_y()
	{
		return y;
	}

	Point& operator=(Point& other)
	{
		if (&other == this)
			return *this;

		x = other.x;
		y = other.y;

		return *this;
	}

	void point_move(double x_, double y_)
	{
		x += x_;
		y += y_;
	}

	void Print_Coord()
	{
		printf(" (%f, %f) ", x, y);
	}
	// + +=
	Point& operator+(Point& other)
	{
		Point rez;
		rez.x = x + other.x;
		rez.y = y + other.y;
		return rez;
	}

	Point& operator+=(Point& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	

};

class Triangle
{
	char* name;
	Point a, b, c;
	double side1, side2, side3;
	static int amount;

public:
	//> set get
	Triangle();

	Triangle(double c1, double c2, double c3, double c4, double c5, double c6);

	double Pythagor(Point& V1, Point& V2);

	Triangle(Point& v1, Point& v2, Point& v3);

	~Triangle()
	{
		delete[] name;
	}

	double getside1() { return side1; }

	double getside2() { return side2; }

	double getside3() { return side3; }

	char* getname() { return name; }

	void setcord(Point& A, Point& B, Point& C);

	double Area();

	void Move_Triangle(double x_move, double y_move);

	void show();

	void show_area_sides();

	bool operator>(Triangle& other);

	Triangle& operator= (Triangle & other);

	bool is_inTriangle(Point& x); 

	bool is_inTriangle(Triangle& other);  

	bool is_in_triangle(Point& x);

	bool is_contains(Triangle& other);
	// вкл триуг в триуг, 
};



