#include <iostream>
#include <numeric>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

void dfs(const vector<vector<int>> &g, int s, vector<int> &visited,
         unordered_map<int, vector<int>> &component, int c) {
  // vector<bool> visited(g.size(), false);
  stack<int> st;
  st.push(s);
  while (!st.empty()) {
    int top = st.top();
    st.pop();
    visited[top] = true;
    component[c].push_back(top);
    // cout << top << ' ';

    for (auto child : g[top]) {
      if (!visited[child]) {
        visited[child] = true;
        st.push(child);
      }
    }
  }
}

int dfs(const vector<vector<int>> &g) {
  int components = 0;
  unordered_map<int, vector<int>> component(g.size());
  vector<int> visited(g.size(), false);

  for (auto i = 0; i < g.size(); ++i) {
    if (!visited[i]) {
      visited[i] = true;
      dfs(g, i, visited, component, components);
      ++components;
    }
  }

  cout << '\n';
  for (const auto &p : component) {
    cout << p.first << ": ";
    for (auto e : p.second) {
      cout << e << " ";
    }
    cout << '\n';
  }

  return component.size();
}

int main() {
  cout << "is_undirected: ";
  char is_undirected = 'N';
  cin >> is_undirected;
  int n, m;
  cin >> n >> m;

  // g.size = n+1 if node start from 1, component returned from dfs =
  // actual_component+1 (because zero is treated as seperate component) g.size =
  // n   if node start from 0

  vector<vector<int>> g(n + 1);

  for (int i = 1; i <= m; ++i) {
    int v, u;
    cin >> v >> u;
    g[v].push_back(u);
    if (is_undirected == 'Y' || is_undirected == 'y')
      g[u].push_back(v);
  }

  auto components = dfs(g);

  cout << '\n' << "Components: " << components << '\n';
  return 0;
}
