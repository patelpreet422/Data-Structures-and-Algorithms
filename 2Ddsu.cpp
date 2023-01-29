#include <iostream>
#include <set>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

class UnionFind2D {
 public:
  int components;

  UnionFind2D(int n, int m) {
    // Initialize parents and size vectors
    parents = vector<int>(n * m, 0);
    size = vector<int>(n * m, 1);
    components = n * m;

    for(int i = 0; i < n * m; ++i) {
      parents[i] = i;
    }

    this->n = n;
    this->m = m;
  }

  int find(int x, int y) {
    int i = x * m + y;
    if (parents[i] != i) {
      parents[i] = find(parents[i] / m, parents[i] % m);
    }
    return parents[i];
  }

  void unite(int x1, int y1, int x2, int y2) {
    int i = find(x1, y1);
    int j = find(x2, y2);

    if (i == j) {
      return;
    }

    if (size[i] < size[j]) {
      std::swap(i, j);
    }

    parents[j] = i;

    this->components = this->components - 1;
    
    size[i] += size[j];
  }

  int connected_components() {
    return components;
  }

 private:
  std::vector<int> parents;
  std::vector<int> size;
  int n, m;
};

int main() {
    int n = 2;
    int m = 3;
    
    UnionFind2D uf(n, m);

    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> g(n, vector<int>(m, 0));

    vector<tuple<string, int, int>> queries;
    queries.push_back({"c", -1, -1});
    queries.push_back({"d", 0, 1});
    queries.push_back({"d", 0, 2});
    queries.push_back({"c", -1, -1});

    for(int i = 0; i < queries.size(); ++i) {
        string s = get<0>(queries[i]);

        if(s == "c") {
          // count connected components
          cout << uf.connected_components() << '\n';
        } else {
          int u = get<1>(queries[i]);
          int v = get<2>(queries[i]);

          g[u][v] = 1;

          // up, down, right, left
          for(auto [dx, dy]: dir) {
            int x = u + dx;
            int y = v + dy;

            if(0 <= x && x < n && 0 <= y && y < m && g[x][y] == 1) {
              uf.unite(u, v, x, y);
            }
          }
        }

    }

    return 0;
}
