#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

void dfs(int n, int p, string &indent, bool last = false) {

  // print indent
  cout << indent << n << '\n';

  // remove indent and add space instead
  if (last) {
    if (indent.size() >= 2) {
      indent.erase(indent.size() - 2, string::npos);
      indent += "  ";
    }
  } else {
    if (indent.size() >= 1) {
      indent.erase(indent.size() - 1, string::npos);
      indent += " ";
    }
  }

  for (int i = 0; i < g[n].size(); ++i) {
    int c = g[n][i];
    if (c == p) {
      continue;
    }

    if (i == g[n].size() - 1) {
      indent += "`-";
      dfs(c, n, indent, true);
    } else {
      indent += "|-";
      dfs(c, n, indent, false);
    }

    indent.erase(indent.size() - 2, string::npos);
  }
}

int main() {
  g = vector<vector<int>>{{1, 2}, {0, 4}, {0, 3, 5, 6}, {2}, {1}, {2}, {2}};
  string indent = "";
  dfs(0, 0, indent);
  return 0;
}
