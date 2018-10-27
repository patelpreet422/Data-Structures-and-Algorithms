#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void insertion_sort(vector<int> & vec)
{
  for(size_t i = 0; i < vec.size(); ++i)
  {
    for(size_t j = i + 1; j < vec.size(); ++j)
    {
      if(vec[i] > vec[j])
      {
        swap(vec[i], vec[j]);
      }
    }
  }
} 

void bubble_sort(vector<int> & vec)
{
  for(size_t i = 0; i < vec.size(); ++i)
  {
    for(size_t j = 0; j <= vec.size() - i - 1; ++j)
    {
      if(vec[j] > vec[j + 1])
      {
        swap(vec[j], vec[j + 1]);
      }
    }
  }
}

void selection_sort(vector<int> & vec)
{
  for(size_t i = 0; i < vec.size() - 1; ++i)
  {
    auto min_ptr = min_element(next(begin(vec), i), end(vec));
    swap(vec[i], *min_ptr);
  }
}

int main()
{
  vector<int> vec{7, 8, 1, 0, 2, -7};
  selection_sort(vec);
  for(auto i: vec) {cout << i << '\n';}
  return 0;
}
