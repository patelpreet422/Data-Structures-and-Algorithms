#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
  vector<vector<int>> vec {
    {3, 5, 1},
    {4, 8, 6},
    {7, 2, 9},
    {0, 0, 1},
    {-1, 0, 1}
  };

//  for(auto& r: vec) {
//    for(auto e: r) cout << e << ' ';
//    cout << '\n';
//  }

  for(int i = vec[0].size()-1; i >= 0; --i) {
    sort(begin(vec), end(vec), [i](auto&& l, auto&& r) {
      return l[i] < r[i];
    });
  }

  for(auto& r: vec) {
    for(auto e: r) cout << e << ' ';
    cout << '\n';
  }
  return 0;
}
