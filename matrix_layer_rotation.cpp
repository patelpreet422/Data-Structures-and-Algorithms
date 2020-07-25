#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &vec) {
  for (auto e : vec)
    out << e << " ";
  return out;
}

vector<int> extractLayer(const vector<vector<int>> &mat, int k) {
  auto r = mat.size(), c = mat[0].size();

  /*
   * 0th layer -> outer most layer
   */

  // # of elements in kth layer
  auto ls = 2 * (r - 2 * k) + 2 * (c - 2 * k) - 4;
  vector<int> layer(ls);
  int p = 0;

  // top-side of layer
  for (int i = k; i <= c - 1 - k; ++i) {
    layer[p++] = mat[k][i];
  }

  // right-side of layer
  for (int i = k + 1; i <= r - 1 - k; ++i) {
    layer[p++] = mat[i][c - 1 - k];
  }

  // bottom-side of layer
  for (int i = c - 2 - k; i >= k; --i) {
    layer[p++] = mat[r - 1 - k][i];
  }

  // left-side of layer
  for (int i = r - 2 - k; i > k; --i) {
    layer[p++] = mat[i][k];
  }

  return layer;
}

void fillLayer(vector<vector<int>> &mat, const vector<int> &layer, int k) {
  auto r = mat.size(), c = mat[0].size();
  auto p = 0;
  for (int i = k; i <= c - 1 - k; ++i) {
    mat[k][i] = layer[p++];
  }
  for (int i = k + 1; i <= r - 1 - k; ++i) {
    mat[i][c - 1 - k] = layer[p++];
  }
  for (int i = c - 2 - k; i >= k; --i) {
    mat[r - 1 - k][i] = layer[p++];
  }
  for (int i = r - 2 - k; i > k; --i) {
    mat[i][k] = layer[p++];
  }
}

void fillMatrix(vector<vector<int>> &mat, const vector<vector<int>> &layers) {
  /*
   * fill matrix layer by layer starting from outermost layer and gradually
   * coming inwards
   */
  for (int i = 0; i < layers.size(); ++i) {
    fillLayer(mat, layers[i], i);
  }
}

void rotateMatrix(vector<vector<int>> &mat, int t) {
  auto r = mat.size(), c = mat[0].size();
  // # of layers = min(row, col)/2
  auto k = min(r, c) / 2;
  vector<vector<int>> layers(k);

  // extract each layer one-by-one
  for (int i = 0; i < k; ++i) {
    layers[i] = extractLayer(mat, i);
  }

  // rotate each layer individually
  for (auto &l : layers) {
    auto amount = t % l.size();
    rotate(l.begin(), l.begin() + amount, l.end());
  }

  // fill matrix back
  fillMatrix(mat, layers);

  // print matrix
  for (auto &row : mat) {
    cout << row << ' ';
    cout << '\n';
  }
}

int main() {
  int m, n, r;
  cin >> m >> n >> r;
  vector<vector<int>> mat(m, vector<int>(n));
  for (auto i = 0; i < m; ++i) {
    for (auto j = 0; j < n; ++j) {
      cin >> mat[i][j];
    }
  }
  rotateMatrix(mat, r);
  return 0;
}
