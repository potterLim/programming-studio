#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
public:
    Queue();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(int value);
    void Dequeue();
    void Print() const;

private:
    int mData[5];
    int mFront;
    int mRear;
};

#endif /* QUEUE_H */