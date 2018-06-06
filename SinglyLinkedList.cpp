#include <iostream>
using namespace std;
template <class T>
struct Node
{
    T data;
    explicit Node(T d = 0):data(d){}
    Node *next = nullptr;
    ~Node(){delete next;}
    //TODO: write copy ctor, move ctor, copy assignment operator, move assignment operator
};
template <class T>
class LinkedList
{
private:
    Node<T> head;
    int size = 0;
public:
    void insert(T d)
    {
        Node<T> *n = new Node<T>(d);
        Node<T> *curr = &head;
        ++size;
        int i = 0;
        while(i<(size-1))
        {
            curr = curr->next;
            ++i;
        }
        curr->next = n;
    }
    void insert(T d, int idx)
    {
        if(idx<0||idx>size) return;
        if(idx == size) insert(d);
        else{
            Node<T> *n = new Node<T>(d);
            Node<T> *curr = &head;
            ++size;
            int i = 0;
            while(i<idx)
            {
                curr = curr->next;
                ++i;
            }
            n->next = curr->next;
            curr->next = n;
        }
    }
    void remove(int idx)
    {
        if(idx<0||idx>=size) return;
        Node<T> *curr = &head;
        --size;
        int i = 0;
        while(i<idx)
        {
            curr = curr->next;
            ++i;
        }
        curr->next = curr->next->next;
    }
    T operator[](int idx)
    {
        if(idx < 0 || idx >= size) return 0;
        Node<T> *curr = &head;
        int i = 0;
        while(i<=idx)
        {
            curr = curr->next;
            ++i;
        }
        return curr->data;
    }
    bool is_empty(){return size==0;}
    int length(){return size;}
    T front(){return (*this)[0];}
    T back(){return (*this)[size-1];}
};
int main()
{
    LinkedList<float> ll;
    ll.insert(1.6);
    for(int i = 0; i < ll.length(); ++i)
    {
        cout << ll[i] << ' ';
    }
    return 0;
}
