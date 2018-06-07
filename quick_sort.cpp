/*if you are using Visual Studio then uncomment the line below*/
//#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;

int partition(int *array, int low, int high){
    int pivot = array[(low + high)/2];
    while(low<=high){
        while(array[low] < pivot) ++low;
        while(array[high] > pivot) --high;
        if(low <= high) swap(array[low++], array[high--]);
    }
    return low;
}
void quickSortHelper(int *array, int low, int high){
    if(low >= high) return;
    int partitionPoint = partition(array, low, high);
    quickSortHelper(array, low, partitionPoint-1);
    quickSortHelper(array, partitionPoint, high);
}
void quickSort(int *array, int size){
    quickSortHelper(array, 0, size - 1);
}
int main()
{
    int size = 10;
    int array[size];
    for(int i = 0; i < size; ++i){
        array[i] = rand()%10 + 1;
    }
    quickSort(array, size);
    for_each(array, array+size, [](const auto &e){cout << e << ' ';});
    return 0;
}
