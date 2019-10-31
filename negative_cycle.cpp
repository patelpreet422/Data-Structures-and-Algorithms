#include <iostream>
#include <vector>
#include <tuple>
#include <deque>
#include <cmath>
using namespace std;

vector<vector<int>> g;
vector<tuple<int, int, int>> edge;
vector<int> d;

bool negative_cycle(int s) {
  d[s] = 0;
  bool relaxed = false;
  for(int i = 0; i < (int)g.size()-1; ++i) {
    relaxed = false;
    for(auto [u, v, c]: edge) {
      if(d[u] != numeric_limits<int>::max()) {
        if(d[v] > d[u]+c) {
          d[v] = d[u]+c;
          relaxed = true;
        }
      }
    }
  }
  return relaxed;
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
  cout << boolalpha << negative_cycle(0) << '\n';
  return 0;
}
