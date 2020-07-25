#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using vertex_t = int;
using adjacency_list_t = unordered_map<vertex_t, vector<vertex_t>>;
using weight_t = int;

class Graph {
public:
  adjacency_list_t adjacencyList;
  int size;
  Graph(adjacency_list_t al, int s) : adjacencyList(al), size(s) {}
  vector<vertex_t> neighbours(vertex_t vertex) { return adjacencyList[vertex]; }
};

void dfs_visit(Graph g, vertex_t vertex, unordered_set<vertex_t> &visited) {
  visited.insert(vertex);
  cout << vertex << '\n';

  for (auto neighbour : g.neighbours(vertex)) {
    if (visited.find(neighbour) == visited.end()) {
      dfs_visit(g, neighbour, visited);
    }
  }
}

void dfs(Graph g) {
  unordered_set<vertex_t> visited;
  for (auto vertex : g.adjacencyList) {
    if (visited.find(vertex.first) == visited.end()) {
      dfs_visit(g, vertex.first, visited);
    }
  }
}

void dfs(Graph g, vertex_t vertex) {
  unordered_set<vertex_t> visited;
  dfs_visit(g, vertex, visited);
}

int main() {
  adjacency_list_t adjacencyList{
      {1, {2, 7, 8}}, {2, {3, 6}}, {3, {4, 5}}, {8, {9, 12}}, {9, {10, 11}}};
  Graph g(adjacencyList, 12);
  dfs(g);
  return 0;
}
