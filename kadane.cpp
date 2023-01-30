#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int maxSubArray(vector<int>& nums) {
  if(nums.empty()) {
    return 0;
  }

  int n = nums.size();
  int cs = nums[0];
  int ms = nums[0];

  int start = 0;
  int end = 0;

  for(int i = 1; i < n; ++i) {
    if(cs <= 0) {
      cs = 0;
      start = i;
    }

    cs += nums[i];

    if(cs > ms) {
      end = i;
      ms = cs;
    }
  }

  // start and end represents the range
  for(int i = start; i <= end; ++i) {
    cout << nums[i] << ' ';
  }

  cout << '\n';

  return ms;
}

int main() {
  vector<int> vec{-2, -3, 4, -1, -2, 1, 5, -3};
  cout << max_subarray_sum(vec) << '\n';
  return 0;
}
