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


using vertex_t = long;
using weight_t = int;
using adjacency_matrix_t = vector<vector<vertex_t>>;
using edge_weight_t = unordered_map<pair<vertex_t, vertex_t>, weight_t, hash_pair>;

struct Graph
{
    adjacency_matrix_t adjacency_matrix;
    size_t vertices;
    edge_weight_t edgeWeight;

    Graph() = delete;
    Graph(vector<vector<vertex_t>> am): adjacency_matrix(move(am)), vertices(am.size())
    {
        for (vertex_t v1 = 0; v1 < vertices; ++v1) {
            for (vertex_t v2 = 0; v2 < vertices; ++v2) {
                if(adjacency_matrix[v1][v2])
                    edgeWeight[make_pair(v1, v2)] = adjacency_matrix[v1][v2];
            }
        }
    }

    Graph(size_t s): vertices(s)
    {
        adjacency_matrix.resize(s, vector<vertex_t>(s, 0));
    }

    void add_edge(vertex_t v1, vertex_t v2, weight_t weight = 1, bool directed = true)
    {
        adjacency_matrix[v1][v2] = weight;
        edgeWeight[make_pair(v1, v2)] = weight;
        if(!directed) add_edge(v2, v1, weight);
    }

    vector<vertex_t> neighbours(vertex_t v)
    {
        vector<vertex_t> children;
        for(vertex_t i = 0; i < vertices; ++i)
        {
            if(adjacency_matrix[v][i]) children.push_back(i);
        }
        return children;
    }

    weight_t edge_weight(vertex_t v1, vertex_t v2) { return adjacency_matrix[v1][v2]; }
};

int main() {
    Graph g(5);

    for(int i = 0; i < 7; ++i)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        g.add_edge(v1, v2, w);
    }
    
    return 0;
}
