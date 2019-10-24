#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<vector<int>> g;
vector<bool> being_visited;
vector<vector<int>> paths;

deque<int> path;

void dfs(int v) {
  being_visited[v] = true;
  path.push_back(v);

  for(auto c: g[v]) {
    if(!being_visited[c]) {
      dfs(c);
    }
  }

  bool all = true;
  for(auto c: g[v]) {
    if(!being_visited[c]) {
      all = false;
      break;
    }
  }

  if(all)
    paths.push_back(vector<int>(begin(path), end(path)));

  being_visited[v] = false;
  path.pop_back();
}

int main() {
  int n, m; cin >> n >> m;
  g.assign(n, vector<int>());
  being_visited.assign(n, false);
  for(int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v; /*--u; --v; */
    g[u].push_back(v);
//    g[v].push_back(u);
  }

  int v = 0;
  dfs(v);

  for(auto& r: paths) {
    for(auto e: r) cout << e << ' ';
    cout << '\n';
  }

  return 0;
}
