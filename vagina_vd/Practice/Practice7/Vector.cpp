#include <iostream>
#include "Vector.h"
#include <exception>

using namespace std;

void Vector::Create(double* tmp)
{
	for (int i = 0; i < size; i++)
		elements[i] = tmp[i];
}

void Vector::Output()
{
	for (int i = 0; i < size; i++)
	{
		cout << elements[i] << " ";
	}
	cout << "\n";
}

Vector::Vector(int _size)
{
	if (_size <= 0)
		throw ExceptionSize("Not correct size of vector!");
	size = _size;
	elements = new double[size];
}

Vector::~Vector()
{
	size = 0;
	delete[] elements;
}

//конструктор копирования
Vector::Vector(Vector & tmp)
{
	size = tmp.size;
	elements = new double[size];
	for (int i = 0; i < size; i++)
		elements[i] = tmp.elements[i];
}

const Vector& Vector::operator=(const Vector& x)
{
	if (this == &x)
		return *this;
	delete[]elements;
	size = x.size;
	elements = new double[size];
	for (int i = 0; i < size; i++)
		elements[i] = x.elements[i];
	return *this;
}

Vector Vector::operator+(const Vector & x)
{
	if (size != x.size)
		throw ExceptionSize("Values are not equal");
	Vector tmp(size);
	for (int i = 0; i < size; i++)
		tmp.elements[i] = elements[i] + x.elements[i];
	return tmp;
}

Vector Vector::operator+(double num)
{
	Vector tmp(size);
	for (int i = 0; i < size; i++)
		tmp.elements[i] = elements[i] + num;
	return tmp;
}

Vector Vector::operator-(const Vector & x)
{
	if (size != x.size)
		throw ExceptionSize("Values are not equal");
	Vector tmp(size);
	for (int i = 0; i < size; i++)
		tmp.elements[i] = elements[i] - x.elements[i];
	return tmp;
}

Vector Vector::operator-(double num)
{
	Vector tmp(size);
	for (int i = 0; i < size; i++)
		tmp.elements[i] = elements[i] - num;
	return tmp;
}

Vector Vector::operator*(const Vector & x)
{
	if (size != x.size)
		throw ExceptionSize("Values are not equal");
	Vector tmp(size);
	for (int i = 0; i < size; i++)
		tmp.elements[i] = elements[i] * x.elements[i];
	return tmp;
}

Vector Vector::operator*(double num)
{
	Vector tmp(size);
	for (int i = 0; i < size; i++)
		tmp.elements[i] = num * elements[i];
	return tmp;
}

Vector Vector::operator/(double num) 
{
	if (num == 0)
		throw ExceptionSize("Num isn't zero!");
	Vector tmp(size);
	for (int i = 0; i < size; i++)
		tmp.elements[i] = elements[i] / num;
	return tmp;
}

Vector& Vector::operator+=(double num)
{
	for (int i = 0; i < size; i++)
		elements[i] += num;
	return *this;
}

Vector Vector::operator+=(const Vector& v)
{
	if (v.size != size)
		throw ExceptionSize("Not correct size of vector!");
	for (int i = 0; i < size; i++)
		elements[i] += v.elements[i];
	return *this;
}

Vector& Vector::operator-=(double num)
{
	for (int i = 0; i < size; i++)
		elements[i] -= num;
	return *this;
}

Vector Vector::operator-=(const Vector& v)
{
	if (v.size != size)
		throw ExceptionSize("Not correct size of vector!");
	for (int i = 0; i < size; i++)
		elements[i] -= v.elements[i];
	return *this;
}

Vector& Vector::operator*=(double num)
{
	for (int i = 0; i < size; i++)
		elements[i] *= num;
	return *this;
}

double Vector::Lenght() const
{
	float lenght = 0;
	for (int i = 0; i < size; i++)
		lenght += elements[i] * elements[i];
	lenght = sqrt(lenght);
	return lenght;
}

double& Vector::operator[](int idx)
{
	if ((idx < 0) || (idx >= size))
		throw ExceptionIdx("Not correct index");
	return elements[idx];
}

const double& Vector::operator[](int index) const
{
	if ((index < 0) || (index >= size))
		throw ExceptionIdx("Not correct index");
	return elements[index];
}

void* Vector::operator new(size_t Size)
{
	void* tmp = malloc(Size);
	if (tmp == NULL)
		throw("Empty vector!");
	return tmp;
}

void Vector::operator delete(void* tmp)
{
	delete (Vector*)tmp;
}

ostream & operator<<(ostream & out, const Vector & tmp)
{
	cout << "( ";
	for (int i = 0; i < tmp.size; i++)
		out << tmp.elements[i] << " ";
	cout << ")";
	return out;
};