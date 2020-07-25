#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> sparse_table(vector<int> &vec) {
  // # rows in sparse table is same as the number
  // of bits required to store the size of vec
  // # bit to store a number = floor(log2(k)) + 1
  vector<vector<int>> st(log2(vec.size()) + 1, vector<int>(vec.size()));
  st[0] = vec;
  for (int k = 1; k < st.size(); ++k) {
    for (int i = 0; i + (1 << k) <= vec.size(); ++i) {
      st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
    }
  }
  return st;
}

int query(vector<vector<int>> &st, int l, int r) {
  int len_interval = r - l + 1;
  int trailing_zeros = log2(len_interval);
  return min(st[trailing_zeros][l],
             st[trailing_zeros][r - (1 << trailing_zeros) + 1]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> vec(n);
  for (auto &e : vec)
    cin >> e;
  auto st = sparse_table(vec);
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << query(st, l, r) << '\n';
  }
  return 0;
}
