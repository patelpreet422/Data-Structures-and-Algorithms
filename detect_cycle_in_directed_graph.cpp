#include <deque>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector<bool> visited;
vector<bool> on_path;

bool dfs(int n) {
  visited[n] = true;
  on_path[n] = true;
  for (auto e : g[n]) {
    if (!visited[e]) {
      if (dfs(e))
        return true;
    } else if (on_path[e]) {
      return true;
    }
  }
  on_path[n] = false;
  return false;
}

bool cycle() {
  for (int i = 0; i < (int)g.size(); ++i) {
    if (!visited[i]) {
      if (dfs(i))
        return true;
    }
  }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  g.assign(n, vector<int>());
  visited.assign(n, false);
  on_path.assign(n, false);
  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u; /* --v; --u */
    g[v].push_back(u);
  }
  cout << boolalpha << cycle() << '\n';
  return 0;
}
