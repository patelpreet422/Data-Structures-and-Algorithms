#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> g;
vector<bool> visited, on_stack;
vector<int> id, low;
stack<int> s;
int c = 0;

void dfs(int n) {
  s.push(n); visited[n] = on_stack[n] = true;
  low[n] = id[n] = c++;
  for(auto c: g[n]) {
    if(!visited[c]) dfs(c);
    if(on_stack[c]) low[n] = min(low[n], low[c]);
  }

  if(id[n] == low[n]) {
    while(true) {
      int t = s.top(); s.pop(); on_stack[t] = false;
      low[t] = low[n];
      if(t == n) break;
    }
  }
}

void scc() {
  for(int i = 0; i < g.size(); ++i) {
    if(!visited[i]) dfs(i);
  }
}

int main() {
  int n, m; cin >> n >> m;
  g.assign(n, vector<int>());
  visited.assign(n, false);
  on_stack.assign(n, false);
  id.assign(n, -1);
  low.assign(n ,-1);

  for(int i = 0; i < m; ++i) {
    int v, u; cin >> v >> u;
    g[v].push_back(u);
  }

  scc();

  for(int i = 0; i < n; ++i) {
    cout << "low[" << i << "]: " << low[i] << '\n';
  }

  return 0;
}
