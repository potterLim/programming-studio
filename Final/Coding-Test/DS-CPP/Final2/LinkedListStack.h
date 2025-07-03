#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

#include "Node.h"

class LinkedListStack
{
public:
    LinkedListStack();

    void Push(char value);
    char Pop();
    bool IsEmpty() const;

private:
    Node* mTop;
};

#endif /* LINKED_LIST_STACK_H */
