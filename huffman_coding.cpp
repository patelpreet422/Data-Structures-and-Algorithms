#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

static const char INTERNAL_NODE = 0;

struct Node {
  Node *left = nullptr;
  Node *right = nullptr;
  char character;
  int freq = 0;
  Node(char character, int freq) : character(character), freq(freq) {}
  Node(Node *left, Node *right, char character, int freq)
      : left(left), right(right), character(character), freq(freq) {}
};

Node *huffman_coding(unordered_map<char, int> char_map) {
  auto compare_node = [](Node *&n1, Node *&n2) { return n1->freq > n2->freq; };
  priority_queue<Node *, vector<Node *>, decltype(compare_node)> pq(
      compare_node);
  for (auto &p : char_map) {
    pq.push(new Node(p.first, p.second));
  }
  while (pq.size() > 1) {
    Node *first = pq.top();
    pq.pop();
    Node *second = pq.top();
    pq.pop();
    pq.push(new Node(first, second, INTERNAL_NODE, first->freq + second->freq));
  }
  return pq.top();
}

int bits_required = 0;
void traverse_tree(Node *&ptr, string s) {
  if (ptr == nullptr) {
    return;
  }
  traverse_tree(ptr->left, s + "0");
  if (ptr->character != INTERNAL_NODE) {
    cout << ptr->character << "(" << ptr->freq << ")"
         << " -> " << s << '\n';
    bits_required += ptr->freq * s.length();
  }
  traverse_tree(ptr->right, s + "1");
}

unordered_map<char, int> char_freq(string s) {
  unordered_map<char, int> freq_map;
  for (char c : s) {
    if (freq_map.find(c) == freq_map.end())
      freq_map[c] = 1;
    else
      ++freq_map[c];
  }
  return freq_map;
}

int main() {
  //  unordered_map<char, int> char_map{{'a', 5}, {'b', 9}, {'c', 12}, {'d',
  //  13}, {'e', 16}, {'f', 45}}; Node* root = huffman_coding(char_map);
  Node *root = huffman_coding(char_freq("go go gophers"));
  traverse_tree(root, "");
  cout << bits_required << '\n';
  return 0;
}
