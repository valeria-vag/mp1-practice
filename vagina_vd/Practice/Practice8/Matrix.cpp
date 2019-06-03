#include "Matrix.h"
#include "iostream"
using namespace std;

Matrix::Matrix()
{
    rows = 3;
    cols = 3;
    elements = (double*)malloc(rows * cols * sizeof(double));
    for (int i = 0; i < rows * cols; i++)
        elements[i] = 0;
}

Matrix::Matrix(int _rows, int _cols)
{
    if ((_rows <= 0) || (_cols <= 0))
        throw Exception("Not correct size!");
    rows = _rows;
    cols = _cols;
    elements = (double*)malloc(rows * cols * sizeof(double));
    for (int i = 0; i < rows * cols; i++)
        elements[i] = 0;
} 

Matrix::Matrix(const Matrix& A)
{
    rows = A.rows;
    cols = A.cols;
    elements = (double*)malloc(rows * cols * sizeof(double));
    for (int i = 0; i < rows * cols; i++)
        elements[i] = A.elements[i];
}

Matrix::Matrix(double* _elements, int _rows, int _cols) {
    rows = _rows;
    cols = _cols;
    elements = (double*)malloc(rows * cols * sizeof(double));
    for (int i = 0; i < rows * cols; i++)
        elements[i] = _elements[i];
}

Matrix::~Matrix()
{
    rows = 0;
    cols = 0;
    delete[] elements;
}

const Matrix& Matrix::operator=(const Matrix& A)
{
    if (this == &A)
        return *this;
    rows = A.rows;
    cols = A.cols;
    for (int i = 0; i < rows * cols; i++)
        elements[i] = A.elements[i];
    return *this;
}

Matrix Matrix::operator+(const Matrix& A)
{
//исключения!
    Matrix tmp(rows, cols);
    for (int i = 0; i < (rows * cols); i++)
        tmp.elements[i] += (elements[i] + A.elements[i]);
    return tmp;
}

Matrix Matrix::operator+(double k)
{
    Matrix tmp(rows, cols);
    for (int i = 0; i < rows * cols; i++)
        tmp.elements[i] += (elements[i] + k);
    return tmp;
}

Matrix Matrix::operator-(const Matrix& A)
{
    //исключения!
    Matrix tmp(rows, cols);
    for (int i = 0; i < (rows * cols); i++)
        tmp.elements[i] += (elements[i] - A.elements[i]);
    return tmp;
}

Matrix Matrix::operator-(double k)
{
    Matrix tmp(rows, cols);
    for (int i = 0; i < rows * cols; i++)
        tmp.elements[i] += (elements[i] - k);
    return tmp;
}

Matrix Matrix::operator*(const Matrix& A)
{
    //исключения!
    Matrix tmp(rows, A.cols);
    for (int i = 0; i < rows * A.cols; i++)
        tmp.elements[i] = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < A.cols; j++)
            for (int k = 0; k < cols; k++)
                tmp.elements[i * A.cols + j] +=
                (elements[i * cols + k] * A.elements[k * A.cols + j]);

    return tmp;
}

Matrix Matrix::operator*(double k)
{
    Matrix tmp(rows, cols);
    for (int i = 0; i < rows * cols; i++)
        tmp.elements[i] += (elements[i] * k);
    return tmp;
}

void Matrix::Output()
{
    for (int i = 0; i < rows; i++)
    {
        cout << "|  ";
        for (int j = 0; j < cols; j++)
            cout << elements[i * cols + j] << " ";
        cout << " |\n";
    }
    cout << endl;
}

double* Matrix::operator[](int idx)
{
    //исключения
    return(cols * idx + elements);
}

istream& operator>>(istream &in, Matrix& A)
{
    for (int i = 0; i < (A.rows * A.cols); i++)
        in >> A.elements[i];
    return in;
}

ostream & operator<<(ostream &out, const Matrix& A)
{
    for (int i = 0; i < (A.rows * A.cols); i++)
    {
        out << "  |  ";
        out << A.elements[i] << " ";
        out << " |\n";
        out << endl;
    }
    return out;
}