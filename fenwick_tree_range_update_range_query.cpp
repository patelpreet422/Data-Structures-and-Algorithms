#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int64_t> b1;
vector<int64_t> b2;

void make(int64_t n) {
    b1 = vector<int64_t>(n + 1, 0);
    b2 = vector<int64_t>(n + 1, 0);
    for(int64_t i = 1; i < b1.size(); ++i) {
        b1[i] += 0;
        int64_t p = i + (i & -i);
        if(p < b1.size()) {
            b1[p] += b1[i];
        }
    }
}

void add(vector<int64_t>& bit, int64_t i, int64_t del) {
    for(++i; i < bit.size(); i += (i & -i)) {
        bit[i] += del;
    }
}

void range_add(int64_t l, int64_t r, int64_t del) {
    add(b1, l, del);
    add(b1, r+1, -del);
    add(b2, l, del*(l-1));
    add(b2, r+1, -del*r);
}

int64_t sum(vector<int64_t>& bit, int64_t i) {
    int64_t s = 0;
    for(++i; i > 0; i -= (i & -i)) {
        s += bit[i];
    }
    return s;
}

int64_t prefix_sum(int64_t i) {
    return sum(b1, i)*i - sum(b2, i);
}

int64_t range_sum(int64_t l, int64_t r) {
    return prefix_sum(r) - prefix_sum(l-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t t; cin >> t;
    while(t--) {
        size_t n, c; cin >> n >> c;
        make(n);
        while(c--) {
            int64_t o;
            cin >> o;
            if (o == 0) {
                int64_t p, q, v;
                cin >> p >> q >> v;
                range_add(p-1, q-1, v);
            } else {
                int64_t p, q;
                cin >> p >> q;
                cout << range_sum(p-1, q-1) << '\n';
            }
        }
    }

    return 0;
}

