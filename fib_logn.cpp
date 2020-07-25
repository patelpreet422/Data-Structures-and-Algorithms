#include <algorithm>
#include <exception>
#include <initializer_list>
#include <iostream>
#include <math.h>
#include <stdexcept>
#include <unordered_map>
#include <vector>

using namespace std;
template <typename T> using matrix = vector<vector<T>>;
const int64_t MOD = 1'000'000'007;

void multiply(matrix<int64_t> &m, matrix<int64_t> &b) {
  matrix<int64_t> t{{0, 0}, {0, 0}};
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k)
        t[i][j] = (t[i][j] + m[i][k] * b[k][j]) % MOD;
    }
  }
  m = t;
}

matrix<int64_t> matrix_pow(matrix<int64_t> m, int64_t k) {
  matrix<int64_t> r = {{1, 0}, {0, 1}};
  for (; k; k >>= 1) {
    if (k & 1)
      multiply(r, m);
    multiply(m, m);
  }
  return r;
}

int64_t fib(int64_t k) {
  if (k <= 1)
    return k;
  matrix<int64_t> m{{1, 1}, {1, 0}};
  m = matrix_pow(m, k);
  return m[0][1];
}

int64_t sum_fib_n(int64_t k) { return fib(k + 2) - 1; }

int main() {
  cout << fib(10) << '\n';
  return 0;
}
