#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;

vector<vector<int>> g;
vector<bool> visited;
vector<bool> on_path;
vector<int> tin, tout;
vector<pair<int, int>> tree, back, fwd, cross;
int c = 0;

void dfs(int n, int p = -1) {
  tin[n] = c++;
  visited[n] = true;
  on_path[n] = true;
  for(auto c: g[n]) {
    if(c == p) continue;
    if(!visited[c]) {
      tree.emplace_back(n, c);
      dfs(c, n);
    } else {
      if(tin[n] < tin[c] and !on_path[c]) {
        // forward edge <=> back edge
        fwd.emplace_back(n, c);
      }

      if(tin[n] > tin[c] and !on_path[c]) {
        // cross edge never occur in undirected graph
        // they become tree edge
        cross.emplace_back(n, c);
      }

      if(tin[n] > tin[c] and on_path[c]) {
        back.emplace_back(n, c);
      }
    }
  }
  on_path[n] = false;
  tout[n] = c++;
}

void dfs() {
  for(int i = 0; i < (int)g.size(); ++i) {
    if(!visited[i]) {
      dfs(i);
    }
  }
}

int main() {
  int n, m; cin >> n >> m;
  g.assign(n, vector<int>());
  visited.assign(n, false);
  on_path.assign(n, false);
  tin.assign(n, 0);
  tout.assign(n, 0);
  for(int i = 0; i < m; ++i) {
    int v, u; cin >> v >> u; /* --v; --u; */
    g[v].push_back(u);
  }

  dfs();
  
  cout << "tree edge: ";
  for(auto [a, b]: tree) cout << "(" << a << ", " << b << ") ";
  cout << '\n';

  cout << "back edge: ";
  for(auto [a, b]: back) cout << "(" << a << ", " << b << ") ";
  cout << '\n';

  cout << "forward edge: ";
  for(auto [a, b]: fwd) cout << "(" << a << ", " << b << ") ";
  cout << '\n';

  cout << "cross edge: ";
  for(auto [a, b]: cross) cout << "(" << a << ", " << b << ") ";
  cout << '\n';
  return 0;
}
