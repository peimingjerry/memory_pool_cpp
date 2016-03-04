
#include <assert.h>
#ifndef ASSERT
#define ASSERT assert
#endif

#ifndef NULL
#define NULL 0
#endif

template<typename T>
class Node : public T
{
public:
    Node() { this->pNext = (this + 1); }
    Node<T> * pNext;
};

template<typename T, unsigned int N>
class MyPool 
{
public:
    MyPool(): _list(NULL), _root(NULL) {}
    ~MyPool() { delete[] _root; }
    T* allocOBJ();
    void freeOBJ(T *obj);
    //int getCapacity();
private:
    T * _list;
    T * _root;
    unsigned int _used_count;
};

template<typename T, unsigned int N>
T* MyPool<T,N>::allocOBJ()
{
    if (_list == NULL) {
        ASSERT(_root == NULL);
        _root = new T[N];
        ASSERT(_root != NULL);
        _list = _root;
        T *tmp = static_cast<T *>(_list + N - 1);
        tmp->pNext = NULL;
    }
    T* obj = _list;
    _list = static_cast<T *>(obj->pNext);
    obj->pNext = NULL;

    return obj;
}

template<typename T, unsigned int N>
void MyPool<T,N>::freeOBJ(T *obj)
{
    obj->pNext = _list;
    _list = obj;
}
