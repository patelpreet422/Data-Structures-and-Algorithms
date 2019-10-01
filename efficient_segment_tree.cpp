#include <iostream>
#include <vector>
using namespace std;

vector<int> tree;
size_t n;

void init(const vector<int>& vec) {
    n = vec.size();
    tree.assign(n << 1, 0);
    for(int i = 0; i < n; ++i)
        tree[i + n] = vec[i];
}

void build(const vector<int>& vec) {
    init(vec);
    for(int i = n-1; i > 0; --i)
        tree[i] = tree[i << 1] + tree[(i << 1) | 1];
}

void build(int s) {
    n = s;
    tree.assign(s << 1, 0);
}

int query(int l, int r) { // min[l, r)
    l += n; r += n;
    int res = 0;
    while(l < r) {
        if(l & 1) res = res + tree[l++];
        if(r & 1) res = res + tree[--r];
        l >>= 1; r >>= 1;
    }
    return res;
}

int query(int l) {
    int res = 0;
    l += n;
    while(l > 0) {
        res = res + tree[l];
        l >>= 1;
    }
    return res;
}

void modify(int l, int del) { // modify[l, l]
    l = n;
    tree[l] += del;
    while(l > 1) {
        tree[l>>1] = tree[l] + tree[l ^ 1];
        l >>= 1;
    }
}

void modify(int l, int r, int del) { // modify[l, r)
    l += n; r += n;
    while(l < r) {
        if(l & 1) tree[l++] += del;
        if(r & 1) tree[--r] += del;
        l >>= 1; r >>= 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t t; cin >> t;
    while(t--) {
        size_t l, c; cin >> l >> c;
        build(l);
        while(c--) {
            int64_t p, q, v;
            cin >> p >> q >> v;
            modify(p, q+1, v);
        }
        cin >> c;
        while(c--) {
            int64_t s; cin >> s;
            cout << query(s) << '\n';
        }
    }   return 0;
}
