#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int mobile(const vector<int> &vec, vector<bool> &dir) {
  int mi = -1;
  int max_mobile = numeric_limits<int>::min();
  for (int i = 0; i < vec.size(); ++i) {
    // 0 -> left
    // 1 -> right
    if (i != 0 && dir[i] == 0 && vec[i - 1] < vec[i] && max_mobile < vec[i]) {
      mi = i;
      max_mobile = vec[i];
    }

    if (i != (vec.size() - 1) && dir[i] == 1 && vec[i + 1] < vec[i] &&
        max_mobile < vec[i]) {
      mi = i;
      max_mobile = vec[i];
    }
  }
  return mi;
}

void reverse_dir(vector<int> &vec, vector<bool> &dir, int mi) {
  for (int i = 0; i < vec.size(); ++i) {
    if (vec[i] > vec[mi])
      dir[i] = (dir[i] ? 0 : 1);
  }
}

void permute(vector<int> vec) {
  vector<bool> dir(vec.size(), 0);
  int mi = 0;

  while ((mi = mobile(vec, dir)) != -1) {
    // 0 -> left
    // 1 -> right
    cout << "vec: ";
    for (auto e : vec)
      cout << e << " ";
    cout << "\n";

    reverse_dir(vec, dir, mi);
    if (dir[mi]) {
      swap(vec[mi], vec[mi + 1]);
      swap(dir[mi], dir[mi + 1]);
    } else {
      swap(vec[mi], vec[mi - 1]);
      swap(dir[mi], dir[mi - 1]);
    }
  }
  cout << "vec: ";
  for (auto e : vec)
    cout << e << " ";
  cout << "\n";
}

int main() {
  vector<int> vec = {1, 2, 3, 4};
  permute(vec);
  return 0;
}
