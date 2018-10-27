#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

template <typename T>
T set_rightmost_bit_off(T k)
{
	return k&(k-1);
}

template <typename U, typename T>
U calculate_sum(T arr, U idx)
{
	U res = 0;
	while(idx)
	{
		res += arr[idx-1];
		idx = set_rightmost_bit_off(idx);
	}
	return res;
}

template <typename T>
T make_BIT(T vec)
{
	T BIT(vec.size());
	for(size_t i = 0; i < vec.size(); ++i)
	{
		auto idx = i+1;
		while(idx <= vec.size())
		{
			BIT[idx-1] += vec[i];
			idx += idx & (-idx);
		}
	}
	return BIT;
}

int naive(vector<int> vec, int k)
{
	int s = 0;
	for(int i = 0; i < k; ++i)
	{
		s += vec[i];
	}
	return s;
}

int max_sum(vector<int> vec)
{
	int s = 0;
	for(int i: vec)
	{
		s += i;
		if(s <= 0)
		    s = 0;
	}
	return s;
}

int main()
{
	vector<int> vec {7, -4, 15, -22, 13, -3};
	
	auto BIT = make_BIT(vec);
	
	
	
	cout << max_sum(vec) << '\n';
  return 0;
}
