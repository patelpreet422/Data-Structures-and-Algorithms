#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dec(string s, int b)
{
  int r = 0, p = 1;
  for(int i = s.size()-1; i>=0; --i)
  {
    r += (s[i]-'0')*p;
    p *= b;
  }
  return r;
}

string radix(int d, int b)
{
  string r;
  while(d)
  {
    r = to_string(d%b) + r;
    d /= b;
  }
  return r;
}

int main()
{
  int d = 10; 
  cout << radix(d, 8) << '\n';
  return 0;
}
