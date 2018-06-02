/*
    hackerrank: https://www.hackerrank.com/challenges/array-left-rotation/problem
*/
#include <iostream>
using namespace std;
void rotate(unsigned long long *arr, int size, int amount)
{
	/*
	  0, 1, 2, 3
	  1, 2, 3, 4
	  
	  4, 1, 2, 3
	  (size+idx-amount)%size
	*/
	for(int i = 0; i < size; ++i)
	{
		cout << (size+i-amount)%size+1 << ' ';
	}
}

int main()
{
	int size;
	int d;
	cin >> size >> d;
	unsigned long long arr[size];
	for(int i = 0; i < size; ++i)
	{
		cin >> arr[i];
	}
	rotate(arr, size, -d);
	return 0;
}
