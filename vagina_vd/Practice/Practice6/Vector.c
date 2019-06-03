#include "Vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

Vector MemAlloc(int size) {
	Vector v;
	v.size = size;
	v.elements = (float*)malloc(sizeof(float) * v.size);
	for (int i = 0; i < size; i++)
		v.elements[i] = 0;
	return v;
}

Vector Create() {
	Vector v;
	int _size;
	printf("Enter size of vector: ");
	scanf_s("%d", &_size);
	v.size = _size;
	v.elements = (float*)malloc(sizeof(float)*v.size);
	printf("Enter elements of vector: \n");
	for (int i = 0; i < _size; i++)
		scanf_s("%d", &(v.elements[i]));
	return v;
}

//удаление вектора
void Delete(Vector v) {
	v.size = 0;
}

//Сложение 
Vector Plus(Vector v1, Vector v2) {
	Vector v;
	v = MemAlloc(v1.size);
	if (v1.size != v2.size)
	{
		printf("Vectors have different sizes\n");
		return v;
	}
	else
		for (int i = 0; i < v1.size; i++)
			v.elements[i] = v1.elements[i] + v2.elements[i];
	return v;
}

//Вычитание 
Vector Minus(Vector v1, Vector v2) {
	Vector v;
	v = MemAlloc(v1.size);
	if (v1.size != v2.size)
	{
		printf("Vectors have different sizes\n");
		return v;
	}
	else
		for (int i = 0; i < v1.size; i++)
			v.elements[i] = v1.elements[i] - v2.elements[i];
	return v;
}

//длина вектора
float Length(Vector v)
{
	float length = 0;
	for (int i = 0; i < v.size; i++)
		length += (v.elements[i] * v.elements[i]);
	length = sqrt(length);
	return length;
}

//умножение на число
Vector MultiplyNum(Vector v, float num) {
	Vector V;
	V = MemAlloc(v.size);
	for (int i = 0; i < v.size; i++)
		V.elements[i] = v.elements[i] * num;
	return V;
}

//скалярное произведение векторов
Vector Multiply(Vector v1, Vector v2)
{
	Vector v;

	v = MemAlloc(v1.size);
	if (v1.size != v2.size)
	{
		printf("Vectors have different sizes\n");
		return v;
	}
	for (int i = 0; i < v.size; i++)
		v.elements[i] = v1.elements[i] * v2.elements[i];
	return v;
}

//угол между векторами
float Corner(Vector v1, Vector v2)
{
	float corner, tmp = 0;
	if (v1.size != v2.size)
	{
		printf("Vectors have different sizes\n");
		return 0;
	}
	for (int i = 0; i < v1.size; i++)
		tmp += v1.elements[i] * v2.elements[i]; //скалярное произведение
	corner = tmp / (Length(v1) * Length(v2));
	corner = acos(corner) * 180 / PI;
	if (corner > 90) corner = 180 - corner;
	return corner;
}

void Output(Vector v)
{
	if (v.size == 0)
		printf("Vector is empty\n");
	else
	{
		printf("( ");
		for (int i = 0; i < v.size; i++)
			printf("%d ", v.elements[i]);
		printf(")\n");
	}
};
