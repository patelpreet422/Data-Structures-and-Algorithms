#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int bsearch(vector<int> &vec, int k) {
  int p = 0;

  for (int i = log2(vec.size()); i >= 0; --i) {
    if (vec[p] == k)
      return p;
    if ((p | (1 << i)) < vec.size() && vec[p | (1 << i)] <= k)
      p |= (1 << i);
  }

  return (vec[p] == k) ? p : ((k < vec[0]) ? 0 : p + 1);
}

int main() {
  vector<int> vec{12, -10, 75, 100};
  sort(begin(vec), end(vec));
  for (auto e : vec)
    cout << e << ' ';
  cout << '\n';
  int a = -10;
  cin >> a;
  auto i = bsearch(vec, a);
  cout << '\n' << a << " at: " << i << '\n';
  return 0;
}
