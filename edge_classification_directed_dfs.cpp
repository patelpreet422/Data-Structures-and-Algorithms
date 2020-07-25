#include <cmath>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

enum VertexState { NOT_DISCOVERED, DISCOVERED, PROCESSED };

vector<vector<int>> g;
vector<VertexState> state;
vector<int> tin;
int c = 0;

vector<pair<int, int>> tree;
vector<pair<int, int>> back;
vector<pair<int, int>> fwd;
vector<pair<int, int>> cross;

void dfs(int n) {
  tin[n] = c++;
  state[n] = DISCOVERED;

  for (auto e : g[n]) {
    if (state[e] == NOT_DISCOVERED) {
      dfs(e);
      tree.push_back({n, e});
    } else {
      if (state[e] == PROCESSED && tin[n] < tin[e]) {
        fwd.push_back({n, e});
      }

      if (state[e] == PROCESSED && tin[e] < tin[n]) {
        cross.push_back({n, e});
      }

      if (state[e] == DISCOVERED) {
        back.push_back({n, e});
      }
    }
  }

  state[n] = PROCESSED;
}

void dfs() {
  for (int i = 0; i < (int)g.size(); ++i) {
    if (state[i] == NOT_DISCOVERED) {
      dfs(i);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  g.assign(n, vector<int>());
  state.assign(n, NOT_DISCOVERED);
  tin.assign(n, 0);
  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u;
    g[v].push_back(u);
  }

  dfs();

  cout << "tree edge: ";
  for (auto [a, b] : tree)
    cout << "(" << a << ", " << b << ") ";
  cout << '\n';

  cout << "back edge: ";
  for (auto [a, b] : back)
    cout << "(" << a << ", " << b << ") ";
  cout << '\n';

  cout << "forward edge: ";
  for (auto [a, b] : fwd)
    cout << "(" << a << ", " << b << ") ";
  cout << '\n';

  cout << "cross edge: ";
  for (auto [a, b] : cross)
    cout << "(" << a << ", " << b << ") ";
  cout << '\n';
  return 0;
}
