#include <cmath>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g, rg;
vector<bool> visited;
deque<int> order;

void dfs(int n, const vector<vector<int>> &adj) {
  visited[n] = true;
  for (auto c : adj[n]) {
    if (!visited[c]) {
      dfs(c, adj);
    }
  }
  order.push_front(n);
}

void sort(const vector<vector<int>> &adj) {
  for (int i = 0; i < (int)adj.size(); ++i) {
    if (!visited[i]) {
      dfs(i, adj);
    }
  }
}

void dfs2(int n, const vector<vector<int>> &adj, vector<int> &comp) {
  visited[n] = true;
  comp.push_back(n);
  for (auto e : adj[n]) {
    if (!visited[e]) {
      dfs2(e, adj, comp);
    }
  }
}

void kosaraju() {
  sort(rg); // find top order from RG
  // process G in top order of RG
  visited.assign(g.size(), false);
  vector<int> comp;
  int scc = 0;
  for (auto n : order) {
    if (!visited[n]) {
      dfs2(n, g, comp);
      ++scc;

      cout << scc << ": ";
      for (auto v : comp)
        cout << v << ' ';
      cout << '\n';
      comp.clear();
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  g.assign(n, vector<int>());
  rg.assign(n, vector<int>());
  visited.assign(n, false);
  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u; /* --v; --u; */
    g[v].push_back(u);
    rg[u].push_back(v);
  }
  kosaraju();
  return 0;
}
