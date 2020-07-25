#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct RMQ {
  vector<int> tree;
  size_t n;

  RMQ() = default;
  explicit RMQ(const vector<int> &vec) {
    n = vec.size();
    tree.assign(n << 1, INT32_MAX);
    for (int i = 0; i < n; ++i)
      tree[i + n] = vec[i];
    for (int i = n - 1; i > 0; --i)
      tree[i] = min(tree[i << 1], tree[(i << 1) | 1]);
  }

  int query(int l, int r) { // min[l, r)
    l += n;
    r += n;
    int res = INT32_MAX;
    while (l < r) {
      if (l & 1)
        res = min(res, tree[l++]);
      if (r & 1)
        res = min(res, tree[--r]);
      l >>= 1;
      r >>= 1;
    }
    return res;
  }
};

struct LCA {
  vector<int> euler;
  vector<int> new_at;
  vector<int> to_old;
  RMQ rmq;

  LCA(const vector<vector<int>> &adj) {
    auto n = adj.size();
    new_at.assign(n, -1);
    to_old.assign(n, -1);
    int c = 0;
    dfs(adj, 0, c);

    rmq = RMQ(euler);
  }

  void dfs(const vector<vector<int>> &adj, int v, int &c) {
    new_at[v] = euler.size();
    auto new_val = c++;
    to_old[new_val] = v;
    euler.push_back(new_val);
    for (auto child : adj[v]) {
      if (new_at[child] == -1) {
        dfs(adj, child, c);
        euler.push_back(new_val);
      }
    }
  }

  int lca(int v, int u) {
    v = new_at[v];
    u = new_at[u];
    if (v > u)
      swap(v, u);
    auto r = rmq.query(v, u + 1);
    return to_old[r];
  }
};

int main() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 1; i < n; ++i) {
    int v, u;
    cin >> v >> u;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }

  LCA lca(adj);
  cout << lca.lca(2, 5) << '\n';
  return 0;
}
