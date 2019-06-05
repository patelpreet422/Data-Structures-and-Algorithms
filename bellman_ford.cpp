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
    
    weight_t edge_weight(vertex_t v1, vertex_t v2)
    {
        return edgeWeight[make_pair(v1, v2)];
    }
};

// O(V*E)
unordered_map<vertex_t, weight_t> bellman_ford(Graph g, int s, int t)
{
    unordered_map<vertex_t, weight_t> d;
    unordered_map<vertex_t, vertex_t> parent;
    for(int i = 0; i < g.vertices; ++i)
    {
        d[i] = numeric_limits<int>::max();
        parent[i] = numeric_limits<int>::max();
    }

    d[s] = 0;

    // keep on relaxing vertex (n-1) times, n = no. of vertices in a graph
    for(int i = 1; i <= g.vertices-1; ++i)
    {
        // relax every vertex which is beginning of an edge
        for(auto edge: g.edgeWeight)
        {
            vertex_t v1 = edge.first.first;

            if(d[v1] == numeric_limits<int>::max()) continue;

            for(auto neighbour: g.neighbours(v1))
            {
                if(d[neighbour] > (d[v1] + g.edge_weight(v1, neighbour)))
                {
                    d[neighbour] = d[v1] + g.edge_weight(v1, neighbour);
                    parent[neighbour] = v1;
                }
            }
        }
    }

    cout << "Cost: " << d[t] << ", "; 
    // print path
    stack<vertex_t> temp;
    for(vertex_t current_vertex = t; current_vertex != numeric_limits<int>::max(); current_vertex = parent[current_vertex])
        temp.push(current_vertex);

    while(!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    return d;
}

int main() {
    Graph g(5, true);

    for(int i = 0; i < 6; ++i)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        g.add_edge(v1, v2, true, w);
    }

    auto d = bellman_ford(g, 0, 2);
//    for(auto p: d)
//    {
//        cout << 0 << " -> " << p.first << " = " << p.second << '\n';
//    }
    return 0;
}
