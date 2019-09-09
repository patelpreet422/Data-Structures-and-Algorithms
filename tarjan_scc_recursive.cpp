#include <vector>
#include <iostream>
#include <stack>
#include <climits>
using namespace std;
using graph_t = vector<vector<int>>;

void dfs(graph_t& g, int v, stack<int>& s, vector<bool>& on_stack, vector<int>& id, vector<int>& low_link, int& id_num)
{
  s.push(v);
  on_stack[v] = true;
  id[v] = low_link[v] = id_num++;
  for(auto c: g[v]) {
    if(id[c] == -1) {
      dfs(g, c, s, on_stack, id, low_link, id_num);
    }
    if(on_stack[c]) {
      low_link[v] = min(low_link[v], low_link[c]);
    }
  }

  if(id[v] == low_link[v]) {
    while(true) {
      int curr = s.top();
      s.pop();
      on_stack[curr] = false;
      low_link[curr] = low_link[v];
      if(curr == v) break;
    }
  }
}

void scc(graph_t& g)
{
  int n = g.size();
  int id_num = 0;
  stack<int> s;
  vector<bool> on_stack(n, false);
  vector<int> id(n, -1), low_link(n, numeric_limits<int>::max());
  for(int i=0; i<n; ++i)
  {
    if(id[i]==-1)
      dfs(g, i, s, on_stack, id, low_link, id_num);
  }
  for(int i=0; i<n; ++i)
  {
    cout << "ll[" << i << "]: " << low_link[i] << '\n';
  }
}

int main()
{
  int n, m; cin >> n >> m;
  graph_t g(n);
  for(int i=1; i<=m; ++i)
  {
    int v, u; cin >> v >> u;
    g[v].push_back(u);
  }

  scc(g);
  return 0;
}
  
