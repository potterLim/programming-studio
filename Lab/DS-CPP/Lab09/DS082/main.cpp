#include <iostream>
#include "TreeNode.h"

using namespace std;

int main()
{
    int nodeCount;
    int traversalType;

    cin >> nodeCount >> traversalType;

    int* nodeValues = new int[nodeCount];

    for (int i = 0; i < nodeCount; ++i)
    {
        cin >> nodeValues[i];
    }

    TreeNode* pRoot = BuildTree(nodeValues, nodeCount);

    if (traversalType == 1)
    {
        cout << "preorder traversal: ";
        PreorderTraversal(pRoot);
    }
    else if (traversalType == 2)
    {
        cout << "postorder traversal: ";
        PostorderTraversal(pRoot);
    }
    else
    {
        cout << "Invalid traversal type. Please enter 1 for preorder or 2 for postorder." << endl;
    }

    DeleteTreeRecursive(pRoot);
    delete[] nodeValues;

    return 0;
}