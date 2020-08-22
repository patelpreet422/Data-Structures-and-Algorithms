#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Trie {
  vector<Trie *> children;
  bool is_word = false;

  Trie() { this->children.assign(256, nullptr); }

  ~Trie() {
    for(auto& c: children) {
      delete c;
      c = nullptr;
    }
  }

  bool empty() {
    for (char i = 0; i < this->children.size(); ++i) {
      if (this->children[i] != nullptr) {
        return false;
      }
    }
    return true;
  }

  void insert(const string& s) {
    Trie* curr = this;
    for(auto c: s) {
      if (curr->children[c] == nullptr) {
        curr->children[c] = new Trie();
      }
      curr = curr->children[c];
    }
    curr->is_word = true;
  }

  void print(string &s) {
    if (this->is_word) {
      cout << s << '\n';
    }
    for (char c = 0; c < this->children.size(); ++c) {
      if (this->children[c] != nullptr) {
        s.push_back(char(c));
        this->children[c]->print(s);
        s.pop_back();
      }
    }
  }

  bool contains(const string &s) {
    Trie *curr = this;
    for (auto c : s) {
      if (curr->children[c] == nullptr) {
        return false;
      }
      curr = curr->children[c];
    }
    return curr->is_word;
  }

  void remove(const string &s, int i) {
    if (i == s.size()) {
      this->is_word = false;
      return;
    }
    if (this->children[s[i]] == nullptr) {
      return;
    }
    this->children[s[i]]->remove(s, i + 1);
    if (this->children[s[i]]->empty() and !this->children[s[i]]->is_word) {
      cout << "removing... " << s[i] << "\n";
      delete this->children[s[i]];
      this->children[s[i]] = nullptr;
    }
  }

  Trie *auto_complete(const string &s) {
    Trie *curr = this;
    for (auto c : s) {
      if (curr->children[c] == nullptr) {
        return nullptr;
      }
      curr = curr->children[c];
    }
    return curr;
  }

  void remove(const string &s) { remove(s, 0); }

  void print() {
    string s = "";
    print(s);
  }
};

int main() {
  Trie trie;
  vector<string> dict{"a",           "demo",    "demon",
                      "graph",       "grapher", "!@#$%^789876543",
                      "!@#$11234567"};
  for(auto& s: dict) {
    trie.insert(s);
  }
  trie.print();
  return 0;
}

