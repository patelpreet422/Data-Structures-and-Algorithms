#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int extract_digit(int k, int p)
{
  return int(k/pow(10, p-1))%10;
}

int int_size(int k)
{
  int s = 0;
  while(k) {
      k /= 10;
      ++s;
    }
  return s;
}

int max_element_size(vector<int> &vec)
{
  int mx = vec[0], mi = vec[0];
  for(int i: vec){
      if(mx < i) mx = i;
      if(mi > i) mi = i;
    }
  return max(int_size(mx), int_size(mi));
}

void radix_sort(vector<int> &vec)
{
  auto l = max_element_size(vec);
  for(int k = 1; k <= l; ++k)
    {
      sort(vec.begin(), vec.end(), [k = k](int a, int b){ return  extract_digit(a, k) < extract_digit(b, k);});
    }
}

int main()
{
  vector<int> vec{170, 45, 75, 90, 802, 24, 2, 66};
  radix_sort(vec);
  for(auto i: vec) {
      cout << i << ", ";
    }
  return 0;
}
