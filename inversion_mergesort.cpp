#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

int64_t mergesort_inversion(vector<int> &vec, int64_t p, int64_t q) {
  if (p >= q)
    return 0;
  int mid = (p + q) / 2;

  // recurse on left half
  auto a = mergesort_inversion(vec, p, mid);

  // recurse on right half
  auto b = mergesort_inversion(vec, mid + 1, q);

  // temp stores the sorted array
  vector<int> temp(q - p + 1);
  int64_t l = 0, i = p, m = mid + 1, c = 0;

  // len(left half) = mid - p + 1
  // len(right half) = q - mid;
  while (i <= mid && m <= q) {
    if (vec[i] <= vec[m]) {
      temp[l++] = vec[i];
      ++i;
    } else {
      temp[l++] = vec[m];
      ++m;
      //            c += ((mid - p + 1) - i);
      //          c += (remaining elements in left half)
      c += (mid - i + 1);
    }
  }

  // copy left half
  while (i <= mid)
    temp[l++] = vec[i++];

  // copy right half
  while (m <= q)
    temp[l++] = vec[m++];

  // copy sorted array to vec
  l = 0;
  while (p <= q) {
    vec[p++] = temp[l++];
  }

  c += a + b;
  return c;
}

int main() {
  int64_t t;
  cin >> t;
  while (t--) {
    int64_t n;
    cin >> n;
    vector<int> vec(n);
    for (auto &e : vec)
      cin >> e;

    cout << mergesort_inversion(vec, 0, vec.size() - 1) << '\n';
  }
  return 0;
}
