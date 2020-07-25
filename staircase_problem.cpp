#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline constexpr int len_i(int i) {
  int count = 0;
  while (i) {
    i = i / 10;
    ++count;
  }
  return count;
}

int ways_to_come_down(int stairs, const vector<int> &steps, string &chosen) {
  if (stairs < 0)
    return 0;
  if (stairs == 0) {
    cout << chosen << '\n';
    return 1;
  }
  int ways = 0;
  for (const auto &e : steps) {
    chosen += to_string(e);
    ways += ways_to_come_down(stairs - e, steps, chosen);
    int l = len_i(e);
    chosen.erase(chosen.size() - l, l);
  }
  return ways;
}

int ways_to_come_down(int stairs, const vector<int> &steps) {
  string chosen = "";
  return ways_to_come_down(stairs, steps, chosen);
}

int main() {
  int stairs = 5;
  vector<int> steps = {1, 2};
  cout << ways_to_come_down(stairs, steps) << '\n';
  return 0;
}
