#include <iostream>
#include <limits>
#include <vector>

using namespace std;

void printBrace(vector<vector<int>> &S, int i, int j, char &c) {
  if (i == j) {
    cout << c;
    ++c;
  } else {
    cout << "(";
    printBrace(S, i, S[i][j], c);
    printBrace(S, S[i][j] + 1, j, c);
    cout << ")";
  }
}

int mcm(vector<int> dims) {
  /*
   * Dimension of matrix A[i] = dims[i] x dims[i+1]
   */

  int n = dims.size() - 1;
  vector<vector<int>> M(n, vector<int>(n));
  vector<vector<int>> S(n, vector<int>(n, 0));

  for (int i = 0; i < n; ++i)
    M[i][i] = 0;

  for (int d = 1; d < n; ++d) {
    for (int i = 0; i < n - d; ++i) {
      int col = i + d;
      cout << "[" << i << ", " << col << "]\n";
      M[i][col] = numeric_limits<int>::max();
      for (int k = i; k < col; ++k) {
        /*
         * k is intermidiate matrix
         * So, if we multiply i-th matrix
         * with k-th intermidiate matrix
         * and j-th matrix
         *
         * total cost = dim[i]*dim[k+1]*dim[j+1];
         */

        cout << "\t(" << i << ", " << k << ") + (" << k + 1 << ", " << col
             << ")";

        if (M[i][k] + M[k + 1][col] + dims[i] * dims[k + 1] * dims[col + 1] <
            M[i][col]) {
          M[i][col] =
              M[i][k] + M[k + 1][col] + dims[i] * dims[k + 1] * dims[col + 1];

          // Since we come here means that A[k] is the slicing point so we store
          // this point
          S[i][col] = k;
        }
        // M[i][col] = min(M[i][col], M[i][k] + M[k+1][col] +
        // dims[i]*dims[k+1]*dims[col+1]);
        cout << " + dim[" << i << "]*"
             << "dim[" << k + 1 << "]*"
             << "dim[" << col + 1 << "]\n";
      }
      cout << "\n";
    }
  }

  char c = 'A';
  printBrace(S, 0, n - 1, c);
  cout << "\n";

  return M[0][n - 1];
}

int main() {
  vector<int> dims{5, 4, 6, 2, 7};
  cout << mcm(dims) << "\n";
  return 0;
}
