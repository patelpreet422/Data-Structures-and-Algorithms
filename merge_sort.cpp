
#include <iostream>
#include <algorithm>
using namespace std;

void merge(int *array, int low, int mid, int high, int *temp){
    int left = low, right = mid+1, i=low;
    while(left<=mid && right<=high){
        if(array[left] <= array[right]) temp[i++] = array[left++];
        else temp[i++] = array[right++];
    }
    while(left <= mid) temp[i++] = array[left++];
    while(right <= high) temp[i++] = array[right++];
    for(i = low; i <= high;++i) array[i] = temp[i];
}
void mergeSortHelper(int *array, int low, int high, int *temp){
    if(low >= high) return;
    int mid = (low + high)/2;
    mergeSortHelper(array, low, mid, temp);
    mergeSortHelper(array, mid+1, high, temp);
    merge(array, low, mid, high, temp);
}
void mergeSort(int *array, int size){
    int *temp = new int[size];
    mergeSortHelper(array, 0, size - 1, temp);
    delete[] temp;
}
int main()
{
    int size = 10;
    int *array = new int[size];
    for(int i = 0; i < size; ++i){
        array[i] = rand()%10 + 1;
    }
    mergeSort(array, size);
    for_each(array, array+size, [](const auto &e){cout << e << ' ';});
    delete[] array;
    return 0;
}
