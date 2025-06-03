#include <iostream>

#include "MinHeap.h"

using namespace std;

MinHeap::MinHeap()
    : mSize(0)
{
}

MinHeap::~MinHeap()
{
}

void MinHeap::InsertKey(const int value)
{
    if (mSize >= MAX_SIZE)
    {
        cout << "Heap overflow" << endl;
        return;
    }

    mData[mSize] = value;
    ++mSize;

    MinHeapifyUp(mSize - 1);
}

void MinHeap::DeleteKey()
{
    if (IsEmpty())
    {
        cout << "Heap is empty" << endl;
        return;
    }

    cout << "min value : " << mData[0] << endl;

    mData[0] = mData[mSize - 1];
    --mSize;

    MinHeapifyDown(0);
}

int MinHeap::Peek() const
{
    if (IsEmpty())
    {
        cout << "Heap is empty" << endl;
        return -1;
    }

    return mData[0];
}

int MinHeap::GetSize() const
{
    return mSize;
}

bool MinHeap::IsEmpty() const
{
    return mSize == 0;
}

void MinHeap::MinHeapifyUp(int index)
{
    while (index != 0 && mData[(index - 1) / 2] > mData[index])
    {
        int temp = mData[index];
        mData[index] = mData[(index - 1) / 2];
        mData[(index - 1) / 2] = temp;

        index = (index - 1) / 2;
    }
}

void MinHeap::MinHeapifyDown(int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < mSize && mData[left] < mData[smallest])
    {
        smallest = left;
    }

    if (right < mSize && mData[right] < mData[smallest])
    {
        smallest = right;
    }

    if (smallest != index)
    {
        int temp = mData[index];
        mData[index] = mData[smallest];
        mData[smallest] = temp;

        MinHeapifyDown(smallest);
    }
}

void MinHeap::PrintHeap() const
{
    for (int index = 0; index < mSize; ++index)
    {
        cout << mData[index] << " ";
    }
    cout << endl;
}