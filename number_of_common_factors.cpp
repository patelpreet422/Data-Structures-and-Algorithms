#include <iostream>
using namespace std;

int64_t gcd(int64_t a, int64_t b)
{
  while(b)
  {
    int64_t c = b;
    b = a%b;
    a = c;
  }
  return a;
}

int64_t common_factors(int64_t a, int64_t b)
{
  auto c = gcd(a, b);
  int64_t n = 0;
  for(int64_t i = 1; i*i <= c; ++i)
  {
    if(c%i == 0)
    {
      if(c/i == i) ++n;
      else n += 2;
    }
  }
  return n;
}

int main()
{
  int64_t a, b; cin >> a >> b;
  cout << common_factors(a, b) << '\n';
  return 0;
}
