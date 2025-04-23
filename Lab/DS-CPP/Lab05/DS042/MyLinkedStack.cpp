#include <iostream>

#include "MyLinkedStack.h"

using namespace std;

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

void MyLinkedStack::Push(const int& data)
{
    Node* newNode = new Node(data);
    newNode->Next = mStackTop;
    mStackTop = newNode;
}

void MyLinkedStack::Pop()
{
    if (IsEmpty())
    {
        cout << "Stack is empty." << endl;
        return;
    }

    Node* tempNode = mStackTop;
    mStackTop = mStackTop->Next;
    delete tempNode;
}

int MyLinkedStack::Top() const
{
    if (IsEmpty())
    {
        cout << "Stack is empty." << endl;
        return -1;
    }

    return mStackTop->Data;
}

int MyLinkedStack::GetNodeCount() const
{
    int count = 0;
    for (Node* current = mStackTop; current != nullptr; ++count, current = current->Next)
    {
    }
    return count;
}

void MyLinkedStack::PrintAll() const
{
    if (IsEmpty())
    {
        cout << "Stack is empty." << endl;
        return;
    }

    for (Node* current = mStackTop; current != nullptr; current = current->Next)
    {
        cout << current->Data;
        if (current->Next != nullptr)
        {
            cout << " -> ";
        }
    }

    cout << " (" << GetNodeCount() << " nodes)" << endl;
}
