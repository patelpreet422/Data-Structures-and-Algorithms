#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  string a; 
  string b;
  int lcs(int i, int j, int l, int &s) {
    if (i == -1 or j == -1) {
      return l;
    }

    int ans = 0;
    if (a[i] == b[j]) {
      s = i;
      ans = lcs(i - 1, j - 1, l + 1, s);
    }

    int xi = -1, yi = 1;
    int lx = lcs(i - 1, j, 0, xi);
    int ly = lcs(i, j - 1, 0, yi);
    if (ans < lx) {
      ans = lx;
      s = xi;
    }

    if (ans < ly) {
      ans = ly;
      s = yi;
    }
    return ans;
  }

  int lcs(string a, string b) {
    this->a = a;
    this->b = b;

    int s = -1;
    int lc = lcs(a.size() - 1, b.size() - 1, 0, s);
    cout << a.substr(s, lc) << '\n';
    return lc;
  }
};

int main() {
  Solution solution;
  string a = "xgeeksforgeeks";
  string b = "geeksforgeeks";
  cout << solution.lcs(a, b) << '\n';
  return 0;
}
