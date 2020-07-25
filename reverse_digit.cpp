#include <iostream>

using namespace std;

int reverse_int(int k) {
  int i = 0;
  while (k) {
    i = i * 10 + k % 10;
    k /= 10;
  }
  return i;
}

int main() {
  cout << reverse_int(123456) << endl;
  return 0;
}
