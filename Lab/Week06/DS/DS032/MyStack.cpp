#include "MyStack.h"
#include <iostream>

using namespace std;

MyStack::MyStack(int size) 
    : mMaxSize(size)
    , mTop(-1)
{
    mList = new Student[mMaxSize];
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
    return (mTop == -1);
}

bool MyStack::IsFull() const
{
    return (mTop == mMaxSize - 1);
}

void MyStack::Push(const Student& student)
{
    if (IsFull())
    {
        cout << "Stack is full. Cannot push " << student.Gpa << " " << student.Name << endl;
        return;
    }

    mList[++mTop] = student;
}

Student MyStack::Pop()
{
    if (IsEmpty())
    {
        cout << "Stack is empty. Cannot pop." << endl;
        return Student();
    }

    return mList[mTop--];
}

void MyStack::Clear()
{
    mTop = -1;
}

void MyStack::Print() const
{
    if (IsEmpty())
    {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Top GPA: " << mList[mTop].Gpa << endl;
    for (int i = mTop; i >= 0; --i)
    {
        cout << mList[i].Name << endl;
    }
}
