#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#include <iostream>

using namespace std;

template <typename T, int maxSize>
class Container
{
private:
	T* arr;
	int count;
public:
	Container();
	Container(int);
	Container(const Container&); //конструктор копирования 
	~Container();

	void Create(const T* _Arr, int _count);
	bool IsFull()const;
	bool IsEmpty()const;
	int Find(const T)const;
	void Add(const T);
	void DeleteIdx(int);
	void DeleteEl(T);
	void Print() const;

	T operator[](int) const;
	T& operator[](int);
};

template <typename T, int maxSize>
Container<T, maxSize>::Container() {
	count = 0;
	arr = new T[maxSize];
}

template <typename T, int maxSize>
Container<T, maxSize>::Container(int _count) {
	arr = new T[maxSize];
	count = _count;
	for (int i = 0; i < count; i++)
		arr[i] = i;
}

template <typename T, int maxSize>
Container <T, maxSize>::Container(const Container<T, maxSize>&c) {
	count = c.count;
	arr = new T[count];
	for (int i = 0; i < count; i++)
		arr[i] = c.arr[i];
}

template <typename T, int maxSize>
Container<T, maxSize>::~Container() {
	count = 0;
	arr = NULL;
}

template <typename T, int maxSize>
void Container<T, maxSize>::Create(const T* _arr, int _count)
{
	count = _count;
	Arr = new T[maxSize];
	memcpy(Arr, _arr, sizeof(T) * count);
}

//Проверка на полноту
template <typename T, int maxSize>
bool Container <T, maxSize>::IsFull()const {
	return(count == maxsize);
}

//Проверка на полноту
template <typename T, int maxSize>
bool Container <T, maxSize>::IsEmpty()const {
	return(count == 0); 
}

//Поиск элемента 
template <typename T, int maxSize>
int Container<T, maxSize>::Find(T el)const {
	if (IsEmpty())
		throw Exception("The Container is empty");
	for (int i = 0; i < count; i++)
		if (arr[i] == el) return i;
}

//Добавление элемента
template <typename T, int maxSize>
void Container<T, maxSize>::Add(const T el) {
    if (IsFull())
        throw Exception("The Container is full"); //исключение
    arr[count] = el;
    count++;
};

//Удаление по индексу
template <typename T, int maxSize>
void Container <T, maxSize>::DeleteIdx(int idx) {
	if (IsEmpty()) /
	{
		throw Exception("The Container is empty");
	}
	arr[idx] = arr[count - 1];
	count--;
};

//Удаление по значению элемента
template <typename T, int maxSize>
void Container <T, maxSize>::DeleteEl(T el) {
	DeleteIdx(Find(el)); 
}

template <typename T, int maxSize>
T Container<T, maxSize>::operator[](int idx)const {
    if ((idx < 0) || (idx > count))
        throw Exception("Not correct index");
    return arr[idx];
}

template <typename T, int maxSize>
T& Container<T, maxSize>::operator[](int idx) {
    if ((idx < 0) || (idx > maxSize))
        throw Exception("Not correct index");
    return arr[idx];
}

template <typename T, int maxSize>
void Container<T, maxSize>::Print()const {
	cout << "\n  ";
	for (int i = 0; i < count; i++)
		cout << arr[i] << " ";
	cout << endl;
}

friend ostream& operator<<(ostream& os, const Container& _cont)
{
	os << "( ";
	for (int i = 0; i < _cont.count; i++)
		os << _cont[i] << " ";
	os << ")";
	return os;
}
};

class ExceptionFind : exception
{
private:
	const string msg;
public:
	ExceptionFind(string exc)
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

class ExceptionFull : exception
{
private:
	const string msg;
public:
	ExceptionFull(string exc)
		: msg(exc)
	{
	}
	const char* what() const { return msg.c_str(); }
};

class ExceptionEmp : exception
{
private:
	const string msg;
public:
	ExceptionEmp(string exc)
		: msg(exc)
	{
	}
	const char* what() const { return msg.c_str(); }
};
#endif


