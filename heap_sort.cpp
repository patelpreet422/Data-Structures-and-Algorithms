#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

void heapify_down(vector<int> &vec, int i) {
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

void heapify_up(vector<int> &vec, int i) {
  int par = (i - 1) / 2;
  while (i != 0 && vec[par] < vec[i]) {
    swap(vec[i], vec[par]);
    i = par;
  }
}

void insert_heap(vector<int> &vec, int k) {
  vec.push_back(k);
  heapify_up(vec, vec.size() - 1);
}

void build_max_heap(vector<int> &vec) {
  for (int i = (vec.size() - 2) / 2; i >= 0; --i) {
    heapify_down(vec, i);
  }
}

int delete_heap(vector<int> &vec) {
  int k = vec[0];
  vec[0] = vec[vec.size() - 1];
  vec.pop_back();
  heapify_down(vec, 0);
  return k;
}

void heap_sort(vector<int> &vec) {
  vector<int> sorted_vec(vec.size());
  build_max_heap(vec);
  int size = vec.size();
  for (int i = 0; i < size; ++i) {
    sorted_vec[size - i - 1] = delete_heap(vec);
  }
  vec = sorted_vec;
}

int main() {
  vector<int> vec{7, 10, 4, 3, 20, 15};
  // make_heap(begin(vec), end(vec));
  build_max_heap(vec);
  // sort_heap(vec.begin(), vec.end());
  heap_sort(vec);
  for (auto i : vec) {
    cout << i << '\n';
  }
  return 0;
}
