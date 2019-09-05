#include "iostream"
#include "algorithm"
#include "numeric"
#include "vector"
#include "list"
#include "unordered_map"
#include "iterator"
using namespace std;

vector<int64_t> lis_size(const vector<int64_t>& vec)
{
    // stores indices of candidate incresing subsequence
    vector<int64_t> res(vec.size()+1, numeric_limits<int64_t>::max());
    unordered_map<int64_t, int64_t> parent;
    int64_t len = 0;
    for(int64_t i = 0; i < vec.size(); ++i)
    {
        auto d = lower_bound(res.begin(), res.end(), vec[i]) - res.begin();
        if(res[d] == numeric_limits<int64_t>::max()) ++len;
        res[d] = vec[i];
        if(d == 0) parent[res[d]] = -1;
        else parent[res[d]] = res[d-1];
    }

    vector<int64_t> is(len);
    int64_t k = len;
    for(int64_t i = res[len-1]; i >= 0; i = parent[i])
    {
        is[--len] = i;
    }

  return is;
}

int main()
{
    vector<int64_t> vec;
    copy(istream_iterator<int>(cin), istream_iterator<int>{}, back_inserter(vec));
    for(auto e: lis_size(vec)) cout << e << " ";
    return 0;
}
