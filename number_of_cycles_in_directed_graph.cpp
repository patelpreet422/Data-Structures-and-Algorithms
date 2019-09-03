#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dfs(vector<vector<int>>& g, int start)
{
    int cycles = 0;
    vector<bool> visited(g.size(), false);
    stack<int> s;
    s.push(start);
    visited[start] = true;
    while(!s.empty())
    {
        int top = s.top();
        s.pop();
        cout << top << '\n';
        for(auto child: g[top])
        {
            if(!visited[child])
            {
                visited[child] = true;
                s.push(child);
            } else ++cycles;
        }
    }
    return cycles;
}

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);

    for(int i = 1; i <= m; ++i) {
        int v, u; cin >> v >> u;
        g[v].push_back(u);
    }

    auto cycle = dfs(g, 0);
    cout << '\n' << "Cycle: " << cycle << '\n';
    return 0;
}
