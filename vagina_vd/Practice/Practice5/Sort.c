#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include <math.h>

#define size_of_str 1000
#define el 2000

void Input(wchar_t **arr_path)
{
	char *path;
	printf("Enter path \n");
	*arr_path = (wchar_t*)malloc(size_of_str * sizeof(wchar_t));
	path = (char*)malloc(size_of_str * sizeof(char));
	fgets(path, size_of_str, stdin);
	path[strlen(path) - 1] = '\0';
	swprintf(*arr_path, size_of_str, L"%hs", path);//преобраз строку из char в wchar_t
	free(path);
}

	int ListDirectoryContents(const wchar_t *sDir, wchar_t ***name_of_file, ULONGLONG **size_of_file)
	{
		int i = 0;
		wchar_t *sPath;
		WIN32_FIND_DATA fdFile;
		HANDLE hFind = NULL;
		sPath = (wchar_t*)malloc(size_of_str * sizeof(wchar_t));
		wsprintf(sPath, L"%s\\*.*", sDir);// куда, по какой маске, откуда
		if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
		{
			//wprintf(L"Path not found: [%s]\n", sDir);
			return -1; //возвращаем на случай, если путь не существует
		}

		do
		{
			if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
				i++;
		} while (FindNextFile(hFind, &fdFile));

		hFind = FindFirstFile(sPath, &fdFile);
		*name_of_file = (wchar_t**)malloc(i * sizeof(wchar_t*));
		*size_of_file = (ULONGLONG*)malloc(i * sizeof(ULONGLONG));
		i = 0;

		do
		{
			if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
				//первый файл возвращ ., а послед найденные файлы будут возвращ ..
			{
				ULONGLONG fsize = fdFile.nFileSizeHigh;
				fsize <<= sizeof(fdFile.nFileSizeHigh) * 8;
				fsize |= fdFile.nFileSizeLow;

				(*name_of_file)[i] = (wchar_t*)malloc(size_of_str * sizeof(wchar_t));
				(*size_of_file)[i] = fsize;
				wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
				wsprintf((*name_of_file)[i], L"%s", sPath);
				i++;
			}
		} while (FindNextFile(hFind, &fdFile));
		FindClose(hFind);
		free(sPath);
		return i; //вернуть кол-во файлов
	}

	void ChooseSort(ULONGLONG *size_of_file, int *arr_ind, int kolvo_f)
	{
		int i, j, tmp;
		ULONGLONG min, min_ind;
		for (i = 0; i < kolvo_f; i++)
		{
			min_ind = i;
			for (j = i + 1; j < kolvo_f; j++)
			{
				if (size_of_file[arr_ind[j]] < size_of_file[arr_ind[min_ind]])
					min_ind = j;
			}
			tmp = arr_ind[min_ind];
			arr_ind[min_ind] = arr_ind[i];
			arr_ind[i] = tmp;
		}
	}

	void InsertSort(ULONGLONG *size_of_file, int *arr_ind, int kolvo_f) 
	{
		int i, j, tmp;
		for (i = 1; i < kolvo_f; i++)
		{
			tmp = arr_ind[i];
			j = i - 1;
			while ((j >= 0) && (size_of_file[arr_ind[j]] > size_of_file[tmp])) 
			{
			arr_ind[j + 1] = arr_ind[j];
			arr_ind[j] = tmp;
			j--;
			}
		}
	}
	
	void BubbleSort(ULONGLONG *size_of_file, int *arr_ind, int kolvo_f)
	{
		int i, j, tmp;
		for (i = 0; i < kolvo_f; i++)
		{
			for (j = 1; j < kolvo_f - i; j++)
			{
				if (size_of_file[arr_ind[j - 1]] > size_of_file[arr_ind[j]]) 
				{
					tmp = arr_ind[j];
					arr_ind[j] = arr_ind[j - 1];
					arr_ind[j - 1] = tmp;
				}
			}
		}
	}
	
	int CountingSort(ULONGLONG *size_of_file, int kolvo_f, int *idx)
	{
		int *count = (int*)malloc(el * sizeof(int));
		int i, j, id = 0, idel = 0;
		int del = 0, min, max, pos = 0;

		min = size_of_file[0];
		max = size_of_file[0];

		for (i = 0; i < kolvo_f; i++)
		{
			if ((size_of_file[i]) < min)
				min = size_of_file[i];
			if ((size_of_file[i]) > max)
				max = size_of_file[i];
		}

		del = max - min + 1;
		idel = (int)del;

		for (i = 0; i < kolvo_f; i++)
			if (size_of_file[i] > el)
				return -1;

		for (i = 0; i < idel; i++)
		{
			if (count[i] > 0)
			{
				pos = 0;
				for (j = 0; j < count[i]; j++)
				{
					while (size_of_file[pos] != i)
						pos++;
					idx[id] = pos;
					pos++;
					id++;
				}
			}
		}

		free(count);
	}

	void QuickSplit(int *arr_ind, ULONGLONG *size_of_file, int *i, int *j, ULONGLONG p)
	{
		int tmp;
		do {
			while (size_of_file[arr_ind[(*i)]] < p)
				(*i)++;
			while (size_of_file[arr_ind[(*j)]] > p)
				(*j)--;
			if ((*i) <= (*j))
			{
				tmp = arr_ind[(*i)];
				ind[(*i)] = ind[(*j)];
				ind[(*j)] = tmp;
				(*i)++;
				(*j)--;
			}
		} while ((*i) < (*j));
	}

	void QuickSort(ULONGLONG *size_of_file, int *arr_ind, int n1, int n2)
	{
		int mid = (n1 + n2) / 2;
		int i = n1, j = n2;
		quick_split(ind, size, &i, &j, size[ind[mid]]);
		if (j > n1)
			quick_sort(size, ind, n1, j);
		if (i < n2)
			quick_sort(size, ind, i, n2);
	}

	void Merge(ULONGLONG *size_of_file, int lb, int mid, int ub, int *arr_ind)
	{
		int i, j = mid + 1;
		int pos, tmp;
		for (i = lb; ((i < ub) && (j <= ub)); i++)
		{
			if (size_of_file[arr_ind[i]] > size_of_file[arr_ind[j]])
			{
				tmp = arr_ind[j];
				for (pos = j; pos > i; pos--)
					arr_ind[pos] = arr_ind[pos - 1];
				arr_ind[i] = tmp;
				j++;
			}
		}
	}

	void MergeSort(ULONGLONG *size_of_file, int lb, int ub, int *arr_ind)
	{
		int mid;
		if (lb < ub)
		{
			mid = (lb + ub) / 2;
			MergeSort(size_of_file, lb, mid, arr_ind);
			MergeSort(size_of_file, mid + 1, ub, arr_ind);
			Merge(size_of_file, lb, mid, ub, arr_ind);
		}
	}

	void Output(ULONGLONG *size_of_file, int *arr_ind, int kolvo_f, wchar_t **name_of_file)
	{
		int i;
		setlocale(LC_ALL, "Russian");
		WIN32_FIND_DATA fdFile;
		for (i = 0; i < kolvo_f; i++)
			wprintf(L" %d. File: %s Size: %lld bytes\n", i + 1, name_of_file[arr_ind[i]], (*(size_of_file + arr_ind[i])));
	}

	void SelectSort(int *sort)
	{
		int k = 0;
		printf("Sorting types:\n");
		printf("Selection Sort - 1\n");
		printf("Insertion Sort - 2\n");
		printf("Bubblesort - 3\n");
		printf("Counting sort - 4\n");
		printf("Quicksort - 5\n");
		printf("Mergesort - 6\n");

		do
		{
			printf("Choose a sorting:\n");
			scanf("%d", sort);
			if (*sort > 1 || *sort < 6) k = 1;
		} while (k != 1);
	}

	void main()
	{
		int i, sort, ans = 0, k;
		int not_path;
		int *arr_ind;
		int kolvo_f = 0;
		clock_t begin, end;
		double time = 0;
		wchar_t **name_of_file;
		ULONGLONG *size_of_file;
		wchar_t* path;
		
		name_of_file = (wchar_t**)malloc(MAX_PATH * sizeof(wchar_t*));
		size_of_file = (ULONGLONG*)malloc(MAX_PATH * sizeof(ULONGLONG));
		do
		{
			Input(&path);
			kolvo_f = ListDirectoryContents(path, &name_of_file, &size_of_file);
			if (kolvo_f == -1)
				printf("Path not found");
			arr_ind = (int*)malloc(kolvo_f * sizeof(int));
			for (i = 0; i < kolvo_f; i++)
				arr_ind[i] = i;
			if (kolvo_f == 0)
				printf("Files not found");
			SelectSort(&sort);
			switch (sort)
			{
			case(1):
			{

				getchar();
				begin = clock();
				ChooseSort(size_of_file, arr_ind, kolvo_f);
				end = clock();
				Output(size_of_file, arr_ind, kolvo_f, name_of_file);
				break;
			}
			case(2):
			{

				getchar();
				begin = clock();
				InsertSort(size_of_file, arr_ind, kolvo_f);
				end = clock();
				Output(size_of_file, arr_ind, kolvo_f, name_of_file);
				break;
			}
			case(3):
			{

				getchar();
				begin = clock();
				BubbleSort(size_of_file, arr_ind, kolvo_f);
				end = clock();
				Output(size_of_file, arr_ind, kolvo_f, name_of_file);
				break;
			}
			case(4):
			{    
				getchar();
				begin = clock();
				ans = CountingSort(size_of_file, kolvo_f, arr_ind);
				end = clock();
				if (ans == -1)
				{
					printf("  File sizes are too large for this sort, please choose another sort\n");
					break;
				}
				output(arr_ind, kolvo_f, name_of_file, size_of_file);
				break;
          
			}
			case(5):
			{
				getchar();
				begin = clock();
				quick_sort(size_of_file, arr_ind, 0, kolvo_f - 1);
				end = clock();
				output(arr_ind, kolvo_f, name_of_file, size_of_file);
				break;
			
			}
			case(6):
			{
				getchar();
				begin = clock();
				merge_sort(size_of_file, 0, kolvo_f - 1, arr_ind);
				end = clock();
				output(arr_ind, kolvo_f, name_of_file, size_of_file);
				break;			
			}
			}

			time = (float)(end - begin) / CLOCKS_PER_SEC;
			printf("  Sorting time: %.3f cek\n", time);
			for (i = 0; i < kolvo_f; i++)
				free(name_of_file);
			free(size_of_file);
			printf("If you want to do the sorting again, then enter 1");
			printf("To exit, enter 0");
			scanf("%d", &k);
			} while (k != 0);
	}