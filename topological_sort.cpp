#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

using vertex_t = int;
using adjacency_list_t = unordered_map<vertex_t, vector<vertex_t>>;
using weight_t = int;

class Graph {
public:
    adjacency_list_t adjacencyList;
    int size;
    Graph(adjacency_list_t al, int s): adjacencyList(al), size(s) {}
    vector<vertex_t> neighbours(vertex_t vertex) {
        return adjacencyList[vertex];
    }
};

void topological_sort_helper(Graph g, vertex_t vertex, unordered_set<vertex_t>& visited, stack<vertex_t>& ordered_vertices)
{
    visited.insert(vertex);

    for(auto neighbour: g.neighbours(vertex)){
        if(visited.find(neighbour) == visited.end()){
            topological_sort_helper(g, neighbour, visited, ordered_vertices);
        }
    }
    ordered_vertices.push(vertex);
}

void topological_sort(Graph g)
{
    stack<vertex_t> ordered_vertices;

    unordered_set<vertex_t> visited;

    for(auto vertex: g.adjacencyList){
        if(visited.find(vertex.first) == visited.end()){
            topological_sort_helper(g, vertex.first, visited, ordered_vertices);
        }
    }

    while(!ordered_vertices.empty()){
        cout << ordered_vertices.top() << '\n';
        ordered_vertices.pop();
    }
}

int main() {
    adjacency_list_t adjacencyList{
        {3, {5, 4}},
        {1, {2, 3}},
        {2, {3, 4}}
    };

    Graph g(adjacencyList, 5);
    topological_sort(g);
    return 0;
}
