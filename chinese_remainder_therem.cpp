#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int gcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    int x1, y1;
    int g = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
  }
}

int inv(int a, int m) {
  int x, y;
  gcd(a, m, x, y);
  return (x + m) % m;
}

int chinese(const vector<pair<int, int>> &vec) {
  int prod = accumulate(begin(vec), end(vec), 1,
                        [](auto a, auto b) { return a * b.second; });

  int s = 0;
  for (auto &&p : vec) {
    int q = prod / p.second;
    s += p.first * inv(q, p.second) * q;
    cout << inv(q, p.second) << '\n';
  }
  return s % prod;
}

int main() {
  vector<pair<int, int>> vec{{15, 27}, {16, 20}};
  cout << chinese(vec) << '\n';
  return 0;
}
