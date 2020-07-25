#include <iostream>
#include <map>
using namespace std;

struct Trie {
  map<char, Trie> children;
  bool is_word = false;

  bool empty() { return children.empty(); }

  void insert(const string &s) { insert(s, 0); }

  void insert(const string &s, int i) {
    if (i == s.size()) {
      is_word = true;
      return;
    }
    children[s[i]].insert(s, i + 1);
  }

  void remove(const string &s) { remove(s, 0); }

  void remove(const string &s, int i) {
    if (i == s.size()) {
      is_word = false;
      return;
    }

    if (children.find(s[i]) == children.end())
      return;

    children[s[i]].remove(s, i + 1);
    if (children[s[i]].empty() and !children[s[i]].is_word) {
      children.erase(children.find(s[i]));
      cout << "removing: " << s[i] << '\n';
    }
  }

  Trie next_suffixes(const string &s) { return next_suffixes(s, 0); }

  Trie next_suffixes(const string &s, int i) {
    if (i == s.size()) {
      return *this;
    }

    if (children.find(s[i]) == children.end())
      return Trie();

    return children[s[i]].next_suffixes(s, i + 1);
  }

  void print() {
    string t;
    print(t);
  }

  void print(string &s) {
    if (is_word)
      cout << s << '\n';

    for (auto [c, n] : children) {
      s.push_back(c);
      n.print(s);
      s.pop_back();
    }
  }
};

int main() {
  Trie trie;
  //  trie.insert("abfgh");
  //  trie.insert("abfgi");
  //  trie.insert("abc");
  //  trie.insert("ab");
  //  trie.insert("abdef");
  //  trie.insert("abdefg");
  trie.remove("x");

  trie.next_suffixes("x").print();
  trie.print();

  return 0;
}
