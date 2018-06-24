#include <iostream>
#include <memory>
#include <list>
using namespace std;
template<class T>
class Queue
{
private:
    unique_ptr<list<T> > data;
public:
    Queue()
    {
        data = make_unique<list<T> >();
    }
    void enque(T elem) { data->push_back(elem); }
    T& back() { return data->back(); }
    T& front() { return data->front(); }
    void deque() { data->pop_front(); }
    size_t size() { return data->size(); }
    bool empty() { return data->empty(); }
};

int main()
{
    Queue<int> queue;
    queue.enque(10);
    queue.enque(20);
    queue.enque(30);
    cout << "Front: " << queue.front() << '\n';
    cout << "Back: " << queue.back() << '\n';
    cout << "Size: " << queue.size() << '\n';
    queue.deque();
    cout << "Front: " << queue.front() << '\n';
    cout << "Back: " << queue.back() << '\n';
    cout << "Size: " << queue.size() << '\n';
    return 0;
}
