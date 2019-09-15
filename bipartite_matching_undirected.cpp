#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isBiPartite(const vector<vector<int>>& g) {
    vector<int> color(g.size(), -1);
    bool bipartite = true;
    queue<int> q;
    for(int i = 0; i < g.size(); ++i) {
        if(color[i] == -1) {
            q.push(i);
            color[i] = 1;
            while(!q.empty()) {
                int v = q.front(); q.pop();
                for(auto c: g[v]) {
                    if(color[c] == -1) {
                        q.push(c);
                        color[c] = color[v]^1;
                    } else {
                        bipartite &= (color[c] != color[v]);
                    }
                }
            }
        }
    }
    return bipartite;
}

int main() {
    int t; cin >> t;
    for(int i = 1; i <= t; ++i) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n, vector<int>{});
        for (int i = 1; i <= m; ++i) {
            int v1, v2;
            cin >> v1 >> v2;
            g[v1 - 1].push_back(v2 - 1);
            g[v2 - 1].push_back(v1 - 1);
        }

        cout << "Scenario #" << i << ":\n";
        if(!isBiPartite(g)) cout << "Suspicious bugs found!\n";
        else cout << "No suspicious bugs found!" << '\n';
    }
    return 0;
}
