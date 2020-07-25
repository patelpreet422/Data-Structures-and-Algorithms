#include <boost/lambda/lambda.hpp>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// Russian peasant multiplication (recursive)
// O(log(a))
uint mul(uint a, uint b) {
  if (a == 0 || b == 0)
    return 0;
  if (a == 1)
    return b;
  return mul(a >> 1, b << 1) + (a & 1 ? b : 0);
}

// Russian peasant multiplication (iterative)
// O(log(min(a, b)))
uint mul_(uint a, uint b) {
  if (a == 0 || b == 0)
    return 0;
  if (a > b)
    swap(a, b);

  uint r = 0;
  while (a > 0) {
    r += (a & 1) ? b : 0;
    a >>= 1;
    b <<= 1;
  }
  return r;
}

int main() {
  int a = 12, b = 20;
  cout << mul(a, b) << '\n';
  cout << mul_(a, b) << '\n';
  return 0;
}
