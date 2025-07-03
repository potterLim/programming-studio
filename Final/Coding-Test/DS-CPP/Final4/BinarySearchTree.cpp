#include <iostream>

#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree()
    : mRoot(nullptr)
{
}

void BinarySearchTree::Insert(int value)
{
    mRoot = InsertInternal(mRoot, value);
}

Node* BinarySearchTree::InsertInternal(Node* node, int value)
{
    if (node == nullptr)
    {
        return new Node(value);
    }

    if (value < node->mData)
    {
        node->mLeft = InsertInternal(node->mLeft, value);
    }
    else
    {
        node->mRight = InsertInternal(node->mRight, value);
    }

    return node;
}

void BinarySearchTree::PrintInOrder() const
{
    InOrderInternal(mRoot);
    cout << endl;
}

void BinarySearchTree::InOrderInternal(Node* node) const
{
    if (node == nullptr)
    {
        return;
    }

    InOrderInternal(node->mLeft);
    cout << node->mData << " ";
    InOrderInternal(node->mRight);
}
