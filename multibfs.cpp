#include <iostream>
#include <iterator>
#include <queue>
#include <vector>

using namespace std;

int n; 
vector<vector<int>> g;
vector<int> d;

enum { UNVISITED = -1 };

void bfs(const vector<int> &start) {
  queue<int> q;
  for (auto e : start) {
    q.push(e);
    d[e] = 0;
  }

  while (!q.empty()) {
    int t = q.front();
    q.pop();

    for (auto e : g[t]) {
      if (d[e] == UNVISITED) {
        d[e] = d[t] + 1;
        q.push(e);
      }
    }
  }
}

int main() {
  int m;
  cin >> n >> m;
  g.assign(n, vector<int>());
  d.assign(n, UNVISITED);

  while (m--) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int s;
  cin >> s;
  vector<int> start(s, 0);
  for (auto &e : start)
    cin >> e;

  bfs(start);

  copy(begin(d), end(d), ostream_iterator<int>(cout, " "));
  cout << '\n';
  return 0;
}
