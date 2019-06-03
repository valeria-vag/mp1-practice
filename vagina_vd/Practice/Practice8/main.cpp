#include "Matrix.h"
#include <iostream>
#include "conio.h"
using namespace std;

void main()
{
	double a1[3] = { -2, 5, 1 };
	double a2[5] = { 8, 1, 3, 2, 3 };
	double a3[3] = { 4, -1, 2 };
	double a4[6] = { 9, 1, -5, 5, 2, 7 };
	Matrix A(a1, 2, 3);
	Matrix B(a2, 5, 2);
	Matrix C(a3, 2, 3);
	Matrix D(a4, 3, 7);
	Matrix res;

	cout << "  Matrix1\n" << endl;
	A.Output();
	cout << "  Matrix2\n" << endl;
	B.Output();
	cout << "  Matrix3\n" << endl;
	C.Output();
	cout << "  Matrix3\n" << endl;
	D.Output();
	try
	{
		cout << " D + B\n" << endl;
		cout << D + B;

		cout << " A + C = ";
		cout << A + C << endl;

		cout << " B + 3 = ";
		cout << B + 3;
	}
	catch (ExceptionSize& exc)
	{
		cerr << exc.what() << endl;
	}

	try
	{
		cout << "  D - B\n" << endl;
		res = (D - B);
		res.Output();

		cout << "  A * C\n" << endl;
		res = (A * C);
		res.Output();

		cout << "  D * C = ";
		res = (D * C);
		res.Output();
	}
	catch (ExceptionSize& exc)
	{
		cerr << exc.what() << endl;
	}
	
	cout << "  B * 4\n" << endl;
	res = B * 4;
	res.Output();
	cout << "  C - 5\n" << endl;
	res = (C - 5);
	res.Output();

	try
	{
		cout << " 3rd row of A:  " << A[3] << endl;
		cout << "  C[2][2] =  " << C[1][1] << endl;
		cout << "  C[32][25] =  " << C[32][25] << endl;
	}
	catch (ExceptionIdx& exc)
	{
		cerr << exc.what() << endl;
	}
}