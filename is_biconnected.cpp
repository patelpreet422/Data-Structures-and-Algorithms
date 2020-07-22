#include <iostream>
#include <vector>
using namespace std;

enum { UNDISCOVERED, DISCOVERED };

vector<vector<int>> g;
vector<int> id, low;
vector<int> state;
int c = 0;

bool articulation_present(int v, int p) {
  state[v] = DISCOVERED;
  low[v] = id[v] = c++;
  int unvisited_child = 0;

  for (auto e : g[v]) {
    if (e == p)
      continue;
    if (state[e] == UNDISCOVERED) {
      ++unvisited_child;

      if (articulation_present(e, v))
        return true;

      low[v] = min(low[v], low[e]);
      if (low[e] >= id[v] and p != -1) {
        return true;
      }
    } else {
      low[v] = min(low[v], id[e]);
    }
  }

  if (unvisited_child >= 2 and p == -1) {
    // root of tree is also an articulation point
    return true;
  }
  return false;
}

bool is_biconnected() {
  // Biconnected graph (aka 2-connected graph) is a graph which
  //  1) is connected
  //  2) has no articulation point
  //
  // Definition of biconnectivity:-
  // Let G = (V, E) be an undirected graph.
  // Suppose for each triple of distinct vertices
  // v, w, a in V, there is path p: v => w such that a is not on the
  // path p. Then G is biconnected.
  //
  // So checking for binconnectivity is same as checking if there is
  // articulation point present in the graph or not

  bool connected = true;
  bool has_no_art_pt = !articulation_present(0, -1);
  for (int i = 0; i < g.size(); ++i) {
    if (state[i] == UNDISCOVERED) {
      connected = false;
      break;
    }
  }
  return connected & has_no_art_pt;
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

  cout << boolalpha << is_biconnected() << '\n';
  return 0;
}
