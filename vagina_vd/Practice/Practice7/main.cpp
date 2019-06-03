#include "Vector.h"
#include <iostream>
#include <exception>
#include <conio.h>

using namespace std;

void main()
{

	Vector v1(3);
	Vector v2(5);
	Vector v3(3);
	Vector res(5);

	double a1[3] = { -2, 5, 1 };
	double a2[5] = { 8, 1, 3, 2, 3 };
	double a3[3] = { 4, -1, 2 };

	v1.Create(a1);
	v2.Create(a2);
	v3.Create(a3);

	cout << "  v1 = ";
	v1.Output();
	cout << "  v2 = ";
	v2.Output();
	cout << "  v3 = ";
	v3.Output();
	
	cout << "\n  v1 + 3 = " << v1 + 3;
	cout << "\n  v3 - 7 = " << v3 - 7;
    cout << "\n  v2 * 2 = " << v2 * 2;
	cout << "\n  v3 / 4 = " << v3 / 4;

    res = v1.Lenght();
    cout << "\n\n  Lenght of v1 = " << res;
    res = v2.Lenght();
    cout << "\n  Lenght of v2 = " << res;
    res = v3.Lenght();
    cout << "\n  Lenght of v3 = " << res;

    try
    {
        cout << "\n\n  v1 + v2 = ";
        cout << v1 + v2;
        cout << "\n  v1 + v3 = ";
        cout << v1 + v3;
    }
    catch (ExceptionSize& exc)
    {
        cerr << exc.what() << endl;
    }

    try
    {
        cout << "\n  v1 - v2 = ";
        cout << v1 - v2;
		cout << "\n  v2 - v3 = ";
		cout << v2 - v3;
    }
    catch(ExceptionSize& exc)
    {
        cerr << exc.what() << endl;
    }

	try
	{
		cout << "\n  v1 * v2 = ";
		cout << v1 * v2;
		cout << "\n  v2 * v3 = ";
		cout << v2 * v3;
	}
	catch (ExceptionSize& exc)
	{
		cerr << exc.what() << endl;
	}

	try
	{
		cout << "\n  v1 += 2 = ";
		cout << v1 += 2;

		cout << "\n  v2 -= 3 = ";
		cout << v2 -= 3;

		cout << "\n  v3 *= 4 = ";
		cout << v3 *= 4;

		cout << "\n  v2 /= 5 = ";
		cout << v2 /= 5;
	}
	catch (ExceptionSize& exc)
	{
		cerr << exc.what() << endl;
	}

    try 
    {
        cout << "\n  v1[5] = " << v1[5];
        cout << "\n  v2[2] = " << v2[2];
        cout << "\n  v3[0] = " << v3[0];
    }
    catch (ExceptionIdx& exc)
    {
        cerr << exc.what() << endl;
    }
}
}