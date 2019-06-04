#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <limits>

using namespace std;

using vertex_t = int;
using adjacency_list_t = unordered_map<vertex_t, vector<vertex_t>>;
using weight_t = int;

class Graph {
public:
    adjacency_list_t adjacencyList;
    int size;
    Graph(adjacency_list_t al, int s): adjacencyList(move(al)), size(s) {}
    vector<vertex_t> neighbours(vertex_t vertex) {
        return adjacencyList[vertex];
    }
};

void shortest_path(Graph g, int s, int e)
{
    queue<int> to_processed;
    unordered_set<int> visited;
    unordered_map<vertex_t, vertex_t> parent;

    to_processed.push(s);
    parent[s] = numeric_limits<int>::infinity();

    while(!to_processed.empty())
    {
        int current_vertex = to_processed.front();

        //cout << current_vertex << " ";
        if(current_vertex == e) break;

        visited.insert(current_vertex);
        to_processed.pop();

        for(auto neighbour: g.neighbours(current_vertex))
        {
            if(visited.find(neighbour) == visited.end())
            {
                to_processed.push(neighbour);
                parent[neighbour] = current_vertex;
                visited.insert(neighbour);
            }
        }
    }

    stack<int> path;
    for(int current_vertex = e; current_vertex != numeric_limits<int>::infinity(); current_vertex = parent[current_vertex])
    {
        path.push(current_vertex);
    }

    while(!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }

}

int main() {
    adjacency_list_t adjacencyList{
            {3, {5, 4, 6}},
            {1, {2, 3}},
            {2, {3, 4}},
            {4, {5}},
            {6, {2, 4}}
    };

    Graph g(adjacencyList, 6);

    shortest_path(g, 1, 4);

    return 0;
}
