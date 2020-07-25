#include <iostream>
#include <list>
#include <memory>
using namespace std;
template <class T> class Stack {
private:
  unique_ptr<list<T>> data;

public:
  Stack() { data = make_unique<list<T>>(); }
  void push(T elem) { data->push_back(elem); }
  void pop() { data->pop_back(); }
  T &top() { return data->back(); }
  bool empty() { return data->empty(); }
  size_t size() { return data->size(); }
};
int main() {
  Stack<int> stack;
  stack.push(10);
  stack.push(20);
  stack.push(30);
  cout << "Top: " << stack.top() << '\n';
  cout << "Size: " << stack.size() << '\n';
  stack.pop();
  cout << "Top: " << stack.top() << '\n';
  cout << "Size: " << stack.size() << '\n';
  return 0;
}
