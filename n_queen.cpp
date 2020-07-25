#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<bool>> &chess, int r, int c) {
  if (r > chess.size())
    return false;
  if (r < 0)
    return false;
  if (c > chess.size())
    return false;
  if (c < 0)
    return false;

  static const vector<pair<int, int>> dirs{{-1, 0}, {1, 0},   {0, -1}, {0, 1},
                                           {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};

  for (auto &&d : dirs) {
    int x = d.first, y = d.second;
    for (int k = 1; ((0 <= r + k * x) && (r + k * x < chess.size())) &&
                    ((0 <= c + k * y) && (c + k * y < chess.size()));
         ++k) {
      // cout << r+k*x << ", " << c+k*y << '\n';
      if (chess[r + k * x][c + k * y] == true)
        return false;
    }
  }
  return true;
}

void queen(vector<vector<bool>> &chess, int row, int &k) {
  if (row == chess.size()) {
    cout << k << ": \n";
    ++k;
    for (auto &r : chess) {
      for (auto e : r) {
        cout << (e ? 'Q' : '_') << " ";
      }
      cout << '\n';
    }
    cout << '\n';
    return;
  }
  int n = chess.size();
  for (int col = 0; col < n; ++col) {
    chess[row][col] = true;
    if (isSafe(chess, row, col)) {
      queen(chess, row + 1, k);
    }
    chess[row][col] = false;
  }
}

int main() {
  // int x, y; cin >> x >> y;
  // vector<vector<bool>> chess(5, vector<bool>(5, false));
  // isSafe(chess, x, y);

  int n;
  cin >> n;
  vector<vector<bool>> chess(n, vector<bool>(n, false));
  int k = 1;
  queen(chess, 0, k);
  return 0;
}
