#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// partition returns the index at which the pivot must be placed
// Lomuto partition
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

int quick_select(vector<int> &v, int l, int h, int k) {
  if (l > h)
    return -1;
  int p = partition(v, l, h);
  if (k == p)
    return p;
  if (k < p)
    return quick_select(v, l, p - 1, k);

  return quick_select(v, p + 1, h, k);
}

int main() {
  vector<int> v{1, 2, 3, 4, 5};
  do {
    auto t = v;
    /* cout << "vec: "; */
    /* for (auto e : t) { */
    /*   cout << e << ' '; */
    /* } */
    /* cout << '\n'; */
    cout << "quick_select: ";
    for (int i = 0; i < t.size(); ++i) {
      cout << t[quick_select(t, 0, t.size() - 1, i)] << ' ';
    }
    cout << '\n';
  } while (next_permutation(begin(v), end(v)));
  return 0;
}
