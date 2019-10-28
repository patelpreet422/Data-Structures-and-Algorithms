#include <iostream>
#include <deque>
#include <vector>
#include <numeric>
#include <unordered_set>
using namespace std;

vector<vector<int>> g;
vector<bool> visited;

bool dfs(int n, int p) {
  visited[n] = true;
  for(auto e: g[n]) {
    if(!visited[e]) {
      if(dfs(e, n)) return true;
    } else if(e != p) {
      return true;
    }
  }
  return false;
}

bool cycle() {
  for(int i = 0; i < (int)g.size(); ++i) {
    if(!visited[i]) {
      if(dfs(i, i)) return true;
    }
  }
  return false;
}

int main() {
  int n, m; cin >> n >> m;
  g.assign(n, vector<int>());
  visited.assign(n, false);
  for(int i = 0; i < m; ++i) {
    int v, u; cin >> v >> u; /* --v; --u */
    g[v].push_back(u);
    g[u].push_back(v);
  }
  cout << boolalpha << cycle() << '\n';
  return 0;
}
