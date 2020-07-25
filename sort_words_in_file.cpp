#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
using namespace std;
int main() {
  ifstream fin("test.txt");
  istream_iterator<string> ii(fin);
  istream_iterator<string> eos;
  set<string> words(ii, eos);

  ostream_iterator<string> oi(cout, "\n");
  copy(begin(words), end(words), oi);
  fin.close();
  return 0;
}
