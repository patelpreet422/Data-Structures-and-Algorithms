#include <iostream>
#include <vector>
using namespace std;

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
    Fenwick(const vector<T>& vec)
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

    T sum(T i)
    {
        T res = 0;
        ++i;
        for(; i > 0; i -= (i&-i))
            res += bit[i];
        return res;
    }

    T sum(size_t i, size_t j)
    {
        return sum(j) - sum(i-1);
    }

    void add(size_t i, T delta)
    {
        ++i;
        for(; i <= bit.size(); i += (i&-i))
            bit[i] += delta;
    }
};

int main()
{
	vector<int> vec {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
	Fenwick t(vec);

	for(int i = 0; i < vec.size(); ++i)
		for(int j = i; j <vec.size(); ++j)
		{
			cout << "i: " << i << ", j: " << j << " " <<  t.sum(i, j) << '\n';
		}
	//for(auto e: t.bit) cout << e << " ";
	return 0;
}
