#include <iostream>
#include <vector>
using namespace std;
pair<int, int> two_largest(const vector<int> &vec) {
  int first = vec[0];
  int second = vec[0];
  for (int i = 1; i < vec.size(); ++i) {
    if (first < vec[i]) {
      if (second != first)
        second = first;
      first = vec[i];
    } else if (second < vec[i] && vec[i] != first) {
      second = vec[i];
    }
  }
  return make_pair(first, second);
}
int main() {
  vector<int> arr = {3, 8, 9, 1, 2, 7};
  int f = 0, s = 0;
  auto m = two_largest(arr);
  cout << m.first << ", " << m.second << '\n';
  return 0;
}
