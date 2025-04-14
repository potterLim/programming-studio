#include "MyStack.h"
#include <iostream>

using namespace std;

MyStack::MyStack(int size) : mMaxSize(size), mTop(-1)
{
    mList = new int[mMaxSize];
}

MyStack::~MyStack()
{
    delete[] mList;
}

void MyStack::Initialize()
{
    mTop = -1;
}

bool MyStack::IsEmpty() const
{
    return mTop == -1;
}

bool MyStack::IsFull() const
{
    return mTop == mMaxSize - 1;
}

void MyStack::Push(const int& elem)
{
    if (IsFull())
    {
        cout << "Stack is full. Cannot push " << elem << "." << endl;
        return;
    }

    mList[++mTop] = elem;
}

int MyStack::Pop()
{
    if (IsEmpty())
    {
        cout << "Stack is empty. Cannot pop." << endl;
        return -1;
    }

    return mList[mTop--];
}

void MyStack::Print() const
{
    for (int i = mTop; i >= 0; --i)
    {
        cout << mList[i] << endl;
    }
}