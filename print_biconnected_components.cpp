#include <array>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

enum { UNDISCOVERED, PROCESSED, DISCOVERED };

vector<vector<int>> g;
vector<int> id, low;
vector<int> state;
stack<array<int, 2>> edges;
int c = 0;

void dfs(int v, int p) {
  state[v] = DISCOVERED;
  low[v] = id[v] = c++;
  int unvisited_child = 0;

  for (auto e : g[v]) {
    if (e == p)
      continue;
    if (state[e] == UNDISCOVERED) {
      ++unvisited_child;
      edges.push({v, e});

      dfs(e, v);

      low[v] = min(low[v], low[e]);
      if (low[e] >= id[v] and p != -1) {
        // articulation point found
        int x = -1;
        int y = -1;
        do {
          x = edges.top()[0];
          y = edges.top()[1];
          edges.pop();
          cout << x << " - " << y << ", ";
        } while (!((x == v) && (y == e)));
        cout << '\n';
      }
    } else {
      // in theoritical undirected graph there are no forward edge
      // or cross edges but the way we implement undirected graph means
      // there are going to be forward edge and cross edge in undirected
      // graph also we need to handle that case as well
      if (id[e] < id[v])
        edges.push({v, e});
      low[v] = min(low[v], id[e]);
    }
  }

  state[v] = PROCESSED;
}

void biconnected_components() {
  for (int i = 0; i < g.size(); ++i) {
    if (state[i] == UNDISCOVERED) {
      dfs(i, -1);
      for (; !edges.empty();) {
        int x = edges.top()[0], y = edges.top()[1];
        cout << x << " - " << y << ", ";
        edges.pop();
      }
      cout << '\n';
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  g.assign(n, vector<int>());
  state.assign(n, UNDISCOVERED);
  low.assign(n, -1);
  id.assign(n, -1);

  for(int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u;
    g[v].push_back(u);
    g[u].push_back(v);
  }

  biconnected_components();
  return 0;
}
