#include <cstdio>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct segment_tree
{
    vector<int64_t> lo, hi, delta, data, raw_data;
    explicit segment_tree(vector<int64_t> vec)
    {
        raw_data = std::move(vec);
        auto n = raw_data.size();
        lo = vector<int64_t>(4*n+1, -1);
        hi = vector<int64_t>(4*n+1, -1);
        delta = vector<int64_t>(4*n+1, 0);
        data = vector<int64_t>(4*n+1, 0);
        init(1, 0, n-1);
        build(1, 0, n-1);
    }

    void init(int64_t n, int64_t l, int64_t r)
    {
        if(l == r) {
            lo[n] = hi[n] = l;
        } else {
            int64_t mid = (l+r)/2;
            lo[n] = l;
            hi[n] = r;
            init(2*n, l, mid);
            init(2*n+1, mid+1, r);
        }
    }

    void update(int64_t n)
    {
        data[n] = min(data[2*n]+delta[2*n], data[2*n+1]+delta[2*n+1]);
    }

    void prop(int64_t n)
    {
        delta[2*n] += delta[n];
        delta[2*n+1] += delta[n];
        delta[n] = 0;
    }

    void build(int64_t n, int64_t l, int64_t r)
    {
        if(l == r) {
            data[n] = raw_data[l];
        } else {
            int64_t mid = (l+r)/2;
            build(2*n, l, mid);
            build(2*n+1, mid+1, r);
            //data[n] = min(data[2*n], data[2*n+1]);
            update(n);
        }
    }

    int64_t query(int64_t n, int64_t l, int64_t r)
    {
        // partial overlap
        if(r < lo[n] || hi[n] < l) return numeric_limits<int64_t>::max();
        // total overlap
        if(l <= lo[n] && hi[n] <= r) return data[n]+delta[n];
        prop(n);
        int64_t lr = query(2*n, l, r);
        int64_t rr = query(2*n+1, l, r);
        update(n);
        return min(lr, rr);
    }

    int64_t query(int64_t l, int64_t r)
    {
        return query(1, l, r);
    }

    void increment(int64_t n, int64_t l, int64_t r, int64_t del)
    {
        // partial overlap
        if(r < lo[n] || hi[n] < l) return;
        // total overlap
        if(l <= lo[n] && hi[n] <= r) {
            delta[n] += del;
            return;
        }

        prop(n);
        increment(2*n, l, r, del);
        increment(2*n+1, l, r, del);
        update(n);
    }

    void increment(int64_t l, int64_t r, int64_t del)
    {
        increment(1, l, r, del);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int64_t n, q; cin >> n >> q;
    vector<int64_t> vec(n);
    for(auto& e: vec) cin >> e;
    segment_tree st(vec);

    while(q--) {
        int64_t l, r; cin >> l >> r;
        st.increment(l, l, -vec[l]+r);
        vec[l] = r;
    }

    for(int i = 0; i < vec.size(); ++i) {
        for(int j = i; j < vec.size(); ++j) {
            cout << "min[" << i << ", " << j << "]: " << st.query(i, j) << '\n';
        }
    }
    return 0;
}
