#ifdef DEBUG
#include <LeetcodeHelper.h>
#include <prettyprint.hpp>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll merge(vector<int> &v, int l, int m, int h) {
  ll c = 0;
  vector<int> temp(h - l + 1, 0);
  int t = 0;
  int ll = l, lh = m, li = l;
  int rl = m + 1, rh = h, ri = m + 1;
  while (li <= lh and ri <= rh) {
    if (v[li] <= v[ri]) {
      temp[t++] = v[li++];
    } else {
      c += (lh - li + 1);
      temp[t++] = v[ri++];
    }
  }

  while (li <= lh) {
    temp[t++] = v[li++];
  }

  while (ri <= rh) {
    temp[t++] = v[ri++];
  }

  for (int i = 0; i < temp.size(); ++i) {
    v[i + l] = temp[i];
  }
  return c;
}

ll inversion(vector<int> &v, int l, int h) {
  if (l >= h) {
    return 0;
  }
  int m = l + (h - l) / 2;
  ll li = inversion(v, l, m);
  ll ri = inversion(v, m + 1, h);
  ll ci = merge(v, l, m, h);
  return li + ri + ci;
}

ll inversion(vector<int> &v) { return inversion(v, 0, v.size() - 1); }

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &e : v) {
      cin >> e;
    }
    cout << inversion(v) << '\n';
  }
  return 0;
}

