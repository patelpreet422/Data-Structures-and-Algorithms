#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void prime_factors(int k) {
  while (k % 2 == 0) {
    cout << 2 << ", ";
    k /= 2;
  }
  int i = 3;
  while (k > 1) {
    while (k % i == 0) {
      cout << i << ", ";
      k /= i;
    }
    i += 2;
  }
}

void factors(int k) {
  for (int i = 1; i * i <= k; ++i) {
    if (k % i == 0) {
      cout << i << ", " << k / i << '\n';
    }
  }
}

int smallest_divisor(int k) {
  if (k % 2 == 1) {
    for (int j = 3; j * j <= k; j += 2) {
      if (k % j == 0)
        return j;
    }
  }
  return 2;
}
/*
vector<unsigned long> primes_upto(unsigned long k)
{
  vector<unsigned long> primes;
  if(2 <= k)
    primes.push_back(2);
  if(3 <= k)
    primes.push_back(3);

  for(unsigned long i = 5, dx = 2; i <= k; i = i + dx, dx = (dx == 2) ? 4: 2)
    {
      bool divides = false;
      for(unsigned long j = 0; j < primes.size() && primes[j]*primes[j] <= i;
++j)
        {
          if(i%primes[j] == 0) {
              divides = true;
              break;
            }
        }
      if(!divides) primes.push_back(i);
    }
  return primes;
}
*/

vector<unsigned long> primes_upto(unsigned long k) {
  vector<unsigned long> primes;
  if (2 <= k)
    primes.push_back(2);
  if (3 <= k)
    primes.push_back(3);

  for (unsigned long i = 5, dx = 2; i <= k;
       i = i + dx, dx = (dx == 2) ? 4 : 2) {
    bool divides = false;
    for (auto p : primes) {
      if (p * p <= i) {
        if (i % p == 0) {
          divides = true;
          break;
        }
      } else {
        break;
      }
    }
    if (!divides)
      primes.push_back(i);
  }
  return primes;
}

int main() {
  unsigned long k = 100000;

  int j = 1;

  for (auto i : primes_upto(k)) {
    cout << j << ": " << i << "\n";
    ++j;
  }
  //  cout << primes_upto(k).size() << '\n';
  return 0;
}
