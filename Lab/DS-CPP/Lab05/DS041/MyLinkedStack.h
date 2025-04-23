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
    void Push(const int& data);
    void Pop();
    int Top() const;
    int GetNodeCount() const;
    void PrintAll() const;

private:
    Node* mStackTop;
};

#endif /* MYLINKEDSTACK_H */
