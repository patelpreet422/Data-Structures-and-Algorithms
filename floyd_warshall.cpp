#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using vertex_t = long;
using weight_t = int;
using adjacency_matrix_t = vector<vector<vertex_t>>;

struct Graph {
  adjacency_matrix_t adjacency_matrix;
  size_t vertices;

  Graph() = delete;
  Graph(vector<vector<vertex_t>> am)
      : adjacency_matrix(move(am)), vertices(am.size()) {}
  Graph(size_t s) : vertices(s) {
    adjacency_matrix.resize(s, vector<vertex_t>(s, 0));
  }

  void add_edge(vertex_t v1, vertex_t v2, weight_t weight = 1,
                bool directed = true) {
    adjacency_matrix[v1][v2] = weight;
    if (!directed)
      adjacency_matrix[v2][v1] = weight;
  }

  vector<vertex_t> neighbours(vertex_t v) {
    vector<vertex_t> children;
    for (vertex_t i = 0; i < vertices; ++i) {
      if (adjacency_matrix[v][i])
        children.push_back(i);
    }
    return children;
  }
};

adjacency_matrix_t floyd_warshall(Graph g, vertex_t s, vertex_t t) {
  adjacency_matrix_t path_matrix = g.adjacency_matrix;
  vector<vector<vertex_t>> parent(
      g.vertices, vector<vertex_t>(g.vertices, numeric_limits<int>::max()));

  // path matrix setup
  for (vertex_t i = 0; i < g.vertices; ++i) {
    for (vertex_t j = 0; j < g.vertices; ++j) {
      if (g.adjacency_matrix[i][j] != 0)
        parent[i][j] = j;
      if (path_matrix[i][j] == 0)
        path_matrix[i][j] = numeric_limits<int>::max();
      if (i == j)
        path_matrix[i][j] = 0;
    }
  }

  // actual algo
  for (vertex_t k = 0; k < g.vertices; ++k) {
    for (vertex_t i = 0; i < g.vertices; ++i) {
      for (vertex_t j = 0; j < g.vertices; ++j) {
        if (path_matrix[i][j] > path_matrix[i][k] + path_matrix[k][j]) {
          path_matrix[i][j] = path_matrix[i][k] + path_matrix[k][j];
          parent[i][j] = k;
        }
      }
    }
  }

  // print path
  cout << s << " ";
  for (vertex_t current_vertex = parent[s][t];
       current_vertex != numeric_limits<int>::max();
       current_vertex = parent[current_vertex][t])
    cout << current_vertex << " ";

  return path_matrix;
}

int main() {
  Graph g(5);

  for (int i = 0; i < 7; ++i) {
    int v1, v2, w;
    cin >> v1 >> v2 >> w;
    g.add_edge(v1, v2, w);
  }

  auto apsp = floyd_warshall(g, 2, 1);

  return 0;
}
