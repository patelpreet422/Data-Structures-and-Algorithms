#include "algorithm"
#include "iostream"
#include "numeric"
#include "vector"
using namespace std;

template <typename T> int LCSS_r(T &&c1, T &&c2, size_t s1, size_t s2) {
  if (s1 == 0 || s2 == 0)
    return 0;
  if (c1[s1 - 1] == c2[s2 - 1])
    return 1 + LCSS(c1, c2, s1 - 1, s2 - 1);
  else
    return max(LCSS(c1, c2, s1, s2 - 1), LCSS(c1, c2, s1 - 1, s2));
}

template <typename T> int LCSS_r(T &&c1, T &&c2) {
  return LCSS(c1, c2, c1.size(), c2.size());
}

template <typename T> int LCSS(T &&s1, T &&s2) {
  /*              0       1       2       3
   *          |   X   | s1[0] | s2[1] | s2[3]
   *     -----|-------|-------|-------|-------
   *  0   X   |   0   |   0   |   0   |   0
   *  1  s2[0]|   0   |       |       |
   *  2  s2[1]|   0   |       |       |
   *  3  s2[2]|   0   |       |       |
   */
  vector<vector<int>> dp_table{s2.size() + 1, vector<int>(s1.size() + 1, 0)};
  for (int i = 1; i <= s2.size(); ++i) {
    for (int j = 1; j <= s1.size(); ++j) {
      dp_table[i][j] = ((s2[i - 1] == s1[j - 1])
                            ? dp_table[i - 1][j - 1] + 1
                            : max(dp_table[i][j - 1], dp_table[i - 1][j]));
    }
  }

  // below work is needed for finding the exact string
  int lcss = dp_table[s2.size()][s1.size()];

  remove_reference_t<T> lcs(lcss + 1, -1);
  int i = s2.size(), j = s1.size();
  while (i > 0 && j > 0) {
    // if current character in s1 and s2 are same, then include this character
    // in LCS[]
    if (s2[i - 1] == s1[j - 1]) {
      lcs[lcss - 1] = s2[i - 1]; // Put current character in result
      i--;
      j--;
      lcss--; // reduce values of i, j and index
    }
    // compare values of L[i-1][j] and L[i][j-1] and go in direction of greater
    // value.
    else if (dp_table[i - 1][j] > dp_table[i][j - 1])
      i--;
    else
      j--;
  }

  for (auto &&e : lcs) {
    if (e != -1)
      cout << e << " ";
  }
  return dp_table[s2.size()][s1.size()];
}

int main() {
  string v1, v2;
  cin >> v1 >> v2;
  cout << LCSS(v1, v2) << '\n';
  return 0;
}
