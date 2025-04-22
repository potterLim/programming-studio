#include "MyLinkedStack.h"

MyLinkedStack::MyLinkedStack()
    : mStackTop(nullptr)
{
}

MyLinkedStack::~MyLinkedStack()
{
    Initialize();
}

void MyLinkedStack::Initialize()
{
    while (mStackTop != nullptr)
    {
        Node* tempNode = mStackTop;
        mStackTop = mStackTop->Next;
        delete tempNode;
    }
}

bool MyLinkedStack::IsEmpty() const
{
    return mStackTop == nullptr;
}

void MyLinkedStack::Push(const char data)
{
    Node* newNode = new Node(data);
    newNode->Next = mStackTop;
    mStackTop = newNode;
}

void MyLinkedStack::Pop()
{
    if (IsEmpty())
    {
        return;
    }

    Node* tempNode = mStackTop;
    mStackTop = mStackTop->Next;
    delete tempNode;
}

char MyLinkedStack::Top() const
{
    if (IsEmpty())
    {
        return '\0';
    }

    return mStackTop->Data;
}
