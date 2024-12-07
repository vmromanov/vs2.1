#pragma once
#include <iostream>
using namespace std;

class Vector
{
   double* elements;
   size_t size;
   size_t capasity;

public:

   Vector(double* element = nullptr, int size = 0);

   Vector(Vector& other_);

   ~Vector();

   Vector operator+(const Vector& other) const;

   Vector& operator=(const Vector& other);

   Vector& operator+=(const Vector& other);

   double operator*(const Vector& other);

   Vector operator&(const Vector& other);

   Vector& operator&=(const Vector& other);

   bool operator==(const Vector& other);

   bool operator!=(const Vector& other);

   bool operator!();

   double& operator[](int index) const;

   double& operator[](int index);

   friend ostream operator<<(ostream stream, Vector v);

   void Push_Back(double el);

   void Print_vector();
};
