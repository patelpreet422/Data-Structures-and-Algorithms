#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int lengthofLIS(const vector<int> &v) {
  vector<int> lis;

  for (auto e : v) {
    // lower_bound return the position of the element that does not satisfy the
    // predicate
    auto ub = lower_bound(begin(lis), end(lis), e,
                          [](auto a, auto b) { return a < b; }) -
              begin(lis);
    if (ub == lis.size()) {
      lis.push_back(e);
    } else {
      lis[ub] = e;
    }
  }
  return lis.size();
}

int main() {
  vector<int> v{5, 15, 8, 7, 4, 10, 20, 19, 7, 25, 29, 12};
  cout << lengthofLIS(v) << '\n';

  return 0;
}
