#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <map>
using namespace std;

vector<vector<int>> g;
vector<vector<int>> rg;
vector<bool> visited;
deque<int> order;
unordered_map<int, vector<int>> component;
deque<int> condensed_top_order;

void reverse() {
  for(int i = 0; i < (int)g.size(); ++i) {
    for(auto e: g[i]) {
      rg[e].push_back(i);
    }
  }
}

void dfs(int v) {
  visited[v] = true;
  for(auto c: rg[v]) {
    if(!visited[c])
      dfs(c);
  }
  order.push_front(v);
}

void sort() {
  for(int i = 0; i < (int)g.size(); ++i) {
    if(!visited[i]) {
      dfs(i);
    }
  }
}

void dfs(int v, int c) {
  component[c].push_back(v);
  visited[v] = true;
  for(auto e: g[v]) {
    if(!visited[e]) {
      dfs(e, c);
    }
  }
}

void kosaraju() {
  int c = 0;
  visited.assign(g.size(), false);

  for(auto e: order) {
    if(!visited[e]) {
      condensed_top_order.push_front(e);
      ++c;
      dfs(e, c);
    }
  }
}

int main() {
  int n, m; cin >> n >> m;
  g.assign(n, vector<int>());
  rg.assign(n, vector<int>());
  visited.assign(n, false);
  for(int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v; /* --u; --v; */
    g[u].push_back(v);
  }

  reverse();
  sort();
  kosaraju();

  for(auto&& p: component)
  {
    cout << p.first << ": ";
    for(auto e: p.second) cout << e << " ";
    cout << '\n';
  }

  cout << "condensed top order: ";
  for(auto e: condensed_top_order) cout << e << ' ';

  return 0;
}
