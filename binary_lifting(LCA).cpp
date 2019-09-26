#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> previsit;
vector<vector<int>> up;
vector<int> postvisit;
vector<vector<int>> adj;
int n;
int timer = 0;

void dfs(int v, int p) {
    previsit[v] = ++timer;
    up[v][0] = p;
    for(int i = 1; i < up[0].size(); ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
    }

    for(auto child: adj[v]) {
        if(child != p) {
            dfs(child, v);
        }
    }

    postvisit[v] = ++timer;
}

void init() {
    previsit.assign(n, -1);
    postvisit.assign(n, -1);
    up.assign(n, vector<int>(ceil(log2(n)+1), -1));
    adj.assign(n, vector<int>());
}

bool is_ancestor(int v, int u) {
    return previsit[v] <= previsit[u] && postvisit[v] >= postvisit[u];
}

int lca(int v, int u) {
    if(is_ancestor(v, u)) return v;
    if(is_ancestor(u, v)) return u;
    for(int i = up[0].size(); i >= 0; --i) {
        if(!is_ancestor(up[v][i], u))
            v = up[v][i];
    }
    return up[v][0];
}

void preprocess() {
    dfs(0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    init();
    for(int v = 0; v < n; ++v) {
        int m; cin >> m;
        while(m--) {
            int u; cin >> u;
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
    }

    preprocess();
    int q; cin >> q;
    while(q--) {
        int v, w;
        cin >> v >> w;
        cout << lca(v, w) << '\n';
    }
    return 0;
}
