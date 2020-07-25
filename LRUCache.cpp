#include <iostream>
#include <list>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class LRUCache {
public:
  LRUCache() = default;
  LRUCache(int s) : size(s) {}
  int size;
  list<pair<int, int>> cache;
  unordered_map<int, list<pair<int, int>>::iterator> index;

  void put(int key, int value) {
    if (index.find(key) != index.end()) {
      // key is already present in the cache
      cache.erase(index[key]);
      cache.push_front(make_pair(key, value));
    } else {
      // key is not present in the cache
      if (cache.size() == size) {
        // limit is reached so evict the least recently used key
        int lruk = cache.back().first;
        cache.pop_back();
        index.erase(lruk);
      }

      cache.push_front(make_pair(key, value));
    }

    // update the index
    index[key] = cache.begin();
  }

  int get(int key) {
    int value;
    if (index.find(key) == index.end()) {
      // key is not present in the cache
      value = -1;
    } else {
      value = index[key]->second;
      cache.erase(index[key]);
      cache.push_front(make_pair(key, value));
      index[key] = cache.begin();
    }
    return value;
  }
};

int main() {
  LRUCache lru(2);
  lru.put(1, 1);
  lru.put(2, 2);
  cout << lru.get(1) << '\n';
  lru.put(3, 3);
  cout << lru.get(2) << '\n';
  lru.put(4, 4);
  cout << lru.get(1) << '\n';
  cout << lru.get(3) << '\n';
  cout << lru.get(4) << '\n';
  return 0;
}
