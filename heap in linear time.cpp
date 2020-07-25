#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void heapify_down(vector<int> &vec, size_t i) {
  while (2 * i + 1 < vec.size()) {
    int max_child = 2 * i + 1;
    if (2 * i + 2 < vec.size() && vec[2 * i + 2] > vec[2 * i + 1]) {
      max_child = 2 * i + 2;
    }
    if (vec[i] < vec[max_child]) {
      swap(vec[i], vec[max_child]);
      i = max_child;
    } else {
      return;
    }
  }
}

void build_max_heap(vector<int> &vec) {
  for (int i = (vec.size() - 2) / 2; i >= 0; --i) {
    heapify_down(vec, i);
  }
}

int main() {
  vector<int> vec{-7, -7, 0, -5, 10, 5, 50};
  // make_heap(begin(vec), end(vec));
  build_max_heap(vec);
  sort_heap(begin(vec), end(vec));
  for (auto i : vec) {
    cout << i << '\n';
  }
  return 0;
}
