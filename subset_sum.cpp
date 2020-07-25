#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;
using ul = unsigned long;

bool subset_sum(vector<int> vec, int i, int target) {
  if (target == 0)
    return true;
  if (target < 0 || i == vec.size())
    return false;
  return subset_sum(vec, i + 1, target - vec[i]) ||
         subset_sum(vec, i + 1, target);
}

int main() {
  vector<int> vec{1, 2, 3};
  cout << subset_sum(vec, 0, 6) << '\n';
  return 0;
}
