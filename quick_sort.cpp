#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// partition returns the index at which the pivot must be placed
int partition(vector<int> &v, int l, int h) {
  int ll = l;
  int pivot = v[h];
  for (int k = l; k < h; ++k) {
    if (v[k] <= pivot) {
      swap(v[k], v[ll++]);
    }
  }
  swap(v[ll], v[h]);
  return ll;
}

void quick_sort(vector<int>& v, int l, int h) {
  if (l > h)
    return;
  int p = partition(v, l, h);
  quick_sort(v, l, p - 1);
  quick_sort(v, p + 1, h);
}

int main() {
  vector<int> v{1, 2};
  do {
    vector<int> t = v;
    quick_sort(t, 0, t.size() - 1);
    for (auto e : t) {
      cout << e << ' ';
    }
    cout << '\n';
  } while (next_permutation(begin(v), end(v)));
  return 0;
}
