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
    explicit Fenwick(const vector<T>& vec)
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

    //initilizer_list ctor
    Fenwick(initializer_list<T> it)
    {
        bit = {0};
        bit.insert(bit.begin()+1, it.begin(), it.end());
        for(size_t i = 1; i <= it.size(); ++i)
        {
            int64_t parent = i + (i&-i);
            if(parent <= it.size())
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

    // O(log(n)*log(n)) lower bound 
    // finds lower_bound of v prefix_sum of vector 
    int lower_bound(int v)
    {
      int l = 0, h = bit.size()-1;
      while(l<h)
      {
        int m =(l+h)/2;
        if(v<=sum(m)) h = m;
        else l = m+1;
      }
      return l;
    }

    friend ostream& operator<<(ostream& os, const Fenwick<T>& bit)
    {
        for(auto e: bit) os << e << " ";
        return os;
    }

    typename vector<T>::iterator begin() {  return bit.begin(); }
    typename vector<T>::iterator end() { return bit.end(); }

};

int main()
{
	vector<int> vec {8, 2, 10, 100, 1, 2};
	Fenwick<int> t(vec);
  cout << t.lower_bound(8) << '\n';
	return 0;
}
