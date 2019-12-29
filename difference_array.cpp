#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n, 0), diff(n + 1, 0);

  cout << "query: " << '\n';
  int m;
  cin >> m;

  while (m--) {
    int i, j, v;
    cin >> i >> j >> v;
    diff[i] += v;
    diff[j + 1] += -v;
  }

  for (int i = 0; i < n; ++i) {
    vec[i] += vec[i - 1] + diff[i];
  }

  copy(begin(vec), end(vec), ostream_iterator<int>(cout, " "));
  // copy(begin(diff), end(diff), ostream_iterator<int>(cout, " "));
  return 0;
}
