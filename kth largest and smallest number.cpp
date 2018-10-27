/*
  You are given a sorted array  of  integers and the elements of the array are unique. There will be queries. For each query, you will be given three integers ,  and .

  There are 2 types of queries:

  For Type 0 queries (type = 0), you have to find the th smallest element among all the elements that are greater than . If the number of elements that are greater than  are less than , output should be .

  For Type 1 queries (type = 1), you have to find the th largest element among all the elements that are smaller than . If the number of elements that are smaller than  are less than , output should be .

  Input Format

  The first line of input will contain two integers:  and .
  The next line will contain  integers. 
  The following  lines each contain 3 integers: ,  and  respectively.

  Output Format

  Output  lines: the answer for each query in a separate line.

  Sample Input

  9 3
  1 2 3 4 5 6 7 9 10
  2 3 0
  7 4 1
  5 1 0
  Sample Output

  5
  3
  6
  Explanation

  For the 1st query, the elements greater than 2 are: 3, 4, 5, 6, 7, 9, 10.
  The 3rd smallest among these is 5.

  For the 2nd query, the elements smaller than 7 are: 1, 2, 3, 4, 5, 6.
  The 4th largest among these is 3.

  For the 3rd query, elements greater than 5 are: 6, 7, 9, 10.
  The 1st smallest among these is 6
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    size_t n = 0, query = 0;
    int x = 0, k = 0, type = 0;
    cin >> n;
    vector<int> arr(n);
    cin >> query;

    for(size_t i = 0; i < n; ++i){
      cin >> arr[i];
    }

  while(query-- > 0) {
    // negative if 1, positive if 0
      cin >> x >> k >> type;
      auto part = partition_point(begin(arr), end(arr), [=](auto i){return i <= x;});
      --part;

      auto dist = (type == 0) ? distance(part, end(arr)) - 1 : distance(begin(arr), part);
      k = (type == 0) ? k : -k;

      if(dist < abs(k)) {
          cout << "Ans: " << -1 << '\n';
        } else {
          cout << "Ans: " << *next(part, k) << '\n';
        }

    }
    return 0;
}
