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

    void add_edge(int v1, int v2, bool directed, int weight = 0) {

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

unordered_map<vertex_t, weight_t> dijkstra(Graph g, vertex_t s, vertex_t t)
{
    multimap<weight_t, vertex_t> path_weight;
    //priority_queue<pair<weight_t, vertex_t>, vector<pair<weight_t, vertex_t>>, greater<pair<weight_t, vertex_t>>> path_weight;
    unordered_map<vertex_t, weight_t> d;
    unordered_map<vertex_t, vertex_t> parent;

    for(int i = 0; i < g.vertices; ++i) {
        d[i] = numeric_limits<int>::max();
        parent[i] = numeric_limits<int>::max();
    }

    path_weight.insert(make_pair(0, s));
    d[s] = 0;

    while(!path_weight.empty())
    {
        // pop top element
        //int current_vertex = path_weight.top().second;
        //path_weight.pop();
        int current_vertex = path_weight.begin()->second;
        path_weight.erase(path_weight.begin());

        for(auto neighbour: g.neighbours(current_vertex))
        {
            if(d[neighbour] >= (d[current_vertex] + g.edgeWeight[make_pair(current_vertex, neighbour)]))
            {
                d[neighbour] = d[current_vertex] + g.edgeWeight[make_pair(current_vertex, neighbour)];
                path_weight.insert(make_pair(d[neighbour], neighbour));
                parent[neighbour] = current_vertex;
            }
        }
    }

    // print actual path
    if(d[t] == numeric_limits<int>::max())
        cout << t << " is not reachable from " << s << '\n';
    else {
        stack<vertex_t> path_node;

        for(vertex_t current_vertex = t; current_vertex != numeric_limits<int>::max(); current_vertex = parent[current_vertex])
        {
            path_node.push(current_vertex);
        }

        cout << "Cost = " << d[t] << ", Path: ";
        while(!path_node.empty())
        {
            vertex_t cv = path_node.top();
            path_node.pop();
            if(!path_node.empty())
                cout << cv << " >>[" << g.edgeWeight[{cv, path_node.top()}] << "]>> ";
            else
                cout << cv ;
        }
    }

    return d;
}

int main() {
    adjacency_list_t adjacencyList{
            {0, {1, 7}},
            {1, {2, 7}},
            {2, {3, 5, 8}},
            {3, {4, 5}},
            {4, {5}},
            {5, {6, 4}},
            {6, {7, 8}},
            {7, {8}}
    };

    edge_weight_t edgeWeight{
            {{0, 1}, 4},
            {{0, 7}, 8},
            {{1, 2}, 8},
            {{1, 7}, 11},
            {{2, 3}, 1},
            {{2, 8}, 2},
            {{2, 5}, 4},
            {{3, 4}, 9},
            {{3, 5}, 1},
            {{5, 4}, 2},
            {{5, 6}, 2},
            {{6, 7}, 1},
            {{6, 8}, 6},
            {{7, 8}, 7}
    };

    Graph g(adjacencyList, edgeWeight, 9, true);
//    for(int i = 0; i < 14; ++i)
//    {
//        int v1, v2, w;
//        cin >> v1 >> v2 >> w;
//        g.add_edge(v1, v2, true, w);
//    }

    auto e = dijkstra(g, 1, 4);

    return 0;
}
