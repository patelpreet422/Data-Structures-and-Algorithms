#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

vector<int64_t> tree;

void add(int64_t i) {
  for (++i; i < tree.size(); i += (i & -i)) {
    tree[i] += 1;
  }
}

int64_t sum(int64_t i) {
  int64_t r = 0;
  for (++i; i; i -= (i & -i)) {
    r += tree[i];
  }
  return r;
}

int64_t inversion(vector<int64_t> &a) {
  int64_t n = a.size();

  vector<int64_t> b = a;
  sort(begin(b), end(b));
    
  // convert a to compressed version maint64_taining the relative order of
  // elements in the original array
  // use coordinate compression to reduce the size of the fenwick tree
  for (int64_t i = 0; i < n; ++i) {
    a[i] = lower_bound(begin(b), end(b), a[i]) - begin(b);
  }

  int64_t r = 0;
  tree.assign(n + 1, 0);
  for (int64_t i = n - 1; i >= 0; --i) {
    r += sum(a[i]);
    add(a[i]);
  }

  return r;
}

int main() {
  vector<int64_t> a;
  copy(istream_iterator<int64_t>(cin), istream_iterator<int64_t>(),
  back_inserter(a)); cout << inversion(a) << '\n';
  return 0;
}
