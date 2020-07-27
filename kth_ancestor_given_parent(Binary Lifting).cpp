#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class TreeAncestor {
public:
  vector<vector<int>> dp;

  void construct(vector<int> &parent) {
    int n = parent.size();
    dp.assign(n, vector<int>(log2(n) + 1, -1));

    for (int i = 0; i < n; ++i) {
      dp[i][0] = parent[i];
      for (int j = 1; j < dp[0].size(); ++j) {
        if (dp[i][j - 1] == -1)
          break;
        dp[i][j] = dp[dp[i][j - 1]][j - 1];
      }
    }

    for (int i = 0; i < n; ++i) {
      cout << "parent[" << i << "]: ";
      for (int j = 0; j < dp[0].size(); ++j) {
        cout << dp[i][j] << ' ';
      }
      cout << '\n';
    }
  }

  TreeAncestor(int n, vector<int> &parent) {
    construct(parent);
  }

  int getKthAncestor(int node, int k) {
    int l = k;
    k = 0;
    int anc = node;
    for (int i = dp[0].size(); i >= 0; --i) {
      if ((k | (1 << i)) <= l and dp[anc][i] != -1) {
        anc = dp[anc][i];
        k |= (1 << i);
      }
    }
    return (l != k) ? -1 : anc;
  }
};

int main() {
  vector<int> parent{-1, 0, 0, 1, 1, 2, 2};
  TreeAncestor solution(parent.size(), parent);
  int ans = solution.getKthAncestor(3, 1);
  cout << ans << '\n';
  return 0;
}
