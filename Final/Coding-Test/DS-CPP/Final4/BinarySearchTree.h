#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "Node.h"

class BinarySearchTree
{
public:
    BinarySearchTree();

    void Insert(int value);
    void PrintInOrder() const;

private:
    Node* mRoot;

    Node* InsertInternal(Node* node, int value);
    void InOrderInternal(Node* node) const;
};

#endif /* BINARY_SEARCH_TREE_H */
