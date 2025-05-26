#ifndef TREE_NODE_H
#define TREE_NODE_H

class TreeNode
{
public:
    int mValue;
    TreeNode* mLeft;
    TreeNode* mRight;

    explicit TreeNode(int value);
};

TreeNode* BuildTree(const int* const nodeValues, const int nodeCount);
void DeleteTreeRecursive(TreeNode* const pRoot);
void PreorderTraversal(TreeNode* const pRoot);
void PostorderTraversal(TreeNode* const pRoot);

#endif /* TREE_NODE_H */
