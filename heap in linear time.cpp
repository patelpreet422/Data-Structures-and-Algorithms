#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void heapify_down(vector<int> & vec, size_t i)
{

  bool swapped = true;
  while (i < vec.size() && swapped) {
      size_t left_child = 2*i + 1;
      size_t right_child = 2*i + 2;
      //bool swapped = false;
      if(left_child < vec.size() && right_child < vec.size() && vec[left_child] < vec[right_child])
       {
           swap(vec[i], vec[right_child]);
           i = right_child;
        } else if(left_child < vec.size()) {
          //only left child
          if(vec[i] < vec[left_child])
            {
              swap(vec[i], vec[left_child]);
              i = left_child;
            } else {
              swapped = false;
            }
        } else {
          //no child
          swapped = false;
        }
    }
}

void build_max_heap(vector<int> & vec)
{
  for(int i = (vec.size() - 2)/2; i >= 0; --i)
    {
      heapify_down(vec, i);
    }
}

int main()
{
  vector<int> vec{-7, -7, 0, -5, 10, 5, 50};
//  make_heap(begin(vec), end(vec));
  build_max_heap(vec);
//  sort_heap(begin(vec), end(vec));
  for(auto i: vec) { cout << i << '\n'; }
  return 0;
}
