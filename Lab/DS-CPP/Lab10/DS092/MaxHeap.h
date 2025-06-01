#ifndef MAX_HEAP_H
#define MAX_HEAP_H

class MaxHeap
{
public:
    MaxHeap();
    void Insert(int value);
    int Delete();
    bool IsEmpty() const;

private:
    static const int MAX_SIZE = 100;
    int mData[MAX_SIZE];
    int mSize;

    void Heapify(int index);
};

#endif /* MAX_HEAP_H */