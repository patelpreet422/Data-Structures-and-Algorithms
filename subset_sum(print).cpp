#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;
using ul = unsigned long;

bool subset_sum(vector<int> vec, int i, int target, string chosen) {
  if (target == 0) {
    cout << chosen << '\n';
    return true;
  }

  if (target < 0 || i == vec.size())
    return false;

  // || is used to for short-circuit evaluation
  // i.e, || will not check second boolean expression is first expression
  // returns true | will check second boolean expression even if first
  // expression is true

  return subset_sum(vec, i + 1, target - vec[i],
                    chosen + " + " + to_string(vec[i])) |
         subset_sum(vec, i + 1, target, chosen);
}

int main() {
  vector<int> vec{1, 2, 3, 5, 4, 6, 3};
  subset_sum(vec, 0, 7, "");
  return 0;
}
