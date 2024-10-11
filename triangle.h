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
	}

	void point_move(double x_, double y_)
	{
		x += x_;
		y += y_;
	}

	void Print_Coord()
	{
		printf("(%f, %f)", x, y);
	}
};

class Triangle
{
	char* name;
	Point a, b, c;
	double side1, side2, side3;
	static int amount ;

public:

	Triangle()
	{
		char buff[18];
		amount = 1;
		sprintf(buff, "triangle %d", amount);
		++amount;
		side1 = side2 = side3 = 0;
		name = new char[strlen(buff) + 1];
		strcpy(name, buff);
	}

	double Pythagor(Point vertex1_, Point vertex2_)
	{
		return sqrt(pow((vertex1_.Get_x() - vertex2_.Get_x()), 2) + pow((vertex1_.Get_y() - vertex2_.Get_y()), 2));
	}

	Triangle(Point v1, Point v2, Point v3)
	{
		char buff[18];
		amount = 1;
		sprintf(buff, "triangle %d", amount);
		++amount;
		a = v1; b = v2; c = v3;
		side1 = Pythagor(v1, v2);
		side2 = Pythagor(v2, v3);
		side3 = Pythagor(v3, v1);
		name = new char[strlen(buff) + 1];
		strcpy(name, buff);
	}

	~Triangle()
	{
		delete[] name;
	}

	double Area(double side1, double side2, double side3)
	{
		double halfPerimeter = (side1 + side2 + side3) / 2;

		return sqrt(halfPerimeter * (halfPerimeter - side1) * (halfPerimeter - side2) * (halfPerimeter - side3));
	}

	void Move_Triangle(double x_move,double y_move)
	{
		a.point_move(x_move, y_move);
		b.point_move(x_move, y_move);
		c.point_move(x_move, y_move);
	}


};


