// https://www.codechef.com/viewsolution/27549441

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// s is the sequence according to which we need to sort the columns
// left most element in s has the highest priority
// for lexicographical sort, s = [0, 1, 2, ... n-1]

vector<int> s;
bool comp(const vector<int> &p1, const vector<int> &p2) {
  for (auto e : s) {
    if (p1[e] < p2[e])
      return false;
    else if (p1[e] > p2[e])
      return true;
    else
      continue;
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    s.push_back(x - 1);
  }
  vector<vector<int>> vect(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      vect[i].push_back(x);
    }
    vect[i].push_back(i);
  }
  sort(vect.begin(), vect.end(), comp);
  for (int i = 0; i < n; i++) {
    cout << vect[i][m] + 1 << '\n';
  }
  return 0;
}
