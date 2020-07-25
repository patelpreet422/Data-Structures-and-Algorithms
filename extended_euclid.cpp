#include <iostream>
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

int main() {
  int x = 0, y = 0;
  int a = 24, b = 48;
  int g = gcd(a, b, x, y);
  cout << x << "*" << a << " + " << y << "*" << b << " = " << g << '\n';
  return 0;
}
