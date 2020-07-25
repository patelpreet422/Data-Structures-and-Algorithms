#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

void mergesort(vector<int> &vec, vector<int> &temp, int64_t p, int64_t q) {
  /*
   *       [ left half ]  [ right half ]
   *         p  lidx  mid     ridx     q
   *         |   |     |       |       |
   *        \/  \/    \/      \/      \/
   * vec = [  ...  ...   ...      ...  ]
   *
   */
  if (p >= q)
    return;

  int64_t mid = (p + q) / 2;

  // recurse on left half
  mergesort(vec, temp, p, mid);

  // recurse on right half
  mergesort(vec, temp, mid + 1, q);

  // temp stores the sorted array
  // vector<int> temp(q-p+1);
  int64_t tidx = 0, lidx = p, ridx = mid + 1;

  // len(left half) = mid - p + 1
  // len(right half) = q - mid;
  while (lidx <= mid && ridx <= q) {
    if (vec[lidx] <= vec[ridx]) {
      temp[tidx++] = vec[lidx++];
    } else {
      temp[tidx++] = vec[ridx++];
    }
  }

  // copy left half
  while (lidx <= mid)
    temp[tidx++] = vec[lidx++];

  // copy right half
  while (ridx <= q)
    temp[tidx++] = vec[ridx++];

  // copy sorted array to vec
  tidx = 0;
  while (p <= q) {
    vec[p++] = temp[tidx++];
  }
}

void mergesort(vector<int> &vec) {
  vector<int> temp(vec.size());
  mergesort(vec, temp, 0, vec.size() - 1);
}

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  copy(istream_iterator<int>(cin), istream_iterator<int>{}, begin(vec));
  mergesort(vec);
  for (auto e : vec)
    cout << e << " ";
  return 0;
}
