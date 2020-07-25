#include <deque>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector<bool> visited;
deque<int> order;
vector<int> d;
map<pair<int, int>, int> weight;

void dfs(int v) {
  visited[v] = true;
  for (auto c : g[v]) {
    if (!visited[c]) {
      dfs(c);
    }
  }
  order.push_front(v);
}

void sort() {
  for (int i = 0; i < (int)g.size(); ++i) {
    if (!visited[i]) {
      dfs(i);
    }
  }
}

void shortest_path(int s = 0) {
  sort();
  d[s] = 0;
  for (auto v : order) {
    // d[v] == INT_MAX, means that this vertex is not reachable
    if (d[v] != numeric_limits<int>::max()) {
      for (auto c : g[v]) {
        d[c] = min(d[c], d[v] + weight[{v, c}]);
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  g.assign(n, vector<int>());
  visited.assign(n, false);
  d.assign(n, numeric_limits<int>::max());
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w; /* --u; --v; */
    g[u].push_back(v);
    weight[{u, v}] = w;
  }

  shortest_path(1);
  for (int i = 0; i < n; ++i)
    cout << "i: " << i << ", " << d[i] << '\n';
  return 0;
}
