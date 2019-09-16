#include "iostream"
#include "vector"
using namespace std;

vector<int64_t> tree;

void init(int64_t n) {
    tree = vector<int64_t>(n+1, 0);
}

void add(int64_t i, int64_t del) {
    for(++i; i < tree.size(); i += (i & -i)) {
        tree[i] += del;
    }
}

void range_add(int64_t l, int64_t r, int64_t del) {
    add(l, del);
    add(r+1, -del);
}

int64_t point_query(int64_t i) {
    int64_t s = 0;
    for(++i; i > 0; i -= (i & -i)) {
        s += tree[i];
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t t; cin >> t;
    while(t--) {
        size_t n, c; cin >> n >> c;
        init(n);
        while(c--) {
            int64_t p, q, v;
            cin >> p >> q >> v;
            range_add(p, q, v);
        }
        cin >> c;
        while(c--) {
            int64_t n; cin >> n;
            cout << point_query(n) << '\n';
        }
    }

    return 0;
}

