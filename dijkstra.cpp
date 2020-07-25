#include <deque>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector<bool> visited;
deque<int> order;
vector<int> d;
map<pair<int, int>, int> weight;

void dijkstra(int s = 0) {
  map<int, int> pq;
  pq.insert({0, s});
  d[s] = 0;
  while (!pq.empty()) {
    auto w = pq.begin()->first;
    auto v = pq.begin()->second;
    pq.erase(pq.begin());

    for (auto c : g[v]) {
      if (d[c] > d[v] + weight[{v, c}]) {
        d[c] = d[v] + weight[{v, c}];
        pq.insert({d[c], c});
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  g.assign(n, vector<int>());
  visited.assign(n, false);
  d.assign(n, numeric_limits<int>::max());
  for (int i = 1; i <= m; ++i) {
    char u, v;
    int w;
    cin >> u >> v >> w; /* --u; --v; */
    g[u].push_back(v);
    g[v].push_back(u);
    weight[{u, v}] = w;
    weight[{v, u}] = w;
  }

  dijkstra();
  for (int i = 0; i < n; ++i)
    cout << "i: " << i << ", " << d[i] << '\n';
  return 0;
}
