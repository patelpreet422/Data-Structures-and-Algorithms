#include <iostream>
using namespace std;
string toBinaryString(int k) {
  if (!k)
    return "";
  return toBinaryString(k >> 1) + ((k & 1) ? "1" : "0");
}

int commonPrefixSize(string a, string b) {
  return distance(a.begin(), mismatch(a.begin(), a.end(), b.begin()).first);
}

string commonPrefix(string a, string b) {
  return string(a.begin(), mismatch(a.begin(), a.end(), b.begin()).first);
}

auto commonAncester(int a, int b) {
  size_t c = 0;
  return stoi(commonPrefix(toBinaryString(a), toBinaryString(b)), &c, 2);
}

// returns shortest path between two nodes in the tree
int pathLength(int a, int b) {
  auto bin_a = toBinaryString(a), bin_b = toBinaryString(b);
  auto common_ancester_size = commonPrefixSize(bin_a, bin_b);
  return bin_a.size() - common_ancester_size + bin_b.size() -
         common_ancester_size;
}

int main() {
  cout << commonAncester(4, 5) << '\n';
  cout << commonAncester(4, 6) << '\n';
  cout << commonAncester(3, 4) << '\n';
  cout << commonAncester(2, 4) << '\n';
  return 0;
}
