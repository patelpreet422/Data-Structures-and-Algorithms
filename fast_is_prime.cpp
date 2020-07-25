#include <iostream>
using namespace td;
bool isPrime(unsigned long k) {
  if (k < 1)
    return false;
  if (k <= 3)
    return true;
  if (k % 2 == 0 || k % 3 == 0)
    return false;
  for (unsigned long i = 5, dx = 2; i * i <= k;
       i = i + dx, dx = (dx == 2) ? 4 : 2) {
    if (k % i == 0)
      return false;
  }
  return true;
}

int main() {
  unsigned long k = 0x1010155D3FF7DC3;
  cout << boolalpha << isPrime(k) << endl;
  return 0;
}
