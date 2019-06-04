#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>
#include <limits>
#include <queue>

using namespace std;

struct hash_pair {
    int hash64shift(int key) const
    {
        key = (~key) + (key << 18); // key = (key << 18) - key - 1;
        key = key ^ (key >> 31);
        key = key * 21; // key = (key + (key << 2)) + (key << 4);
        key = key ^ (key >> 11);
        key = key + (key << 6);
        key = key ^ (key >> 22);
        return (int) key;
    }

    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash64shift(hash64shift(hash1) ^ hash64shift(hash2));
    }
};


using vertex_t = int;
using adjacency_list_t = unordered_map<vertex_t, vector<vertex_t>>;
using weight_t = int;
using edge_weight_t = unordered_map<pair<vertex_t, vertex_t>, weight_t, hash_pair>;

class Graph {
public:
    adjacency_list_t adjacencyList;
    bool weighted = false;
    int vertices = 0;
    edge_weight_t edgeWeight;

    Graph() = delete;
    Graph(adjacency_list_t al, int s, bool w): adjacencyList(move(al)), vertices(s), weighted(w) {

        // find total number of edges
        //for(auto&& l: adjacencyList) edges += l.second.size();

        if(!weighted) return;

        for(auto&& l: adjacencyList)
        {
            for(auto v: l.second)
            {
                int wt;
                cout << "weight(" << l.first << ", " << v << ") = ";
                cin >> wt;
                edgeWeight[make_pair(l.first, v)] = wt;
            }
        }
    }

    Graph(adjacency_list_t al, edge_weight_t ew, int s, bool w):
        adjacencyList(move(al)), edgeWeight(move(ew)), vertices(s), weighted(w)
    {}

    Graph(int s, bool w): vertices(s), weighted(w) {}

    vector<vertex_t> neighbours(vertex_t vertex) {
        return adjacencyList[vertex];
    }

    void add_edge(int v1, int v2, bool directed, int weight = 1) {

        if(adjacencyList.find(v1) == adjacencyList.end())
        {
            adjacencyList[v1] = {v2};
            if(!directed) add_edge(v2, v1, true, weight);
        } else {
            adjacencyList[v1].push_back(v2);
            if(!directed) add_edge(v2, v1, true, weight);
        }

        if(weighted) edgeWeight[make_pair(v1, v2)] = weight;
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

vector<vertex_t> topological_sort(Graph g)
{
    stack<vertex_t> ordered_vertices;

    unordered_set<vertex_t> visited;

    for(auto vertex: g.adjacencyList){
        if(visited.find(vertex.first) == visited.end()){
            topological_sort_helper(g, vertex.first, visited, ordered_vertices);
        }
    }

    vector<vertex_t> sorted_vertices(g.vertices);
    int i = 0;
    while(!ordered_vertices.empty()){
        sorted_vertices[i++] = ordered_vertices.top();
        ordered_vertices.pop();
    }

    return sorted_vertices;
}

unordered_map<vertex_t, weight_t> shortest_path_dag(Graph g, int s, int t)
{
    auto sorted_vertices = topological_sort(g);
    unordered_map<vertex_t, weight_t> d;
    unordered_map<vertex_t, vertex_t> parent;

    for(auto v: sorted_vertices)
    {
        d[v] = numeric_limits<int>::max();
        parent[v] = numeric_limits<int>::max();
    }

    d[s] = 0;

    for(auto current_vertex: sorted_vertices)
    {
        if(d[current_vertex] == numeric_limits<int>::max()) continue;
        for(auto neighbour: g.neighbours(current_vertex))
        {
            if(d[neighbour] > (d[current_vertex] + g.edgeWeight[{current_vertex, neighbour}]))
            {
                d[neighbour] = d[current_vertex] + g.edgeWeight[{current_vertex, neighbour}];
                parent[neighbour] = current_vertex;
            }
        }
    }

    stack<vertex_t> temp;
    for(vertex_t current_vertex = t; current_vertex != numeric_limits<int>::max(); current_vertex = parent[current_vertex])
        temp.push(current_vertex);

    cout << "Cost: " << d[t] << ", Path: ";
    while(!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    return d;
}

int main() {
    Graph g(8, true);

    for(int i = 0; i < 11; ++i)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        g.add_edge(v1, v2, true, w);
    }

//    for(auto e: topological_sort(g)) cout << e << " ";

    for(int i = 0; i < 7; ++i)
    {
        auto e = shortest_path_dag(g, 7, i);
        cout << '\n';
    }

    //for(auto i: e) cout << 1 << " -> " << i.first << ": " << i.second << "\n";
    return 0;
}
