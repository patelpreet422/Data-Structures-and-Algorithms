#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// returns sum[l...r] after querying the summary
int query(vector<int> &vec, vector<int> &summary, int l, int r) {
  int mx = numeric_limits<int>::max(), blk_size = summary.size();
  while (l < r && l % blk_size)
    mx = min(mx, vec[l++]);
  while (l + blk_size <= r) {
    mx = min(mx, summary[l / blk_size]);
    l += blk_size;
  }
  while (l <= r)
    mx = min(mx, vec[l++]);
  return mx;
}

// range sum summary
vector<int> summary(vector<int> &vec) {
  int n = vec.size(), blk_id = -1, blk_size = ceil(sqrt(n));
  vector<int> s(blk_size, numeric_limits<int>::max());
  for (int i = 0; i < n; ++i) {
    if (i % blk_size == 0)
      ++blk_id;
    s[blk_id] = min(s[blk_id], vec[i]);
  }
  return s;
}

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (auto &e : vec)
    cin >> e;
  auto s = summary(vec);
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << query(vec, s, l, r) << '\n';
  }
  return 0;
}
