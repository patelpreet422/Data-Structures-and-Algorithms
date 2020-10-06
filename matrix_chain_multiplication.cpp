#include <bits/stdc++.h>

using namespace std;

/*
https://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/Dynamic/chainMatrixMult.htm
*/

void printBrace(vector<vector<int>> &parent, int i, int j, char &c) {
  if (i == j) {
    cout << c;
    ++c;
  } else {
    cout << "(";
    int k = parent[i][j];
    printBrace(parent, i, k, c);
    printBrace(parent, k + 1, j, c);
    cout << ")";
  }
}

int solve(const vector<int> &v) {
  int n = v.size() - 1;

  vector<vector<int>> dp(n, vector<int>(n, 0));
  vector<vector<int>> parent(n, vector<int>(n, 0));

  for (int g = 1; g < n; ++g) {
    for (int i = 0, j = g; j < n; ++i, ++j) {
      dp[i][j] = INT_MAX;
      for (int k = i; k < j; ++k) {

        if (dp[i][j] > dp[i][k] + dp[k + 1][j] + v[i] * v[k + 1] * v[j + 1]) {
          dp[i][j] = dp[i][k] + dp[k + 1][j] + v[i] * v[k + 1] * v[j + 1];
          parent[i][j] = k;
        }
      }
    }
  }

  char c = 'A';
  printBrace(parent, 0, n - 1, c);
  cout << "\n";

  return dp[0][n - 1];
}

int main() {
  vector<int> v{10, 20, 30, 40, 30};
  cout << solve(v) << '\n';
  return 0;
}
