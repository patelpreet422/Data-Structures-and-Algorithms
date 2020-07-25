#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int extract_digit(int k, int p) { return int(k / pow(10, p - 1)) % 10; }

int int_size(int k) {
  int s = 0;
  while (k) {
    k /= 10;
    ++s;
  }
  return s;
}

int max_element_size(vector<int> &vec) {
  int mx = vec[0], mi = vec[0];
  for (int i : vec) {
    if (mx < i)
      mx = i;
    if (mi > i)
      mi = i;
  }
  return max(int_size(mx), int_size(mi));
}

void counting_sort(vector<int> &vec, int p) {
  unordered_map<int, vector<int>> freq;
  for (auto i : vec) {
    freq[extract_digit(i, p)].push_back(i);
  }
  int k = 0;
  for (int i = -9; i < 10; ++i) {
    if (freq.find(i) != freq.end()) {
      for (auto elem : freq[i]) {
        vec[k++] = elem;
      }
    }
  }
}

void radix_sort(vector<int> &vec) {
  auto l = max_element_size(vec);
  for (int p = 1; p <= l; ++p) {
    //      sort(vec.begin(), vec.end(), [p = p](int a, int b){ return
    //      extract_digit(a, p) < extract_digit(b, p);});
    counting_sort(vec, p);
  }
}

int main() {
  vector<int> vec{-7877878, 170, 45, 75, -8587, 0, 0, 90, 802, 24, 2, 66};
  radix_sort(vec);
  for (auto i : vec) {
    cout << i << ", ";
  }
  return 0;
}
