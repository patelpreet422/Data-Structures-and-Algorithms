#include <numeric>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


pair<vector<vector<long>>, vector<vector<long>>> all_pair_sp(const vector<vector<long>>& graph)
{
    const int INF = numeric_limits<int>::max();

    long n = graph.size();
    vector<vector<long>> path = graph;

    // pred stores the next vertex where we must move to reach from i->j
    vector<vector<long>> pred(n, vector<long>(n, INF));

    for(auto i = 0; i < n; ++i)
    {
        for(auto j = 0; j < n; ++j)
        {
            if(graph[i][j] != INF) pred[i][j] = j;
        }
    }

    for(auto k = 0; k < n; ++k)
    {
        for(auto i = 0; i < n; ++i)
        {
            for(auto j = 0; j < n; ++j)
            {
                if(path[i][k]+path[k][j] < path[i][j])
                {
                    path[i][j] = path[i][k]+path[k][j];
                    pred[i][j] = k;
                }
            }
        }
    }
    return make_pair(path, pred);
}

//iterative
void construct_path(const vector<vector<long>>& pred, long s, long e)
{
    cout << s << " -> ";
    for(auto at = pred[s][e]; at!=e; at=pred[at][e]) {
        cout << at << " -> ";
    }
    cout << e << '\n';

    //pass path as well to return cost
    //return path[s][e];
}

//recursive
void path_reconstruction(const vector<vector<long>>& pred, long s, long e)
{
    if(pred[s][e] == e)
    {
        cout << s << " -> ";
    } else {
        path_reconstruction(pred, s, pred[s][e]);
        path_reconstruction(pred, pred[s][e], e);
    }
}

void pretty_print_path(const vector<vector<long>>& pred, long s, long e)
{
    path_reconstruction(pred, s, e);
    cout << e << '\n';
}

//driver code
int main() {
    const int INF = numeric_limits<int>::max();
    vector<vector<long>> vec { {0,   5,  INF, 10},
                               {INF,  0,  3,  INF},
                               {INF, INF, 0,   1},
                               {INF, INF, INF, 0} };

    auto [path, pred] = all_pair_sp(vec);

//    for(auto& r: path)
//    {
//        for(auto e: r)
//        {
//            cout << setw(5) << ((e==INF)?"INF":to_string(e)) << " ";
//        }
//        cout << '\n';
//    }
    construct_path(pred, 1, 3);
    //pretty_print_path(pred, 0, 3);
    return 0;
}

// go 0 -> 3, cost = 8
// 0 -> 1 -> 2 -> 3

