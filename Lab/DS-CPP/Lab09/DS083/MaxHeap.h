#ifndef MAX_HEAP_H
#define MAX_HEAP_H

class MaxHeap
{
public:
    MaxHeap();

    void insert(int value);
    void delete_();
    void maxHeapify(int rootindex);
    void printHeap() const;

private:
    static const int MAX_SIZE = 20;
    int mData[MAX_SIZE];
    int mSize;
};

#endif /* MAX_HEAP_H */
