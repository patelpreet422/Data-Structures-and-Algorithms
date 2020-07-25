#include <iostream>
#include <stack>
#include <vector>
using namespace std;

enum VertexState { UNDISCOVERED, DISCOVERED, PROCESSED };

vector<vector<int>> g;
vector<VertexState> state;
vector<int> parent;

void dfs(int n, int p, vector<vector<int>> &cs) {
  state[n] = DISCOVERED;
  parent[n] = p;
  for (auto c : g[n]) {
    if (c == p)
      continue;
    if (state[c] == UNDISCOVERED) {
      dfs(c, n, cs);
    } else if (state[c] == DISCOVERED) {
      vector<int> cycle;
      for (int e = n;; e = parent[e]) {
        cycle.push_back(e);
        if (e == c) {
          break;
        }
      }
      cs.push_back(cycle);
    }
  }
  state[n] = PROCESSED;
}

vector<vector<int>> cycles(const vector<vector<int>> &g) {
  vector<vector<int>> cs;

  for (int i = 0; i < g.size(); ++i) {
    if (state[i] == UNDISCOVERED) {
      dfs(i, -1, cs);
    }
  }

  return cs;
}

int main() {
  int n, m;
  cin >> n >> m;
  g.assign(n, vector<int>());
  state.assign(n, UNDISCOVERED);
  parent.assign(n, -1);
  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u;
    g[v].push_back(u);
    g[u].push_back(v);
  }

  for (auto c : cycles(g)) {
    for (auto e : c) {
      cout << e << ' ';
    }
    cout << '\n';
  }

  return 0;
}
