#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// this lower bound return the result same as std::lower_bound but instead of pointers it returns tge index

// this algorithm constructs the index at which the key is present starting from msb to lsb
// it is also called meta binary search or one sided search 
// I prefer to call it index constructive search because actually we are constructing the index at which the key is present smartly
// rather than searching for the key itself
int locate(vector<int>& A, int k)
{
  int p = 0;
  int msb = ceil(log2(A.size()))-1;
  while(msb>=0)
  {
    if(A[p] == k) return p;
    int np = p | (1 << msb);
    if(np < A.size() && A[np] <= k)
      p = np;
    --msb;
  }
  return (A[p]==k)? p: ((k<A[0])?0:p+1);
}
int main()
{
  vector<int> vec{1, 5, 10, 15, 20, 25, 30, 35};
  while(true){
    int n; cin >> n;
    cout << "lower_bound: " << locate(vec, n) << '\n';
  }
  return 0;
}
