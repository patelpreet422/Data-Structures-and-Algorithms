#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<vector<int>> g;
vector<bool> being_visited;
vector<vector<int>> paths;

deque<int> path;

void dfs(int v, int d) {
  being_visited[v] = true;
  path.push_back(v);

  if(v == d) {
    paths.push_back(vector<int>(begin(path), end(path)));
  } else {
    for(auto c: g[v]) {
      if(!being_visited[c]) {
        dfs(c, d);
      }
    }
  }

  being_visited[v] = false;
  path.pop_back();
}

int main() {
  int n, m; cin >> n >> m;
  g.assign(n, vector<int>());
  being_visited.assign(n, false);
  for(int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
  }
  
  int v = 0, d = g.size()-1;
  cout << "start and end vertices: "
  cin >> v >> d;
  dfs(v, d);

  for(auto& r: paths) {
    for(auto e: r) cout << e << ' ';
    cout << '\n';
  }

  return 0;
}
