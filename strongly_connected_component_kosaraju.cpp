#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <limits>
#include <unordered_map>

using namespace std;

stack<int> top_sort_(vector<vector<int>>& g) {
    int n = g.size();
    stack<int> frontier;
    vector<bool> visited(g.size(), false);
    stack<int> ordered;

    for (auto i = 0; i < g.size(); ++i) {
        if (!visited[i]) {
            frontier.push(i);
            visited[i] = true;

            while (!frontier.empty()) {
                int top = frontier.top();
                frontier.pop();
                if (top < 0) {
                    ordered.push(-top-1);
                } else {
                    // before all the children are pushed onto the stack we push -top-1
                    // to mark that when we see this node we are sure that all the children
                    // of top are processed
                    frontier.push(-top - 1);

                    for (auto c: g[top]) {
                        if (!visited[c]) {
                            visited[c] = true;
                            frontier.push(c);
                        }
                    }
                }
            }
        }
    }

    return ordered;
}

vector<vector<int>> reverse_edge(vector<vector<int>>& g)
{
    vector<vector<int>> res(g.size());
    for(auto i = 0; i < g.size(); ++i)
    {
        for(auto e: g[i])
            res[e].push_back(i);
    }
    return res;
}

void dfs(const vector<vector<int>>& g, int s, vector<int>& visited, unordered_map<int, vector<int>>& component, int c) {
    stack<int> st;
    st.push(s);
    while(!st.empty()) {
        int top = st.top();
        st.pop();
        visited[top] = true;
        component[c].push_back(top);

        for(auto child: g[top]) {
            if(!visited[child]) {
                visited[child] = true;
                st.push(child);
            }
        }
    }
}

void kosaraju(vector<vector<int>>& g) {
    vector<vector<int>> rg = reverse_edge(g);
    stack<int> ordered = top_sort_(rg);

    vector<int> visited(g.size(), false);
    unordered_map<int, vector<int>> component;
    // number of components
    int c = 0;

    while(!ordered.empty()) {
        int top = ordered.top();
        ordered.pop();
        if(!visited[top]) {
            
            //dfs(g, top, visited, component, c);
            cout << top << " ";
            ++c;
        }
    }

    /*
    for(auto&& p: component)
    {
        cout << p.first << ": ";
        for(auto e: p.second) cout << e << " ";
        cout << '\n';
    }
    */
    
}

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);

    for(int i = 1; i <= m; ++i) {
        int v, u; cin >> v >> u;
        g[v].push_back(u);
    }

    kosaraju(g);
    return 0;
}
