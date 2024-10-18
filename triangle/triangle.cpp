#include "triangle.h"

int Triangle::amount = 1;

Triangle::Triangle() 
{
	char buff[18];
	sprintf(buff, "triangle %d", amount);
	++amount;
	side1 = side2 = side3 = 0;
	name = new char[strlen(buff) + 1];
	strcpy(name, buff);
}

double Triangle::Pythagor(Point& V1, Point& V2)
{
	return sqrt(pow((V1.Get_x() - V2.Get_x()), 2) + pow((V1.Get_y() - V2.Get_y()), 2));
}

Triangle::Triangle(double c1, double c2, double c3, double c4, double c5, double c6)
{
	Point A(c1, c2);
	Point B(c3, c4);
	Point C(c5, c6);

	char buff[18];
	sprintf(buff, "triangle %d", amount);
	++amount;

	a = A; b = B; c = C;
	side1 = Pythagor(a, b);
	side2 = Pythagor(b, c);
	side3 = Pythagor(c, a);

	name = new char[strlen(buff) + 1];
	strcpy(name, buff);
}

Triangle::Triangle(Point& v1, Point& v2, Point& v3)
{
	char buff[18];
	sprintf(buff, "triangle %d", amount);
	++amount;
	a = v1; b = v2; c = v3;
	side1 = Pythagor(v1, v2);
	side2 = Pythagor(v2, v3);
	side3 = Pythagor(v3, v1);
	name = new char[strlen(buff) + 1];
	strcpy(name, buff);
}

void Triangle::setcord(Point& A, Point& B, Point& C)
{
	a = A; b = B; c = C;
	side1 = Pythagor(a, b);
	side2 = Pythagor(b, c);
	side3 = Pythagor(c, a);
}

double Triangle::Area()
{
	double halfPerimeter = (side1 + side2 + side3) / 2;

	return sqrt(halfPerimeter * (halfPerimeter - side1) * (halfPerimeter - side2) * (halfPerimeter - side3));
}

double AREA(Triangle& x)
{
	double halfPerimeter = (x.getside1() + x.getside2() + x.getside3()) / 2;

	return sqrt(halfPerimeter * (halfPerimeter - x.getside1()) * (halfPerimeter - x.getside2()) * (halfPerimeter - x.getside3()));
}

void Triangle::Move_Triangle(double x_move, double y_move)
{
	a.point_move(x_move, y_move);
	b.point_move(x_move, y_move);
	c.point_move(x_move, y_move);
}

void Triangle::show()
{
	printf("%s:", name);
	a.Print_Coord(); b.Print_Coord(); c.Print_Coord();
	printf("\n");
}

void Triangle::show_area_sides()
{
	double s = Area();
	printf("Area: %f\n", s);
	printf("side1: %f\n", side1);
	printf("side2: %f\n", side2);
	printf("side3: %f\n", side3);
}

bool Triangle::operator>(Triangle& other)
{
	if (this->Area() > other.Area())
	{
		return true;
	}
	return false;
}

Triangle& Triangle::operator= (Triangle& other)
{
	a = other.a;
	b = other.b;
	c = other.c;
	side1 = other.side1;
	side2 = other.side2;
	side3 = other.side3;
	delete name;
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	return *this;
}

bool Triangle::is_inTriangle(Point& x)
{
	double x1, x2, x3, y1, y2, y3, x0, y0;
	x1 = a.Get_x(); x2 = b.Get_x(); x3 = c.Get_x();
	y1 = a.Get_y(); y2 = b.Get_y(); y3 = c.Get_y();
	x0 = x.Get_x(); y0 = x.Get_y();
	double area0, area1, area2, area3;
	Triangle A(a, b, x);
	Triangle B(b, c, x);
	Triangle C(c, a, x);

	area0 = Area();
	area1 = AREA(A);
	area2 = AREA(B);
	area3 = AREA(C);

	double resArea = area1 + area2 + area3;

	if ((resArea <= area0 + 0.00001 && resArea > area0) || (resArea <= area0 && resArea > area0 - 0.00001))
		return true;
	return false;
}

bool Triangle::is_inTriangle(Triangle& other)
{
	if (is_inTriangle(other.a) && is_inTriangle(other.b) && is_inTriangle(other.c)) return true;
	return false;
}

bool Triangle::is_in_triangle(Point& x)
{
	double x1, x2, x3, y1, y2, y3, x0, y0;
	x1 = a.Get_x(); x2 = b.Get_x(); x3 = c.Get_x();
	y1 = a.Get_y(); y2 = b.Get_y(); y3 = c.Get_y();
	x0 = x.Get_x(); y0 = x.Get_y();
	double sign1 = (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
	double sign2 = (x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0);
	double sign3 = (x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0);

	if (sign1 > 0)sign1 = 1;
	if (sign2 > 0)sign2 = 1;
	if (sign2 > 0)sign3 = 1;
	if (sign1 < 0)sign1 = -1;
	if (sign2 < 0)sign2 = -1;
	if (sign3 < 0)sign3 = -1;

	if (sign1 == sign2 && sign2 == sign3)return true;
	
	if (sign1 == 0 && sign2 == sign3)return true;
	if (sign2 == 0 && sign1 == sign3) return true;
	if (sign3 == 0 && sign2 == sign1)return true;

	if (sign1 == 0 && sign2 == 0)return true;
	if (sign2 == 0 && sign3 == 0)return true;
	if (sign3 == 0 && sign1 == 0)return true;

	return false;
}

bool Triangle::is_contains(Triangle& other)
{
	if (is_in_triangle(other.a) && (is_in_triangle(other.b)) && (is_in_triangle(other.c))) return true;
	return false;
}