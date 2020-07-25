#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// union_find data structure usi g path compression
struct union_find {
  vector<int> parent;
  vector<int> sz;
  size_t components;
  size_t size;
  union_find() = delete;
  union_find(size_t s) : components(s), size(s) {
    parent.resize(s);
    sz.resize(s, 1);
    iota(begin(parent), end(parent), 0);
  }

  // uses path compression
  // for every node that lies in between node and root change its root to root
  // that is reached in the end
  int find(int p) {
    int root = p;
    while (parent[root] != root)
      root = parent[root];

    for (int q = p; parent[q] != root; q = exchange(parent[q], root))
      ;
    /*
    int root = q;
    while(parent[p] != root)
    {
            int prev_parent = parent[p];
            parent[p] = root;
            p = prev_parent;
    }
    */

    return root;
  }

  void unify(int p, int q) {
    int p_root = find(p);
    int q_root = find(q);
    if (p_root == q_root)
      return;

    if (sz[p_root] >= sz[q_root]) {
      parent[q_root] = p_root;
      sz[p_root] += sz[q_root];
    } else {
      parent[p_root] = q_root;
      sz[q_root] += sz[p_root];
    }
    --components;
  }

  bool connected(int a, int b) { return find(a) == find(b); }

  int component_size(int p) { return sz[find(p)]; }

  friend ostream &operator<<(ostream &os, union_find uf) {
    for (int i = 0; i < uf.size; ++i) {
      os << uf.find(i) << " ";
    }
    return os;
  }
};

int main() {
  union_find uf(10);

  uf.unify(0, 1);
  uf.unify(2, 3);
  uf.unify(4, 5);
  uf.unify(6, 7);
  uf.unify(8, 9);

  uf.unify(6, 9);
  cout << uf << '\n';

  uf.unify(7, 5);
  cout << uf << '\n';

  uf.unify(0, 2);
  cout << uf << '\n';

  uf.unify(3, 4);
  cout << uf << '\n';

  uf.unify(6, 1);
  cout << uf << '\n';

  uf.unify(8, 9);
  cout << uf << '\n';
  cout << uf.components << '\n';

  for (int i = 0; i < uf.size; ++i) {
    cout << uf.component_size(i) << ' ';
  }
  return 0;
}
