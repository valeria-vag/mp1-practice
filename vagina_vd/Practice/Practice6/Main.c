#include "Vector.h"
#include <stdio.h>

void main() {
	Vector v1, v2, v3, res;

	v1 = Create();
	printf("v1 = ");
	Output(v1);
	printf("\n");
	v2 = Create();
	printf("v2 = ");
	Output(v2);
	printf("\n");
	v3 = Create();
	printf("v3 = ");
	Output(v3);
	printf("\n");

	// Cложение
	printf("v1 + v2\n");
	res = Plus(v1, v2);
	Output(res);
	printf("v2 + v3\n");
	res = Plus(v1, v3);
	Output(res);
	Delete(res);

	// Вычитание
	printf("v1 - v2\n");
	res = Minus(v1, v2);
	Output(res);
	printf("v2 - v3\n");
	res = Minus(v1, v3);
	Output(res);
	Delete(res);

	// Длины
	printf("Length of v1: %.2f\n", Length(v1));
	printf("Length of v2: %.2f\n", Length(v2));

	// Умножение на число
	printf("v1 * 5 \n");
	res = MultiplyNum(v1, 5);
	Output(res);
	printf("v2 * 2 \n");
	res = MultiplyNum(v2, 2);
	Output(res);
	Delete(res);

	// Скалярное произведение
	printf("v1 * v2 \n");
	res = Multiply(v1, v2);
	Output(res);
	printf("v2 * v3 \n");
	res = Multiply(v2, v3);
	Output(res);
	Delete(res);

	// Углы
	printf("Corner between v1 and v2 = %.2f\n", Corner(v1, v2));
	printf("Corner between v2 and v3 = %.2f\n", Corner(v2, v3));
	printf("Corner between v1 and v3 = %.2f\n", Corner(v1, v3));
}