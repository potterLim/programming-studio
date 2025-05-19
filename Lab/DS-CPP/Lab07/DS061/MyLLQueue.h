#ifndef MY_LL_QUEUE_H
#define MY_LL_QUEUE_H

#include <iostream>

using namespace std;

class MyLLQueue
{
public:
    MyLLQueue();
    ~MyLLQueue();

    bool IsEmpty() const;
    void Enqueue(const int value);
    void Dequeue();
    int ShowFront() const;
    int ShowRear() const;
    void DisplayQueue() const;

private:
    struct Node
    {
        int data;
        Node* next;

        Node(const int value)
            : data(value)
            , next(nullptr)
        {
        }
    };

    Node* mHead;
    Node* mTail;
};

#endif  /* MY_LL_QUEUE_H */
