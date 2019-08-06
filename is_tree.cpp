#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

int dfs(const vector<vector<int>>& g)
{
    int connected = 1;
    vector<bool> visited(g.size(), 0);
    stack<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty())
    {
        int t = q.top();
        q.pop();

        for(auto c: g[t]) {
            if(!visited[c]) {
                q.push(c);
                visited[c] = true;
                ++connected;
            }
        }
    }

    return connected;
}

int main()
{
    int n, m;
    cin >> n >> m;
    if(m == n-1)
    {
        vector<vector<int>> g(n, vector<int>());
        for(int i = 0; i < m; ++i)
        {
            int v1, v2; cin >> v1 >> v2;

            // for undirected graph
            g[v1-1].push_back(v2-1);
            g[v2-1].push_back(v1-1);
        }
        (dfs(g) == n) ? cout << "YES\n": cout << "NO\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
