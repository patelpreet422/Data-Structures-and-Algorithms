#include <bits/stdc++.h>

using namespace std;

int64_t change(int n, vector<int> &vec) {
  vector<int64_t> cache(n + 1);
  cache[0] = 1;
  for (int i = 1; i <= n; ++i) {
    int64_t ways = 0;
    for (int j = 0; j < vec.size(); ++j) {
      if (i - vec[j] >= 0)
        ways += cache[i - vec[j]];
    }
    cache[i] = ways;
  }
  return cache[n];
}

int main() {
  vector<int> vec;
  int s;
  cin >> s;
  copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(vec));
  cout << change(s, vec) << '\n';
  return 0;
}
