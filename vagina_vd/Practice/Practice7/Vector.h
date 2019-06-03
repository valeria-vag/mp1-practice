#ifndef _VECTOR_H_
#define _VECTOR_H_

typedef struct Vector
{
private:
    int size;
    double* elements;
public:
    Vector(Vector&);
    Vector(int);
    ~Vector();
    void Create(double*);
    void Output();

    const Vector& operator=(const Vector&);
    Vector operator+(const Vector&); //ñëîæåíèå
    Vector operator+(double);
    Vector operator-(const Vector&); //âû÷èòàíèå
    Vector operator-(double);
    Vector operator*(const Vector&); //âåêòîðíîå ïðîèçâåäåíèå
    Vector operator*(double); //óìíîæåíèå íà ÷èñëî
    Vector operator/(double); //äåëåíèå íà ÷èñëî
    
    Vector& operator+=(double);
    Vector operator+=(const Vector&);
    Vector& operator-=(double);
    Vector operator-=(const Vector&);
    Vector& operator*=(double);

    double Lenght() const;

    double& operator[](int);
    const double& operator[](int) const;

    void* operator new(size_t);
    void operator delete(void*);

    friend ostream& operator<<(ostream&, const Vector&);
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
