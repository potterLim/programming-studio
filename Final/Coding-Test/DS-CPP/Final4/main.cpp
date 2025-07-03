#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    const int NUM_NODES = 6;
    BinarySearchTree tree;

    cout << "Enter " << NUM_NODES << " integers: ";

    for (int i = 0; i < NUM_NODES; ++i)
    {
        int value;
        cin >> value;
        tree.Insert(value);
    }

    cout << "In-order traversal: ";
    tree.PrintInOrder();

    return 0;
}
