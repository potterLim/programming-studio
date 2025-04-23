#ifndef MYSTACK_H
#define MYSTACK_H

#include "Student.h"

class MyStack
{
private:
    int mMaxSize;
    int mTop;
    Student* mList;

public:
    MyStack(int size = 100);
    ~MyStack();

    void Initialize();
    bool IsEmpty() const;
    bool IsFull() const;
    void Push(const Student& student);
    Student Pop();

    void Clear();
    void Print() const;
};

#endif /* MYSTACK_H */