#include <vector>
#include <iostream>
#include <climits>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<int>> sparse_table(vector<int>& vec)
{
    int n = vec.size();
    vector<vector<int>> st(ceil(log2(n+1)), vector<int>(n));
    for(int i = 0; i < n; ++i) st[0][i] = vec[i];
    for(int i = 1; i < st.size(); ++i)
        for(int j = 0; j + (1 << i) <= n; ++j)
            st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i-1))]);
    return st;
}

int query(vector<vector<int>>& st, int l, int r)
{
    int p = 31 - __builtin_clz(r-l);
    return min(st[p][l], st[p][r - (1 << p) + 1]);
}

int main()
{
    int n; cin >> n;
    vector<int> vec(n);
    for(auto& e: vec) cin >> e;
    auto st = sparse_table(vec);
    int q; cin >> q;
    while(q--)
    {
        int l, r; cin >> l >> r;
        cout << query(st, l, r) << '\n';
    }
    return 0;
}
