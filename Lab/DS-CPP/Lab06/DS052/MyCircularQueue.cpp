#include "MyCircularQueue.h"

using namespace std;

MyCircularQueue::MyCircularQueue(int capacity)
    : mMaxSize(capacity)
    , mFront(0)
    , mRear(0)
    , mList(new int[capacity])
{
}

MyCircularQueue::~MyCircularQueue()
{
    delete[] mList;
}

void MyCircularQueue::Initialize()
{
    mFront = 0;
    mRear = 0;
}

bool MyCircularQueue::IsEmpty() const
{
    return mFront == mRear;
}

bool MyCircularQueue::IsFull() const
{
    return (mRear + 1) % mMaxSize == mFront;
}

void MyCircularQueue::Enqueue(const int& element)
{
    if (IsFull())
    {
        cout << "=> Queue is full !" << endl;
        return;
    }

    mList[mRear] = element;
    mRear = (mRear + 1) % mMaxSize;
}

void MyCircularQueue::Dequeue()
{
    if (IsEmpty())
    {
        cout << "=> Queue is empty !" << endl;
        return;
    }

    mFront = (mFront + 1) % mMaxSize;
}

int MyCircularQueue::Front() const
{
    return mList[mFront];
}

int MyCircularQueue::Rear() const
{
    return mList[(mRear - 1 + mMaxSize) % mMaxSize];
}

int MyCircularQueue::Size() const
{
    return (mRear - mFront + mMaxSize) % mMaxSize;
}

void MyCircularQueue::PrintDetail() const
{
    cout << "Size : " << Size() << endl;

    cout << "Queue :";
    for (int i = 0, index = mFront; i < Size(); ++i, index = (index + 1) % mMaxSize)
    {
        cout << "[" << mList[index] << "]";
    }
    cout << endl;

    cout << "index :";
    for (int i = 0, index = mFront; i < Size(); ++i, index = (index + 1) % mMaxSize)
    {
        cout << " " << (index + 1);
    }
    cout << endl;

    cout << "front : " << mFront << ", rear : " << mRear << endl;
}
