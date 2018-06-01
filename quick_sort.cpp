#include <iostream>
//#include <algorithm>
using namespace std;

int partition(int *arr, int low, int pivot, int high)
{
	while(low<=high)
	{
		while(arr[low]<pivot)++low;
		while(arr[high]>pivot)--high;
		if(low<=high) 
		{
			swap(arr[low], arr[high]);
			++low;
			--high;
		}
	}
	return low;
}

void quickSortHelper(int *arr, int low, int high)
{
	if(low>=high) return;
	int pivot = arr[(low+high)/2];
	int partitionPoint=partition(arr, low, pivot, high);
	quickSortHelper(arr, low, partitionPoint-1);
	quickSortHelper(arr, partitionPoint, high);
}

void quickSort(int *arr, int size)
{
	quickSortHelper(arr, 0, size-1);
}
int main()
{
	int size = 160;
	int arr[size];
	for(int i = 0; i < size; ++i)
	{
		arr[i] = rand()%10+1;
	}
  quickSort(arr, size);
	for(int i = 0; i < size; ++i)
	{
		cout << arr[i] << ' ';
	}
	return 0;
}
