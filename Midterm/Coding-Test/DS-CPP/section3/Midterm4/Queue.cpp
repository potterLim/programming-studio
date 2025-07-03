#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue()
    : mFront(0)
    , mRear(0)
{
}

bool Queue::IsEmpty() const
{
    return mFront == mRear;
}

bool Queue::IsFull() const
{
    return (mRear + 1) % 5 == mFront;
}

void Queue::Enqueue(int value)
{
    if (IsFull())
    {
        return;
    }
    mData[mRear] = value;
    mRear = (mRear + 1) % 5;
}

void Queue::Dequeue()
{
    if (IsEmpty())
    {
        return;
    }
    mFront = (mFront + 1) % 5;
}

void Queue::Print() const
{
    int i = mFront;
    while (i != mRear)
    {
        cout << mData[i] << ' ';
        i = (i + 1) % 5;
    }
    cout << endl;
}