#include <iostream>
#include "MaxHeap.h"

using namespace std;

int main()
{
    int totalCount;
    int k;

    cin >> totalCount >> k;

    MaxHeap heap;
    for (int i = 0; i < totalCount; ++i)
    {
        int number;
        cin >> number;
        heap.Insert(number);
    }

    int result = -1;
    for (int j = 0; j < k; ++j)
    {
        result = heap.Delete();
    }

    cout << result << endl;
    return 0;
}