#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

enum State { UNDISCOVERED, BEING_ASSIGNED_SCC, ASSIGNED_SCC };

int c = 0;
vector<vector<int>> g;
vector<int> id, low;
vector<State> state;
stack<int> stk;
vector<vector<int>> components;

void dfs(int v) {
  state[v] = BEING_ASSIGNED_SCC;
  id[v] = low[v] = c++;
  stk.push(v);

  for (auto e : g[v]) {
    if (state[e] == UNDISCOVERED) {
      dfs(e);
      low[v] = min(low[v], low[e]);
    }

    if (state[e] == BEING_ASSIGNED_SCC) {
      low[v] = min(low[v], id[e]);
    }
  }

  if (id[v] == low[v]) {
    vector<int> comp;
    while (true) {
      int top = stk.top();
      stk.pop();
      state[top] = ASSIGNED_SCC;
      comp.push_back(top);
      if (top == v) {
        break;
      }
    }
    components.push_back(comp);
  }
}

void scc() {
  for (int i = 0; i < g.size(); ++i) {
    if (state[i] == UNDISCOVERED) {
      dfs(i);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  g.assign(n, vector<int>());
  low.assign(n, -1);
  id.assign(n, -1);
  state.assign(n, UNDISCOVERED);

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
  }

  scc();

  for (auto &comp : components) {
    for (auto e : comp) {
      cout << e << ", ";
    }
    cout << '\n';
  }

  return 0;
}
