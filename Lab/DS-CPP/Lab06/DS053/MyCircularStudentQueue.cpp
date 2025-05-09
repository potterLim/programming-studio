#include "MyCircularStudentQueue.h"

using namespace std;

MyCircularStudentQueue::MyCircularStudentQueue(int capacity)
    : mMaxSize(capacity)
    , mFront(0)
    , mRear(0)
    , mList(new StudentInfo[capacity])
{
}

MyCircularStudentQueue::~MyCircularStudentQueue()
{
    delete[] mList;
}

void MyCircularStudentQueue::Enqueue(const StudentInfo& student)
{
    if ((mRear + 1) % mMaxSize == mFront)
    {
        cout << "=> Student queue is full!" << endl;
        return;
    }

    mList[mRear] = student;
    mRear = (mRear + 1) % mMaxSize;
}

void MyCircularStudentQueue::Dequeue()
{
    if (IsEmpty())
    {
        cout << "=> Student queue is empty!" << endl;
        return;
    }

    mFront = (mFront + 1) % mMaxSize;
}

const StudentInfo& MyCircularStudentQueue::Front() const
{
    return mList[mFront];
}

int MyCircularStudentQueue::Size() const
{
    return (mRear - mFront + mMaxSize) % mMaxSize;
}

bool MyCircularStudentQueue::IsEmpty() const
{
    return mFront == mRear;
}
