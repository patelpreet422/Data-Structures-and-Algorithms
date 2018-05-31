#include <iostream>
//#include <algorithm>
#include <cstdlib>
using namespace std;
class Heap {
public:
    int *arr;
    int size = 0;
    int capacity = 2;
public:
    Heap(){
        arr = new int[2];
    }
    ~Heap(){
        delete arr;
    }
    int getLeftChildIndex(int parentIndex) {return parentIndex*2+1;};
    int getRightChildIndex(int parentIndex) {return parentIndex*2+2;};
    int getParentIndex(int childIndex){return (childIndex-1)/2;}
    bool hasLeftChild(int parentIndex){return getLeftChildIndex(parentIndex) < size;}
    bool hasRightChild(int parentIndex){return getRightChildIndex(parentIndex) < size;}
    bool hasParent(int childIndex){return getParentIndex(childIndex) >= 0;}
    int leftChild(int parentIndex){return arr[getLeftChildIndex(parentIndex)];}
    int rightChild(int parentIndex){return arr[getRightChildIndex(parentIndex)];}
    int parent(int childIndex){return arr[getParentIndex(childIndex)];}

    void heapifyUp() {
        int currentChild = size-1;
        while(hasParent(currentChild) && (parent(currentChild) >  arr[currentChild])){
            swap(arr[currentChild], arr[getParentIndex(currentChild)]);
            currentChild = getParentIndex(currentChild);
        }
    }

    void heapifyDown(){
        int currentParent = 0;
        while(hasLeftChild(currentParent)){
            int smallest_index = getLeftChildIndex(currentParent);
            if(hasRightChild(currentParent) && (rightChild(currentParent) < leftChild(currentParent))){
                smallest_index = getRightChildIndex(currentParent);
            }
            if(arr[currentParent] >= arr[smallest_index]){
                swap(arr[smallest_index], arr[currentParent]);
            } else {
                break;
            }
            currentParent = smallest_index;
        }
    }

    void add(int key){
        if(size+1 > capacity)
        {
            capacity *= 2;
            int *temp_array = new int[capacity];
            copy(arr, arr+size, temp_array);
            arr = temp_array;
        }
        arr[size] = key;
        ++size;
        heapifyUp();
    }
    int pull(){
        int root_value = arr[0];
        arr[0] = arr[size-1];
        --size;
        heapifyDown();
        return root_value;
    }
};

int main() {
    Heap h;
    int size = 1000;
    for(int i = 1; i <= size; ++i)
    {
        int temp = rand()%10+1;
        cout << temp << ' ';
        h.add(temp);
    }
    cout << '\n';

    for(int i = 1; i <= size; ++i) {
        cout << h.pull() << ' ';
    }
    return 0;
}
