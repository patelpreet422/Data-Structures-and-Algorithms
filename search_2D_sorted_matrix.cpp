#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool exists(vector<vector<int>> &arrs, int e) {
  int r = arrs.size();
  if (r == 0)
    return false;
  int c = arrs[0].size();
  if (c == 0)
    return false;

  vector<int> temp(r);
  int k = 0;
  for (int i = 0; i < r; ++i)
    temp[k++] = arrs[i][c - 1];

  auto t = lower_bound(temp.begin(), temp.end(), e);
  auto d = distance(temp.begin(), t);
  if (d > r - 1)
    return false;

  return binary_search(arrs[d].begin(), arrs[d].end(), e);
}

int main() {
  vector<vector<int>> arrs{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};

  cout << boolalpha << exists(arrs, 10) << '\n';

  /*
  for (auto v : arrs) {
          for (auto e : v)
                  cout << boolalpha << exists(arrs, e) << ' ';
          cout << '\n';
  }
  */
  return 0;
}
