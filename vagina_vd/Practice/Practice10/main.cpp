#include "Container.h"
#include "ContainerSpecial.h"
#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
	Container<int, 10> C1;
	int c1[3] = { 5, 21, 3 };
	C1.Create(c1, 3);

	try
	{
		cout << "   -TEST#1-" << endl << "  Container: ";
		cout << C1 << endl;

		cout << "\n  Add 2 elements";
		C1.Add(9);
		C1.Add(25);
		cout << C1 << endl;

		cout << "\n  Find for item 9, index = " << C1.Find(9) << endl;
		cout << "\n  Container[2] = " << C1[2] << endl;
		cout << "\n  Add 5 new elements";
		for (int i = 0; i < 5; i++)
		{
			C1.Add(i + 1);
			cout << C1 << endl;
		}
		cout << "\n Add a 1 new element\n";
		C1.Add(100);
	}
	catch (Exception_full& e)
	{
		cerr << e.what() << endl;
	}
	try
	{
		cout << "\n  Delete all elements\n";
		int k = 0;
		while (C1.GetCount() != 0)
			C1.Delete(C1[k]);
	}
	catch (Exception_emp& e)
	{
		cerr << e.what() << endl;
	}

	int* a[5];
	int b[5] = { 2, 10, 0, 8, 95 };
	for (int i = 0; i < 5; i++)
		a[i] = &(b[i]);

	Container<int*, 10> C2(a, 5);
	Container<int*, 10> C3(C2);

	cout << "   -TEST#2-" << endl;
	cout << "  Container #1: ";
	C2.Print();
	cout << "  Copied Container #2:  ";
	C3.Print();

	int tmp = 25;
	int* itmp = &tmp;
	cout << "  Container #1 + new point";
	C2.Add(itmp);
	C2.Print();

	try
	{
		cout << "  Print Container #1[11] ";
		cout << "\n  " << C2[11] << endl;
	}
	catch (Exception_ind& e)
	{
		cerr << e.what() << endl;
	}


	system("pause");
}