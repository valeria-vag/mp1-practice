#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <iostream>

using namespace std;

class Matrix
{
private:
	int rows, cols;
	double *elements;
public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix&);
	Matrix(double*, int, int);
	~Matrix();

	void Output();
	const Matrix& operator=(const Matrix&); //���������
	Matrix operator+(const Matrix&); //�������� ������
	Matrix operator+(double); //���������� ���������
	Matrix operator-(const Matrix&);
	Matrix operator-(double);
	Matrix operator*(const Matrix&); //��������� �� �������
	Matrix operator*(double); //��������� �� ���������
	double* operator[](int); //��������� ������ ������

	friend istream& operator>>(istream&, Matrix&); //����
	friend ostream& operator<<(ostream &, const Matrix &); //�����
};

class ExceptionSize : exception
{
private:
	const string msg;
public:
	ExceptionSize(string exc)
		: msg(exc)
	{
	}
	const char* what() const { return msg.c_str(); }
};

class ExceptionIdx : exception
{
private:
	const string msg;
public:
	ExceptionIdx(string exc)
		: msg(exc)
	{
	}
	const char* what() const { return msg.c_str(); }
};

#endif