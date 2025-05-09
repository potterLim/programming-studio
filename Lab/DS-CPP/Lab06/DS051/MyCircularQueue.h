#ifndef MY_CIRCULAR_QUEUE_H
#define MY_CIRCULAR_QUEUE_H

#include <iostream>

#define DEFAULT_CAPACITY (10)

class MyCircularQueue
{
public:
    MyCircularQueue(int capacity = DEFAULT_CAPACITY);
    ~MyCircularQueue();

    void Initialize();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(const int& element);
    void Dequeue();
    int Front() const;
    int Rear() const;
    int Size() const;
    void PrintDetail() const;

private:
    const int mMaxSize;
    int mFront;
    int mRear;
    int* mList;
};

#endif /* MY_CIRCULAR_QUEUE_H */
