#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct union_find {
  vector<int> parent;
  vector<int> size;
  union_find(int n) {
    parent.assign(n, -1);
    iota(begin(parent), end(parent), 0);
    size.assign(n, 1);
  }
  int find(int x) {
    int p = x;
    while(parent[p] != p) {
      p = parent[x];
    }
    while(parent[x] != p) {
      int t = parent[x];
      parent[x] = p;
      x = t;
    }
    return p;
  }
  int unify(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) {
      return a;
    }
    if(size[a] > size[b]) {
      size[a] += size[b];
      parent[b] = a;
      return a;
    } else {
      size[b] += size[a];
      parent[a] = b;
      return b;
    }
    return -1;
  }
  int is_connected(int a, int b) { return find(a) == find(b); }
};

vector<vector<int>> g;
map<pair<int, int>, int> weight;
vector<tuple<int, int, int>> edges;

vector<pair<int, int>> kruskal() {
  union_find uf(g.size());
  vector<pair<int, int>> tree_edges;
  sort(begin(edges), end(edges));
  for (auto [w, u, v] : edges) {
    if (tree_edges.size() == g.size() - 1) {
      break;
    }
    if (!uf.is_connected(u, v)) {
      tree_edges.push_back({u, v});
      uf.unify(u, v);
    }
  }
  return tree_edges;
}

int main() {
  int n, m;
  cin >> n >> m;
  g.assign(n, vector<int>());
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
    weight[{u, v}] = w;
    weight[{v, u}] = w;
    edges.push_back({w, u, v});
  }
  
  for (auto [u, v] : kruskal()) {
    printf("%d -[%d]-> %d\n", u, weight[{u, v}], v);
  }
  return 0;
}

