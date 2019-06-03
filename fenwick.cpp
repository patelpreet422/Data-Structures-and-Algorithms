#include <iostream>
#include <vector>
using namespace std;

//0-based indexing
struct Fenwick
{
	vector<int> bit;
	Fenwick() = delete;
	Fenwick(size_t s)
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
			int parent = i + (i&-i);
			if(parent <= vec.size())
				bit[parent] += bit[i];
		}
	}

	int sum(int i)
	{
		int res = 0;
		++i;
		for(; i > 0; i -= (i&-i))
			res += bit[i];
		return res;
	}

	int sum(int i, int j)
	{
		return sum(j) - sum(i-1);
	}

	void add(int i, int delta)
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
