#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  string a; 
  string b;
  int lcs(int i, int j, int l, string &chosen) {
    if (i == -1 or j == -1) {
      return l;
    }

    int ans = 0;
    if (a[i] == b[j]) {
      chosen.insert(chosen.begin(), a[i]);
      ans = lcs(i - 1, j - 1, l + 1, chosen);
    }
    string ls = "";
    string rs = "";
    int lx = lcs(i - 1, j, 0, ls);
    int ly = lcs(i, j - 1, 0, rs);
    if (ans < lx) {
      ans = lx;
      chosen = ls;
    }

    if (ans < ly) {
      ans = ly;
      chosen = rs;
    }
    return ans;
  }

  int lcs(string a, string b) {
    this->a = a;
    this->b = b;

    string str;
    int lc = lcs(a.size() - 1, b.size() - 1, 0, str);
    cout << str << '\n';
    return lc;
  }
};

int main() {
  Solution solution;
  string a = "gee";
  string b = "xgee";
  cout << solution.lcs(a, b) << '\n';
  return 0;
}
