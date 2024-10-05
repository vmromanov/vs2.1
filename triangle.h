#pragma once

class Point
{
	double x;
	double y;
public:
	Point()
	{
		x = 0.0;
		y = 0.0;
	}

	Point(double a, double b)
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

};

class Triangle
{
	Point a;
	Point b;
	Point c;
	double side1;
	double side2;
	double side3;

public:

	Triangle()
	{
		a.set_point(0.0, 0.0);
		b.set_point(0.0, 0.0);
		c.set_point(0.0, 0.0);
		side1 = side2 = side3 = 0;
	}


};


