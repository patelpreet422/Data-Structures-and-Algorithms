#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;
using ul = unsigned long;

vector<ul> prime_factors(ul k) {
  vector<ul> p_factors;
  for (int i = 2; i * i <= k; ++i) {
    bool isfactor = false;
    while (k % i == 0) {
      k /= i;
      isfactor = true;
    }
    if (isfactor)
      p_factors.push_back(i);
  }
  if (k != 1)
    p_factors.push_back(k);
  return p_factors;
}

int main() {
  for (auto e : prime_factors(15))
    cout << e << ' ';
  return 0;
}
