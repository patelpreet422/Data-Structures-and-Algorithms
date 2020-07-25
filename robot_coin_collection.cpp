#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;
using ul = unsigned long;

unsigned coin_collection(vector<vector<unsigned>> coins) {
  vector<vector<unsigned>> value(
      coins.size(),
      vector<unsigned>(coins[0].size(), numeric_limits<int>::max()));

  value[0][0] = coins[0][0];
  for (int i = 1; i < coins[0].size(); ++i) {
    value[0][i] = value[0][i - 1] + coins[0][i];
  }

  for (int i = 1; i < coins.size(); ++i) {
    value[i][0] = value[i - 1][0] + coins[i][0];
  }

  for (int i = 1; i < coins.size(); ++i) {
    for (int j = 1; j < coins[0].size(); ++j) {
      if (value[i - 1][j] > value[i][j - 1]) {
        value[i][j] = value[i - 1][j] + coins[i][j];

      } else {
        value[i][j] = value[i][j - 1] + coins[i][j];
      }
    }
  }

  // path construction
  stack<unsigned> elem;
  int i = coins.size() - 1, j = coins[0].size() - 1;
  for (; i >= 1 && j >= 1;) {
    elem.push(coins[i][j]);
    if (value[i - 1][j] == value[i][j] - coins[i][j]) {
      --i;
    } else {
      --j;
    }
  }

  while (i > 0)
    elem.push(coins[i--][0]);
  while (j >= 0)
    elem.push(coins[0][j--]);

  while (!elem.empty()) {
    cout << elem.top() << " ";
    elem.pop();
  }

  cout << '\n';
  return value[coins.size() - 1][coins[0].size() - 1];
}

int main() {
  vector<vector<unsigned>> coins{{0, 0, 0, 0, 1, 0},
                                 {0, 1, 0, 1, 0, 0},
                                 {0, 0, 0, 1, 0, 1},
                                 {0, 0, 1, 0, 0, 1},
                                 {1, 0, 0, 0, 1, 0}};
  cout << coin_collection(coins) << '\n';
  return 0;
}
