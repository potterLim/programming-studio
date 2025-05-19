#include "MyLLQueue.h"

using namespace std;

MyLLQueue::MyLLQueue()
    : mHead(nullptr)
    , mTail(nullptr)
{
}

MyLLQueue::~MyLLQueue()
{
    while (!IsEmpty())
    {
        Dequeue();
    }
}

bool MyLLQueue::IsEmpty() const
{
    return mHead == nullptr;
}

void MyLLQueue::Enqueue(const int value)
{
    Node* newNode = new Node(value);
    if (IsEmpty())
    {
        mHead = newNode;
        mTail = newNode;
    }
    else
    {
        mTail->next = newNode;
        mTail = newNode;
    }
}

void MyLLQueue::Dequeue()
{
    if (IsEmpty())
    {
        return;
    }

    Node* nodeToDelete = mHead;
    mHead = mHead->next;
    delete nodeToDelete;

    if (mHead == nullptr)
    {
        mTail = nullptr;
    }
}

int MyLLQueue::ShowFront() const
{
    return mHead->data;
}

int MyLLQueue::ShowRear() const
{
    return mTail->data;
}

void MyLLQueue::DisplayQueue() const
{
    Node* current = mHead;
    while (current != nullptr)
    {
        cout << current->data;
        if (current->next != nullptr)
        {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << "\n";
}