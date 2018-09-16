/*
hackerrank: https://www.hackerrank.com/challenges/array-left-rotation/problem
hackerrank: https://www.hackerrank.com/challenges/circular-array-rotation/problem (See testcase 4)
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
	amount = amount%size;
	for (int i = 0; i < size; ++i)
	{
		// amount%size is for handling case when amount > size
		// for amount <= size arr[(size + i - amount) % size + 1] will also do
		cout << (size + i - amount) % size + 1 << ' ';
	}
}

int main()
{
	int size;
	int d;
	cin >> size >> d;
	unsigned long long *arr = new unsigned long long[size];
	for (int i = 0; i < size; ++i)
	{
		cin >> arr[i];
	}
	rotate(arr, size, -d);
	delete[] arr;
	return 0;
}
