#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void AddLast(int value);
    void Print() const;
    void Clear();
    void SelectionSort();

private:
    class Node
    {
    public:
        int mData;
        Node* mNext;

        Node(int value);
    };

    Node* mHead;
    Node* mTail;
};

#endif /* LINKED_LIST_H */