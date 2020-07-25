#include <algorithm>
#include <cassert>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class SortedList {
public:
  list<int> ll;
  void insert(int val) {
    list<int>::iterator itr = ll.begin();

    while (*itr < val && itr != ll.end()) {
      advance(itr, 1);
    }
    ll.insert(itr, val);
  }

  void erase(int key) { ll.erase(find(ll.begin(), ll.end(), key)); }
};

int main() {
  SortedList sl;
  sl.insert(4);
  sl.insert(40);
  sl.insert(-4);
  sl.insert(10);
  sl.insert(4545);
  sl.insert(-7);
  sl.insert(-7);
  sl.insert(4);

  sl.erase(-7);
  sl.erase(4);
  //    sl.erase(40);

  for (auto s : sl.ll) {
    cout << s << " ";
  }

  return 0;
}
