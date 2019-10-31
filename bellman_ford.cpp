a#include <iostream>
#include <vector>
#include <tuple>
#include <deque>
#include <cmath>
using namespace std;

vector<vector<int>> g;
vector<tuple<int, int, int>> edge;
vector<int> d;

void bellman_ford(int s) {
  d[s] = 0;
  bool none = false;
  for(int i = 0; !none and i < (int)g.size()-1; ++i) {
    none = true;
    for(auto [u, v, c]: edge) {
      if(d[u] != numeric_limits<int>::max()) {
        if(d[v] > d[u]+c) {
          d[v] = d[u]+c;
          none = false;
        }
      }
    }
  }
}

int main() {
  int n, m; cin >> n >> m;
  g.assign(n, vector<int>());
  d.assign(n, numeric_limits<int>::max());
  for(int i = 0; i < m; ++i) {
    int u, v, w; cin >> u >> v >> w; /* --v; --u; */

    g[u].push_back(v);
    edge.push_back({u, v, w});
  }
  bellman_ford(0);
  for(int i = 0; i < (int)g.size(); ++i) {
    cout << "d[" << i << "]: " << d[i] << '\n';
  }
  return 0;
}
