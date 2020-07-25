#include <deque>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector<int> preorder, low;
vector<bool> art;
int c = 0;

void dfs(int n, int p = -1) {
  low[n] = preorder[n] = c++;
  int unvisited_children = 0;
  for (auto e : g[n]) {
    if (preorder[e] == -1) {
      ++unvisited_children;
      dfs(e, n);
      low[n] = min(low[n], low[e]);
      if (low[e] >= preorder[n] and p != -1) {
        art[n] = true;
      }

    } else if (e != p) {
      low[n] = min(low[n], preorder[e]);
    }
  }
  if (p == -1 and unvisited_children > 1) {
    art[n] = true;
  }
}

void dfs() {
  for (int i = 0; i < (int)g.size(); ++i) {
    if (preorder[i] == -1) {
      dfs(i);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  g.assign(n, vector<int>());
  preorder.assign(n, -1);
  low.assign(n, -1);
  art.assign(n, false);
  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u; /* --v; --u; */
    g[v].push_back(u);
    g[u].push_back(v);
  }

  dfs();
  for (int i = 0; i < n; ++i) {
    if (art[i])
      cout << i << ' ';
  }
  cout << '\n';
  return 0;
}
