#ifndef MYSTACK_H
#define MYSTACK_H

class MyStack
{
private:
    int mMaxSize;
    int mTop;
    int* mList;

public:
    MyStack(int size = 10);
    ~MyStack();

    void Initialize();
    bool IsEmpty() const;
    bool IsFull() const;
    void Push(const int& elem);
    int Pop();
    void Print() const;
};

#endif /* MYSTACK_H */