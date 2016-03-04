
#include "memory_pool.h"
#include "list.h"

typedef struct {
    int data;
} myStruct;

int main(void)
{
    typedef Node<myStruct> myNode;
    MyPool<myNode, 100> pool;
    List<myNode> list;
    int i, capacity;
    for (i=0;i<100;i++) {
        myNode *pNode = pool.allocOBJ();
        pNode->data = i;
        list.push_front(pNode);
    }
    list.print();

    capacity = 0;
    for (i=0;i<100;i++) {
        if (i%10 == 0) {
            myNode *pNode = list.pop_front();
            pool.freeOBJ(pNode);
            capacity++;
        }
    }
    list.print();

    for (i=0;i<capacity;i++) {
        myNode *pNode = pool.allocOBJ();
        pNode->data = i + 1000;
        list.push_front(pNode);
    }
    list.print();

    return 0;
}
