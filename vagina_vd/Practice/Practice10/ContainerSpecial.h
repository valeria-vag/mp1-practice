#ifndef _CONTAINERSPECIAL_H_
#define _CONTAINERSPECIAL_H_

#include <iostream>
#include "Container.h"
using namespace std;

template <typename T, int maxSize>
class Container<T*, maxSize>
{
private:
    T** arr;
    int count;
public:
    Container();
    Container(T**, int);
    Container(const Container&); 
    ~Container();

    bool IsFull()const;
    bool IsEmpty()const;
    int Find(const T*)const;
    void Add(T*);
    void DeleteIdx(int);
    void DeleteEl(T*);
    void Print() const;

    T operator[](int) const;
    T& operator[](int);
};

template <typename T, int maxSize>
Container<T*, maxSize>::Container() {
    count = 0;
    arr = new T*[maxSize];
};

//конструктор копирования
template <typename T, int maxSize>
Container <T*, maxSize>::Container(const Container <T*, maxSize>& c) {
    count = c.count;
    arr = new T*[count];
    for (int i = 0; i < count; i++)
        arr[i] = new T(*(_arr[i]));
}

template <typename T, int maxSize>
Container<T*, maxSize>::Container(T** _arr, int size) {
    count = size;
    arr = new T[maxsize]
        for (int i = 0; i < count; i++)
            arr[i] = new T(*(_arr[i]));
}

template <typename T, int maxSize> //+ 
Container<T*, maxSize>::~Container() {
    for (int i = 0; i < count; i++)
        delete arr[i];
    delete[] arr;
    count = 0;
}

//Полнота
template <typename T, int maxsize>
bool Container<T*, maxsize>::IsFull() const
{
    return (count == maxsize);
};

template <typename T, int maxsize>
bool Container<T*, maxsize>::IsEmpty() const
{
    return (count == 0);
};

template <typename T, int maxsize>
int Container<T*, maxsize>::Find(const T* tmp) const
{
    if (IsEmpty())
        throw Exception("Container is empty");
    for (int i = 0; i < count; i++)
        if (Arr[i] == tmp)
            return i;
    throw Exception ("The object is not found");
};

template <typename T, int maxsize>
void Container<T*, maxsize>::Add(T* tmp)
{
    if (IsFull())
        throw Exception("Container is full");
    arr[count++] = tmp; //count++?
};

template <typename T, int maxSize>
void Container<T*, maxSize>::DeleteIdx(const int idx)
{
    if (IsEmpty())
        throw Exception("The Container is empty!");
    if ((index < 0) || (index >= count))
        throw Exception("Index is not correct");

    arr[idx] = arr[count - 1];
    count--;
};

template <typename T, int maxSize>
void Container<T*, maxSize>::DeleteEl(T* idx)
{
    DeleteIdx(Find(idx));
};

template <typename T, int maxSize> //+
T Container<T*, maxSize>::operator[](int idx) const {
    if ((idx < 0) || (idx > count))
        throw Exception("Not correct index!");
    return arr[ind];
};

template <typename T, int maxSize> //+
T& Container<T*, maxSize>::operator[](int idx) {
    if ((idx < 0) || (ind > maxSize))
        throw Exception("Not correct index!");
    return *arr[ind];
}

template <typename T, int maxSize> //+
void Container<T*, maxSize>::Print()const {
    cout << "\n  ";
    for (int i = 0; i < count; i++)
        cout << arr[i] << " ";
    cout << endl;
}
#endif