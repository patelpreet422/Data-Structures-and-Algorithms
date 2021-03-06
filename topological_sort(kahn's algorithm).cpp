#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

bool top_sort(const vector<vector<int>> &g) {
  vector<int> in_degree(g.size(), 0);
  for (auto i = 0; i < g.size(); ++i) {
    for (auto e : g[i])
      ++in_degree[e];
  }

  // for lexicographically first topological order use priority_queue
  queue<int> q;
  for (auto i = 0; i < g.size(); ++i)
    if (in_degree[i] == 0)
      q.push(i);

  vector<int> ordered;
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    ordered.push_back(top);

    for (auto c : g[top]) {
      --in_degree[c];
      if (in_degree[c] == 0)
        q.push(c);
    }
  }

  cout << '\n';
  for (auto e : ordered)
    cout << e << " ";
  cout << '\n';

  return (ordered.size() == g.size()) ? true : false;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);

  for (int i = 1; i <= m; ++i) {
    int v, u;
    cin >> v >> u;
    g[v].push_back(u);
  }

  auto possible = top_sort(g);
  cout << boolalpha << possible << '\n';
  return 0;
}
