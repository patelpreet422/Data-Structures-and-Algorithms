#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<vector<int>> g;
vector<int> preorder, low;
int c = 0;

void dfs(int n, int p = -1) {
  low[n] = preorder[n] = c++;
  for(auto e: g[n]) {
    if(preorder[e] == -1) {
      dfs(e, n);
      low[n] = min(low[n], low[e]);
      if(low[e] > preorder[n]) {
        cout << n << "->" << e << '\n';
      }
    } else if(e != p) {
      low[n] = min(low[n], preorder[e]);
    }
  }
}

void dfs() {
  for(int i = 0; i < (int)g.size(); ++i) {
    if(preorder[i] == -1) {
      dfs(i, i);
    }
  }
}

int main() {
  int n, m; cin >> n >> m;
  g.assign(n, vector<int>());
  preorder.assign(n, -1);
  low.assign(n, -1);
  for(int i = 0; i < m; ++i) {
    int v, u; cin >> v >> u; /* --v; --u; */
    g[v].push_back(u);
    g[u].push_back(v);
  }

  dfs();
//  for(auto e: low) cout << e << ' ';
  cout << '\n';
  return 0;
}
