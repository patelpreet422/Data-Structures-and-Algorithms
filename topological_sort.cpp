#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int>>& g, vector<bool>& visited, int start, stack<int>& stk)
{
    if(visited[start]) return;
    else {
        visited[start] = true;
        for(auto c:  g[start])
        {
            if(!visited[c]) dfs(g, visited, c, stk);
        }
        stk.push(start);
    }
}

void top_sort(vector<vector<int>>& g)
{
    stack<int> stk;
    vector<bool> visited(g.size(), false);
    for(int i = 0; i < g.size(); ++i) {
        if(!visited[i]) dfs(g, visited, i, stk);
    }

    while(!stk.empty()) {
        cout << stk.top()+1 << " ";
        stk.pop();
    }
}

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);

    for(int i = 1; i <= m; ++i) {
        int v, u; cin >> v >> u;
        --v; --u;
        g[v].push_back(u);
    }

    top_sort(g);
    return 0;
}
