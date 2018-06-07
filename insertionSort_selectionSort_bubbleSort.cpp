#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

void insertionSort(int *array, int size)
{
	for (int i = 1; i < size; ++i)
	{
		int j = i - 1;
		while (array[j] > array[j+1] && j >= 0)
		{
			swap(array[j], array[j+1]);
			--j;
		}
	}
}

void selectionSort(int *arr, int size)
{
	for (int i = 0; i <= size - 2; ++i)
	{
		int min = arr[i];
		int min_index = i;
		for (int j = i + 1; j <= size - 1; ++j)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				min_index = j;
			}
		}
		swap(arr[i], arr[min_index]);
	}
}

void bubbleSort(int *arr, int size)
{
	for (int i = 0; i <= size - 2; ++i)
	{
		for (int j = i + 1; j <= size - 1; ++j)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}


int main()
{
	int size = 100;
	int *arr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = rand()%10 + 1;
	}
	
	insertionSort(arr, size);
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
	
	selectionSort(arr, size);
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
	
	bubbleSort(arr, size);
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
	
	delete[] arr;
	return 0;
}
