#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <numeric>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

//0-based indexing
template <typename T>
struct Fenwick
{
    vector<T> bit;
    Fenwick() = delete;
    explicit Fenwick(size_t s)
    {
        bit.resize(s+1, 0);
    }

    //O(n) construction
    Fenwick(const vector<int>& vec)
    {
        bit = {0};
        bit.insert(bit.begin()+1, vec.begin(), vec.end());
        for(size_t i = 1; i <= vec.size(); ++i)
        {
            int64_t parent = i + (i&-i);
            if(parent <= vec.size())
                bit[parent] += bit[i];
        }
    }

    T sum(int i)
    {
        T res = 0;
        ++i;
        for(; i > 0; i -= (i&-i))
            res += bit[i];
        return res;
    }

    T sum(int i, int j)
    {
        return sum(j) - sum(i-1);
    }

    void add(int i, int64_t delta)
    {
        ++i;
        for(; i <= bit.size(); i += (i&-i))
            bit[i] += delta;
    }
};

int64_t inversion(vector<int64_t> arr)
{
    int64_t s = 0;
    auto vec = arr;
    sort(begin(vec), end(vec));
    unordered_map<int64_t, int> index;
    Fenwick<int64_t> bit(vec.size());

    for(int i = 0; i < vec.size(); ++i)
        index[vec[i]] = i;

    for(auto e: arr)
    {
        auto idx = index[e];
        s += bit.sum(idx, vec.size()-1);
        bit.add(idx, 1);
    }

    return s;
}

int main()
{
    int64_t t; cin >> t;
    while(t--)
    {
        int64_t n; cin >> n;
        vector<int64_t> vec(n);
        for(auto& e: vec) cin >> e;
        cout << inversion(vec) << '\n';
    }
    return 0;
}
