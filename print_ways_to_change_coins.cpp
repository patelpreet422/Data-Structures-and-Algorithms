#include <iostream>
#include <vector>
using namespace std;

bool make_change(vector<int> &coins, int target, string chosen, int i) {
  if (i >= coins.size())
    return false;
  if (target == 0) {
    cout << chosen << '\n';
    return true;
  }

  if (target < 0)
    return false;

  return make_change(coins, target - coins[i],
                     chosen + " " + to_string(coins[i]), i) |
         make_change(coins, target, chosen, i + 1);
}

int main() {
  vector coins{2, 3, 5, 7};
  string chosen = "";
  make_change(coins, 8, chosen, 0);
  return 0;
}
