#include "MaxHeap.h"

MaxHeap::MaxHeap()
    : mSize(0)
{
}

void MaxHeap::Insert(int value)
{
    if (mSize >= MAX_SIZE)
    {
        return;
    }

    int i = mSize;
    mData[mSize] = value;
    ++mSize;

    while (i != 0 && mData[(i - 1) / 2] < mData[i])
    {
        int temp = mData[i];
        mData[i] = mData[(i - 1) / 2];
        mData[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int MaxHeap::Delete()
{
    if (mSize == 0)
    {
        return -1;
    }

    int rootValue = mData[0];
    mData[0] = mData[mSize - 1];
    --mSize;
    Heapify(0);
    return rootValue;
}

void MaxHeap::Heapify(int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < mSize && mData[left] > mData[largest])
    {
        largest = left;
    }

    if (right < mSize && mData[right] > mData[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        int temp = mData[index];
        mData[index] = mData[largest];
        mData[largest] = temp;
        Heapify(largest);
    }
}

bool MaxHeap::IsEmpty() const
{
    return mSize == 0;
}