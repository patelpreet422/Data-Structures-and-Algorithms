#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void trim_left(string &input) {
  input.erase(input.begin(), find_if(input.begin(), input.end(),
                                     [](int ch) { return !isspace(ch); }));
}

void trim_right(string &input) {
  input.erase(
      find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); })
          .base(),
      input.end());
}

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
  ~TreeNode() {
    delete this->left;
    delete this->right;
    this->left = nullptr;
    this->right = nullptr;
  }

  void insert(int v) {
    if (this->val < v and this->left == nullptr) {
      this->left = new TreeNode(v);
      return;
    }
    if (this->val >= v and this->right == nullptr) {
      this->right = new TreeNode(v);
      return;
    }
    if (this->val < v) {
      this->left->insert(v);
    } else {
      this->right->insert(v);
    }
  }

  void dfs(string &s) {
    if (this->left) {
      s += "  " + to_string(this->val) + " -- " + to_string(this->left->val) +
           "\n";
      this->left->dfs(s);
    }

    if (this->right) {
      s += "  " + to_string(this->val) + " -- " + to_string(this->right->val) +
           "\n";
      this->right->dfs(s);
    }
  }

  void print() {
    if (this->left) {
      this->left->print();
    }
    cout << this->val << ' ';
    if (this->right) {
      this->right->print();
    }
  }

  string to_graphviz() {
    string s = "strict graph G {\n";
    dfs(s);
    s += "}";
    return s;
  }

  static TreeNode *from(string input) {
    trim_left(input);
    trim_right(input);
    input = input.substr(1, input.size() - 2);
    if (input.empty()) {
      return nullptr;
    }
    stringstream ss(input);
    string item;
    getline(ss, item, ',');
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(stoi(input));
    q.push(root);
    while (true) {
      TreeNode *node = q.front();
      q.pop();
      if (!getline(ss, item, ',')) {
        break;
      }
      trim_left(item);
      trim_right(item);
      if (item != "null") {
        node->left = new TreeNode(stoi(item));
        q.push(node->left);
      }

      if (!getline(ss, item, ',')) {
        break;
      }
      trim_left(item);
      trim_right(item);
      if (item != "null") {
        node->right = new TreeNode(stoi(item));
        q.push(node->right);
      }
    }
    return root;
  }
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  ~ListNode() {
    delete this->next;
    this->next = nullptr;
  }

  void append(int v) {
    ListNode *curr = this;
    while (curr->next) {
      curr = curr->next;
    }
    curr->next = new ListNode(v);
  }

  void print() {
    cout << this->val << ' ';
    if (this->next) {
      this->next->print();
    }
  }

  static ListNode *from(string input) {
    trim_left(input);
    trim_right(input);
    input = input.substr(1, input.size() - 2);
    ListNode *node = nullptr;
    stringstream ss(input);
    string item;
    while (getline(ss, item, ',')) {
      trim_left(item);
      trim_right(item);
      if (node) {
        node->append(stoi(item));
      } else {
        node = new ListNode(stoi(item));
      }
    }
    return node;
  }
};
