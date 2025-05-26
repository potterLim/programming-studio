#include <iostream>
#include "MaxHeap.h"

using namespace std;

MaxHeap::MaxHeap()
    : mSize(0)
{
}

void MaxHeap::insert(int value)
{
    if (mSize >= MAX_SIZE)
    {
        cout << "Overflow: Could not insertKey" << endl;
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

    printHeap();
}

void MaxHeap::delete_()
{
    if (mSize <= 0)
    {
        cout << "Could not deleteKey" << endl;
        return;
    }

    cout << "=> Delete " << mData[0] << endl;

    mData[0] = mData[mSize - 1];
    --mSize;

    maxHeapify(0);
    printHeap();
}

void MaxHeap::maxHeapify(int rootindex)
{
    int largest = rootindex;
    int left = 2 * rootindex + 1;
    int right = 2 * rootindex + 2;

    if (left < mSize && mData[left] > mData[largest])
    {
        largest = left;
    }

    if (right < mSize && mData[right] > mData[largest])
    {
        largest = right;
    }

    if (largest != rootindex)
    {
        int temp = mData[rootindex];
        mData[rootindex] = mData[largest];
        mData[largest] = temp;

        maxHeapify(largest);
    }
}

void MaxHeap::printHeap() const
{
    cout << "==> Heap : ";
    for (int i = 0; i < mSize; ++i)
    {
        cout << mData[i] << " ";
    }
    cout << endl;
}