#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;

// use 3-way partition aka Dutch National Flag algorithm
// partions array[l..h] in three regions
//
// for more info look at quick sort implementation
// of Algorithms by Robert Sedgewick 4E page: 288
//
// arr[l..h] = [ < pivot | == pivot | pivot < ]
// returns {ll, hl} such that arr[ll..hl] == pivot
array<int, 2> partition(vector<int> &v, int l, int h) {
  int pivot = v[l + (h - l) / 2];
  int ll = l;
  int hl = h;
  for (int i = l; i <= hl;) {
    if (v[i] < pivot) {
      swap(v[ll++], v[i++]);
    } else if (v[i] == pivot) {
      ++i;
    } else {
      swap(v[hl--], v[i]);
    }
  }
  return {ll, hl};
}

void quick_sort(vector<int> &v, int l, int h) {
  if (l > h)
    return;
  auto [ll, hl] = partition(v, l, h);
  quick_sort(v, l, ll - 1);
  quick_sort(v, hl + 1, h);
}

void print(vector<int> &v) {
  for (auto e : v) {
    cout << e << ' ';
  }
  cout << '\n';
}

int main() {
  vector<int> v{1, 2, 3, 4, 5};

  do {
    auto t = v;
    quick_sort(t, 0, t.size() - 1);
    print(t);
  } while (next_permutation(begin(v), end(v)));
  return 0;
}
