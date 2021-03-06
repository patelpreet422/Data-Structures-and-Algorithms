#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void top_sort_(vector<vector<int>> &g) {
  int n = g.size();
  stack<int> frontier;
  vector<bool> visited(g.size(), false);
  vector<int> ordered(g.size());

  for (auto i = 0; i < g.size(); ++i) {
    if (!visited[i]) {
      frontier.push(i);
      visited[i] = true;

      while (!frontier.empty()) {
        int top = frontier.top();
        frontier.pop();
        if (top < 0) {
          // all child are visited, do post processing here
          ordered[--n] = -top - 1;
        } else {
          // before all the children are pushed onto the stack we push -top-1
          // to mark that when we see this node we are sure that all the
          // children of top are processed
          frontier.push(-top - 1);

          for (auto c : g[top]) {
            if (!visited[c]) {
              visited[c] = true;
              frontier.push(c);
            }
          }
        }
      }
    }
  }

  for (auto e : ordered)
    cout << e << ' ';
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

  top_sort_(g);
  return 0;
}
