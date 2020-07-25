#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

template <typename T> using matrix = vector<vector<T>>;

matrix<int64_t> matrix_multiply(matrix<int64_t> &m1, matrix<int64_t> &m2) {
  matrix<int64_t> res(m1.size(), vector<int64_t>(m2[0].size(), 0));
  for (int64_t i = 0; i < res.size(); ++i) {
    for (int64_t j = 0; j < res[0].size(); ++j) {
      for (int64_t k = 0; k < m1[0].size(); ++k)
        res[i][j] += m1[i][k] * m2[k][j];
    }
  }
  return res;
}

int main() {
  matrix<int64_t> mat{{1, 2, 3}, {4, 5, 6}};

  matrix<int64_t> mat2{{7, 8}, {9, 10}, {11, 12}};

  for (auto r : matrix_multiply(mat, mat2)) {
    for (auto e : r) {
      cout << e << " ";
    }
    cout << '\n';
  }

  return 0;
}
