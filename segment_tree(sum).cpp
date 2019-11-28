#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<int64_t> tree;
vector<int64_t> delta;

void make(const vector<int64_t>& vec, int64_t lo_n, int64_t hi_n, int64_t n = 0) {
  if(lo_n == hi_n) {
    tree[n] = vec[lo_n];
  } else {
    auto m = (lo_n + hi_n)/2;
    make(vec, lo_n, m, 2*n+1);
    make(vec, m+1, hi_n, 2*n+2);
    tree[n] = tree[2*n+1] + tree[2*n+2];
  }
}

int64_t query(int64_t lo_n, int64_t hi_n, int64_t l, int64_t r, int64_t n = 0) {
  tree[n] += (hi_n - lo_n + 1)*delta[n];
  if(lo_n != hi_n) {
    delta[2*n+1] += delta[n];
    delta[2*n+2] += delta[n];
  }
  delta[n] = 0;

  if(r < lo_n || l > hi_n) return 0;
  else if(l <= lo_n && hi_n <= r) return tree[n];
  auto m = (lo_n + hi_n)/2;

  auto ls = query(lo_n, m, l, r, 2*n+1);
  auto rs = query(m+1, hi_n, l, r, 2*n+2);

  return ls+rs;
}

int64_t query(int64_t l, int64_t r, int64_t size) {
  return query(0, size-1, l, r);
}

void increment(int64_t del, int64_t lo_n, int64_t hi_n, int64_t l, int64_t r, int64_t n = 0) {
  tree[n] += (hi_n - lo_n + 1) * delta[n];
  if (lo_n != hi_n) {
    delta[2 * n + 1] += delta[n];
    delta[2 * n + 2] += delta[n];
  }
  delta[n] = 0;

  if(r < lo_n || l > hi_n) return;
  else if(l <= lo_n && hi_n <= r) {
    delta[n] += del;
  }
  else {
    auto m = (lo_n + hi_n)/2;

    increment(del, lo_n, m, l, r, 2*n+1);
    increment(del, m+1, hi_n, l, r, 2*n+2);

    tree[n] = tree[2*n+1] + tree[2*n+2];
  }
}

void increment(int64_t del, int64_t l, int64_t r, int64_t size) {
  increment(del, 0, size-1, l, r);
}

void init(const vector<int64_t>& vec) {
  tree = vector<int64_t>(4*vec.size()+1, 0);
  delta = vector<int64_t>(4*vec.size()+1, 0);
  make(vec, 0, vec.size()-1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int64_t t; cin >> t;
  while(t--) {
    size_t n, c; cin >> n >> c;
    tree = vector<int64_t>(4*n+1, 0);
    delta = vector<int64_t>(4*n+1, 0);
    while(c--) {
      int64_t p, q, v;
      cin >> p >> q >> v;
      increment(v, p, q, n);
    }
    cin >> c;
    while(c--) {
      int64_t p;
      cin >> p;
      cout << query(p, p, n) << '\n';
    }
  }
  return 0;
}

