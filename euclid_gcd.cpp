#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int gcd(int a, int b) {
  while (b)
    a = exchange(b, a % b);
  return a;
}
