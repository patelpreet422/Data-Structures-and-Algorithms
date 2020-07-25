#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

int findElementIteratve(const vector<int> &input, int start, int end, int key) {

  while (start <= end) {
    int mid = (start + end) / 2;

    if (input[mid] == key)
      return mid;

    else if (input[start] <= input[mid]) {
      /*Left sub array is sorted, check if
      key is with A[start] and A[mid] */
      if (input[start] <= key && key <= input[mid]) {
        /*
          Key lies with left sorted part of array
         */
        end = mid - 1;
      } else {
        /*
        Key lies in right subarray
         */
        start = mid + 1;
      }
    } else {
      /*
       In this case, right subarray is already sorted and
       check if key falls in range A[mid+1] and A[end]
       */
      if (input[mid + 1] <= key && key <= input[end]) {
        /*
          Key lies with right sorted part of array
         */
        start = mid + 1;
      } else {
        /*
        Key lies in left subarray
         */
        end = mid - 1;
      }
    }
  }
  return -1;
}

int main() {
  vector<int> vec{9, 9, 9, 9, 1, 2};
  cout << boolalpha << findElementIteratve(vec, 0, vec.size() - 1, 9) << '\n';
  return 0;
}
