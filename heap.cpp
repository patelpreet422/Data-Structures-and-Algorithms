#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int> &vec, int size, int i)
{
  while(2*i+1 < size)
  {
    int max_child = 2*i+1;
    if(2*i+2 < size && vec[2*i+2] > vec[2*i+1])
      max_child = 2*i+2;
    if(vec[max_child] > vec[i])
    {
      swap(vec[i], vec[max_child]);
      i = max_child;
    } else { return; }
  }
}

void heapify(vector<int> &vec, int i)
{
  heapify(vec, vec.size(), i);
}

void makeHeap(vector<int> &vec)
{
  auto size = vec.size();
  for(int i = (size-2)/2; i >= 0; --i)
  {
    heapify(vec, i);
  }
}

void bubbleUp(vector<int> &vec, int i)
{
  while((i-1)/2 >=0  && vec[i] > vec[(i-1)/2])
  {
    swap(vec[i], vec[(i-1)/2]);
    i = (i-1)/2;
  }
}

void pushHeap(vector<int> &vec, int e)
{
  vec.push_back(e);
  bubbleUp(vec, vec.size()-1);
}

int popHeap(vector<int> &vec, int size)
{
  int e = vec[0];
  swap(vec[0], vec[size-1]);
  //vec.pop_back();
  heapify(vec, size-1, 0);
  return e;
}

int popHeap(vector<int> &vec)
{
  return popHeap(vec, vec.size());
}

void heapSort(vector<int> &heap)
{
  for(int i = 0; i < heap.size(); ++i)
  {
    popHeap(heap, heap.size() - i);
  }
}

ostream& operator<<(ostream& os, const vector<int> &vec)
{
  os << "[";
  for(auto e: vec) os << e << ", ";
  os << "\b\b]";
  return os;
}

int main()
{
  vector<int> vec{35,33,42,10,4,19,27,44,26,31};
  vector<int> vec2 = vec;

  /* make_heap(vec.begin(), vec.end()); */
  /* vec.push_back(100); */
  /* push_heap(vec.begin(), vec.end()); */
  // sort_heap(vec.begin(), vec.end());
  /* cout << "std::make_heap: " << vec << '\n'; */

  makeHeap(vec2);
  pushHeap(vec2, 100);
  // heapSort(vec2);
  cout << "makeHeap: " << vec2 << '\n';
  return 0;
}
