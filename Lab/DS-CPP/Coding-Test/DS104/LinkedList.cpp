#include <iostream>

#include "LinkedList.h"

using namespace std;

LinkedList::Node::Node(int value)
    : mData(value)
    , mNext(nullptr)
{
}

LinkedList::LinkedList()
    : mHead(nullptr)
    , mTail(nullptr)
{
}

LinkedList::~LinkedList()
{
    Clear();
}

void LinkedList::AddLast(int value)
{
    Node* newNode = new Node(value);

    if (mHead == nullptr)
    {
        mHead = newNode;
        mTail = newNode;
    }
    else
    {
        mTail->mNext = newNode;
        mTail = newNode;
    }
}

void LinkedList::Print() const
{
    Node* current = mHead;
    while (current != nullptr)
    {
        cout << current->mData << endl;
        current = current->mNext;
    }
    cout << endl;
}

void LinkedList::Clear()
{
    Node* current = mHead;
    while (current != nullptr)
    {
        Node* temp = current;
        current = current->mNext;
        delete temp;
    }

    mHead = nullptr;
    mTail = nullptr;
}

void LinkedList::SelectionSort()
{
    for (Node* keyNode = mHead; keyNode != nullptr; keyNode = keyNode->mNext)
    {
        for (Node* tempNode = keyNode->mNext; tempNode != nullptr; tempNode = tempNode->mNext)
        {
            if (keyNode->mData > tempNode->mData)
            {
                int swapValue = keyNode->mData;
                keyNode->mData = tempNode->mData;
                tempNode->mData = swapValue;
            }
        }
    }
}

