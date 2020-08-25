#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int binomial(int n, int r) {
  if (r > n - r) {
    r = n - r;
  }
  int a = 1;
  for (int i = 0; i < r; ++i) {
    a *= ((n - i));
    a /= (i + 1);
  }
  return a;
}

int catalan(int n) { return binomial(2 * n, n) / (n + 1); }

int main() {
  cout << catalan(4) << '\n';
  return 0;
}

