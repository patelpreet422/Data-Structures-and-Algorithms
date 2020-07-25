#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template <typename Itr> bool all_same(Itr l, Itr h) {
  return std::all_of(l, h, [i = *l](auto e) { return e == i; });
}

void adjacent_diff(std::vector<int> &vec, int lim) {
  for (int i = 0; i < lim; ++i) {
    vec[i] = vec[i + 1] - vec[i];
  }
}

// returns next element of the sequence
int next(std::vector<int> vec) {
  int e = 0, i = 0;
  while (!all_same(vec.begin(), vec.end() - i)) {
    adjacent_diff(vec, vec.size() - i - 1);
    ++i;
  }
  for (int k = vec.size() - 1 - i; k < vec.size(); ++k)
    e += vec[k];
  return e;
}

int main() {

  std::vector<int> vec{1, 2, 4, 7, 11};
  int k = 5;

  // compute next 5 terms of the sequence
  for (int i = 1; i <= k; ++i) {
    vec.push_back(next(vec));
    std::cout << vec.back() << ' ';
  }
  std::cout << '\n';

  return 0;
}
