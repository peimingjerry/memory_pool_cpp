
#include <iostream>
using std::cout;

#ifndef NULL
#define NULL 0
#endif

template<typename T>
class List
{
public:
    List(): _head(NULL) {}
    void push_front(T *pNode);
    T *pop_front();
    void print();
private:
    T * _head;
};

template<typename T>
void List<T>::print() {
    T *iter = _head;
    while (iter) {
        cout<<iter->data<<"\t"; // T->data is exposed
        iter = iter->pNext;     // T->pNext is exposed
    }
    cout<<"\n\n";
}

template<typename T>
void List<T>::push_front(T *pNode) {
    pNode->pNext = _head;
    _head = pNode;
}

template<typename T>
T * List<T>::pop_front() {
    assert(_head);
    if (_head == NULL) {
        return NULL;
    } else {
        T *pNode = _head;
        _head = _head->pNext;
        return pNode;
    }
}
