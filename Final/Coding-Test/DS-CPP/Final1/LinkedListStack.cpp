#include <iostream>
#include "LinkedListStack.h"

using namespace std;

LinkedListStack::LinkedListStack()
    : mTop(nullptr)
{
}

void LinkedListStack::Push(char value)
{
    Node* newNode = new Node(value);

    if (mTop == nullptr)
    {
        mTop = newNode;
    }
    else
    {
        newNode->mNext = mTop;
        mTop = newNode;
    }
}

char LinkedListStack::Pop()
{
    if (IsEmpty())
    {
        cout << "Stack is empty" << endl;
        return '\0';
    }

    Node* temp = mTop;
    char value = temp->mData;
    mTop = mTop->mNext;

    delete temp;
    return value;
}

bool LinkedListStack::IsEmpty() const
{
    return mTop == nullptr;
}
