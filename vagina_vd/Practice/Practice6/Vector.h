#ifndef __VECTOR_H_
#define __VECTOR_H_

typedef struct {
    float *elements;
    int size;
} Vector;

Vector MemAlloc(int size);
Vector Create();
void Delete(Vector v);
Vector Plus(Vector v1, Vector v2);
Vector Minus(Vector v1, Vector v2);
float Length(Vector v);
Vector MultiplyNum(Vector v, float num);
Vector Multiply(Vector v1, Vector v2);
float Corner(Vector v1, Vector v2);
void Output(Vector v);

#endif