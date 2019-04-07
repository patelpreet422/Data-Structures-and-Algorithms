#include <numeric>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<long>> all_pair_sp(const vector<vector<long>>& graph)
{
    auto n = graph.size();
    vector<vector<long>> path = graph;

    for(auto k = 0; k < n; ++k)
    {
        for(auto i = 0; i < n; ++i)
        {
            for(auto j = 0; j < n; ++j)
            {
                path[i][j] = min(path[i][j], path[i][k]+path[k][j]);
            }
        }
    }
    return path;
}

int main() {
    const int INF = numeric_limits<int>::max();
    vector<vector<long>> vec {
        {0,   5,  INF, 10},
        {INF,  0,  3,  INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    auto apsp = all_pair_sp(vec);
    for(auto& r: apsp)
    {
        for(auto e: r)
        {
            cout << e << " ";
        }
        cout << '\n';
    }
    return 0;
}
