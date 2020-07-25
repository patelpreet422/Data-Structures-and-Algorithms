#include <iostream>
using namespace std;
template <class T> struct Node {
  T data;
  Node<T> *left = nullptr;
  Node<T> *right = nullptr;
  Node<T> *parent = nullptr;
  Node() = default;
  explicit Node(int data) { this->data = data; }
  ~Node() {
    delete left;
    delete right;
  }
  inline bool hasLeftChild() { return left != nullptr; }
  inline bool hasRightChild() { return right != nullptr; }
  inline bool isLeaf() { return left == nullptr && right == nullptr; }
};

template <class T> class BST {
private:
  size_t no_of_elements = 0;
  Node<T> *root = nullptr;

public:
  ~BST() { delete root; }
  bool insert(T elem) {
    ++no_of_elements;
    Node<T> *currHead = root;
    Node<T> *parent = root;
    while (true) {

      if (root == nullptr) {
        root = new Node<T>(elem);
        return true;
      }

      if (elem < currHead->data) {
        parent = currHead;
        if (currHead->hasLeftChild())
          currHead = currHead->left;
        else {
          Node<T> *temp = new Node<T>(elem);
          temp->parent = parent;
          currHead->left = temp;
          return true;
        }
      } else {
        parent = currHead;
        if (currHead->hasRightChild())
          currHead = currHead->right;
        else {
          Node<T> *temp = new Node<T>(elem);
          temp->parent = parent;
          currHead->right = temp;
          return true;
        }
      }
    }
    //        return false;
  }

  bool contain(T elem) {
    Node<T> *currHead = root;
    while (true) {
      if (currHead->data == elem)
        return true;
      if (elem < currHead->data) {
        if (currHead->hasLeftChild())
          currHead = currHead->left;
        else
          return false;
      } else {
        if (currHead->hasRightChild())
          currHead = currHead->right;
        else
          return false;
      }
    }
  }

  void print(Node<T> *node) {
    if (node == nullptr)
      return;
    print(node->left);
    cout << node->data << ' ';
    print(node->right);
  }

  void print() { this->print(this->root); }

  Node<T> *findMin(Node<T> *node) {
    if (node != nullptr) {
      while (node->hasLeftChild())
        node = node->left;
    }
    return node;
  }

  Node<T> *findMax(Node<T> *node) {
    if (node != nullptr) {
      while (node->hasRightChild())
        node = node->right;
    }
    return node;
  }

  T &min() { return findMin(root)->data; }

  T &max() { return findMax(root)->data; }

  inline size_t size() { return no_of_elements; }
  inline bool empty() { return no_of_elements == 0; }

  void remove(T elem, Node<T> *node) {
    // if (node == nullptr) means we have reach bottom of the tree
    // without finding any element that matches the element to be removed
    // so we return
    if (node == nullptr)
      return;

    if (elem < node->data)
      remove(elem, node->left);
    else if (elem > node->data)
      remove(elem, node->right);
    else {
      if (node->isLeaf()) {
        if (node->data <= node->parent->data)
          node->parent->left = nullptr;
        else
          node->parent->right = nullptr;
        delete node;
        --no_of_elements;
        return;
      } else {
        if (node->left == nullptr || node->right == nullptr) {
          //                    only one child
          if (node->data <= node->parent->data)
            node->parent->left =
                node->hasLeftChild() ? node->left : node->right;
          else
            node->parent->right =
                node->hasLeftChild() ? node->left : node->right;
          --no_of_elements;
          return;
        } else {
          //                    case were node has two child
          node->data = findMax(node->left)->data;
          remove(findMax(node->left)->data, node->left);
        }
      }
    }
  }

  void remove(T elem) { remove(elem, this->root); }
};
int main() {
  BST<int> tree;
  tree.insert(10);
  tree.insert(15);
  tree.insert(8);
  tree.insert(9);
  tree.insert(6);
  tree.insert(7);
  tree.insert(5);
  tree.insert(6);
  tree.print();
  cout << "\nSize: " << tree.size() << '\n';
  cout << "After removing" << '\n';
  tree.remove(9);
  tree.print();
  cout << "\nSize: " << tree.size() << '\n';
  return 0;
}
