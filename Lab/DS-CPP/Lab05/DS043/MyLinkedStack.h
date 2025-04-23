#ifndef MYLINKEDSTACK_H
#define MYLINKEDSTACK_H

#include "Node.h"

class MyLinkedStack
{
public:
    MyLinkedStack();
    ~MyLinkedStack();

    void Initialize();
    bool IsEmpty() const;
    void Push(const char data);
    void Pop();
    char Top() const;

private:
    Node* mStackTop;
};

#endif /* MYLINKEDSTACK_H */
