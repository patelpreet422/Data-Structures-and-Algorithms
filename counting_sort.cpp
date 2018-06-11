#include <iostream>
#include <algorithm>
void counting_sort(int *arr, int size)
{
    int max_e = *std::max_element(arr, arr+size);
    int *aux_arr = new int[max_e+1];
    for(int i = 0; i < size; ++i)
    ++aux_arr[arr[i]];
    
    int j=0;
    for(int i = 0; i < max_e+1; ++i)
    {
    	int temp = aux_arr[i];
    	while(temp--)arr[j++] = i;
    }
    
    delete[] aux_arr;
}
int main()
{
    int arr[] = {3, 2, 1};
    int size = sizeof(arr)/sizeof(int);
    counting_sort(arr, size);
    for(int i = 0; i < size; ++i)
    std::cout << arr[i] << '\n';
    return 0;
}
