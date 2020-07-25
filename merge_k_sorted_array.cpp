#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> k_merge(const vector<vector<int>> &sa) {
  int k = sa.size();
  // pair.first = value and pair.second = array index from which this value came
  vector<pair<int, int>> elems(k); // first elems of all array
  int p = 0;                       // elems counter
  int q = 0;                       // counter for merged array counter
  int res_size = 0;                // total elements in merged array

  for (int i = 0; i < k; ++i) {
    elems[p++] = {sa[i][0], i};
    res_size += sa[i].size();
  }
  make_heap(elems.begin(), elems.end(), greater<>{});

  // merged array
  vector<int> res(res_size);

  // store the location we are at in each array
  vector<int> arr_counter(k, 0);

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq(
      greater<>{}, elems);
  while (!pq.empty()) {
    auto min_pair = pq.top();
    int mp_arr_idx = min_pair.second;
    pq.pop();

    res[q++] = sa[mp_arr_idx][arr_counter[mp_arr_idx]];

    if (arr_counter[mp_arr_idx] + 1 < sa[mp_arr_idx].size()) {
      ++arr_counter[mp_arr_idx];
      pq.push({sa[mp_arr_idx][arr_counter[mp_arr_idx]], mp_arr_idx});
    }
  }
  return res;
}

int main() {
  vector<vector<int>> sa{
      {0, 1, 3, 5, 7, 11, 13}, {2, 3, 4, 11}, {0, 9, 10, 11}};

  auto vec = k_merge(sa);

  for (auto e : vec)
    cout << e << " ";
  cout << '\n';
  return 0;
}
