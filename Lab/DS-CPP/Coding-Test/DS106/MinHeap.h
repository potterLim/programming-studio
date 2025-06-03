#ifndef MIN_HEAP_H
#define MIN_HEAP_H

class MinHeap
{
public:
    MinHeap();
    ~MinHeap();

    void InsertKey(const int value);
    void DeleteKey();
    int Peek() const;
    int GetSize() const;
    bool IsEmpty() const;
    void PrintHeap() const;

private:
    static const int MAX_SIZE = 30;
    int mData[MAX_SIZE];
    int mSize;

    void MinHeapifyUp(int index);
    void MinHeapifyDown(int index);
};

#endif /* MIN_HEAP_H */