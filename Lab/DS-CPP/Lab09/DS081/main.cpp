#include <iostream>
#include "TreeNode.h"

using namespace std;

int main()
{
    int nodeCount;
    cin >> nodeCount;

    int* nodeValues = new int[nodeCount];

    for (int i = 0; i < nodeCount; ++i)
    {
        cin >> nodeValues[i];
    }

    TreeNode* pRoot = BuildTree(nodeValues, nodeCount);
    PrintInOrderRecursive(pRoot);
    DeleteTreeRecursive(pRoot);

    delete[] nodeValues;
    return 0;
}