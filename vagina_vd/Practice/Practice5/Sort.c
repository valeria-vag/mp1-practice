#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void input(int a[], int n)
{
	int i;
	srand((unsigned int) time(0));
	for (i = 0; i < n; i++)
		a[i] = rand();
}

void output(int a[], int n)
{
	int i;
	for (i = 0; i < n - 1; i++)
		printf("%d", a[i]);
	printf("%d\n", a[n-1]);
}
//+ выбор нужной сортировки (дописать)
void ChooseSort(int a[], int n) //сортировка выбора
{
	int i, min, minidx, j;
	for (i = 0; i < n; i++)
	{
		min = a[i];
		minidx = i;
		for (j = i + 1; j < n; j++)
		{
			if(a[i] < min)
			{ 
				min = a[j];
				minidx = j;
			}
		}
		a[minidx] = a[i];
		a[i] = min;
	}
} 

void InsirtSort(int a[], int n)
{
	int i, j, tmp;
	for (i = 1; i < n; i++)
	{
		tmp = a[i];
		j = i - 1;
		while (j >= 0) && (a[j] > tmp)
		{
			a[i + 1] = a[j];
			a[j] = tmp;
			j--;
		}
	}
}


void main()
{
	int a[N];
	printf("After sorting: \n");
	input(a, N);
	output(a, N);
	ChooseSort(a, N);
	printf("Before sorting: \n");
	output(a, N);
	printf("\n");

}