#include "iostream"
#include "algorithm"
#include "numeric"
#include "vector"
#include "list"
#include "unordered_map"
#include "iterator"
using namespace std;

int64_t lis_size(const vector<int64_t>& vec)
{
    // stores indices of candidate incresing subsequence
    vector<int64_t> res(vec.size()+1, numeric_limits<int64_t>::max());
    int64_t len = 0;
    for(int64_t i = 0; i < vec.size(); ++i)
    {
        auto d = upper_bound(res.begin(), res.end(), vec[i]) - res.begin();
        if(res[d] == numeric_limits<int64_t>::max()) ++len;
        res[d] = vec[i];
    }

  return len;
}

int main()
{
    vector<int64_t> vec;
    copy(istream_iterator<int>(cin), istream_iterator<int>{}, back_inserter(vec));
    cout << lis_size(vec);
    cout << '\n';
    return 0;
}
