#include <deque>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector<bool> visited;
deque<int> order;

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

int main() {
  int n, m;
  cin >> n >> m;
  g.assign(n, vector<int>());
  visited.assign(n, false);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v; /* --u; --v */
    ;
    g[u].push_back(v);
  }

  sort();
  for (auto e : order)
    cout << e << ' ';
  return 0;
}
