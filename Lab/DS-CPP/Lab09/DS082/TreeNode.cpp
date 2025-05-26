#include <iostream>
#include <queue>
#include "TreeNode.h"

using namespace std;

TreeNode::TreeNode(int value)
    : mValue(value)
    , mLeft(nullptr)
    , mRight(nullptr)
{
}

TreeNode* BuildTree(const int* const nodeValues, const int nodeCount)
{
    if (nodeCount == 0 || nodeValues[0] == 0)
    {
        return nullptr;
    }

    TreeNode* pRoot = new TreeNode(nodeValues[0]);
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(pRoot);

    int i = 1;

    while (i < nodeCount)
    {
        TreeNode* pCurrent = nodeQueue.front();
        nodeQueue.pop();

        if (i < nodeCount && nodeValues[i] != 0)
        {
            pCurrent->mLeft = new TreeNode(nodeValues[i]);
            nodeQueue.push(pCurrent->mLeft);
        }
        ++i;

        if (i < nodeCount && nodeValues[i] != 0)
        {
            pCurrent->mRight = new TreeNode(nodeValues[i]);
            nodeQueue.push(pCurrent->mRight);
        }
        ++i;
    }

    return pRoot;
}

void DeleteTreeRecursive(TreeNode* const pRoot)
{
    if (pRoot == nullptr)
    {
        return;
    }

    DeleteTreeRecursive(pRoot->mLeft);
    DeleteTreeRecursive(pRoot->mRight);
    delete pRoot;
}

void PreorderTraversal(TreeNode* const pRoot)
{
    if (pRoot == nullptr)
    {
        return;
    }

    cout << pRoot->mValue << " ";
    PreorderTraversal(pRoot->mLeft);
    PreorderTraversal(pRoot->mRight);
}

void PostorderTraversal(TreeNode* const pRoot)
{
    if (pRoot == nullptr)
    {
        return;
    }

    PostorderTraversal(pRoot->mLeft);
    PostorderTraversal(pRoot->mRight);
    cout << pRoot->mValue << " ";
}