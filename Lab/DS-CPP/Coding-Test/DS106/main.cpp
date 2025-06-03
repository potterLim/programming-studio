#include <iostream>
#include "MinHeap.h"

using namespace std;

int main()
{
    MinHeap heap;
    int command;

    while (true)
    {
        cout << "1. Array to minHeap 2.insert 3.delete 4.print 0.quit > ";
        cin >> command;

        if (command == 1)
        {
            int count;
            cin >> count;
            for (int index = 0; index < count; ++index)
            {
                int value;
                cin >> value;
                heap.InsertKey(value);
            }
            cout << "minHeap => ";
            heap.PrintHeap();
        }
        else if (command == 2)
        {
            int value;
            cin >> value;
            heap.InsertKey(value);
            cout << "minHeap => ";
            heap.PrintHeap();
        }
        else if (command == 3)
        {
            heap.DeleteKey();
            cout << "minHeap => ";
            heap.PrintHeap();
        }
        else if (command == 4)
        {
            heap.PrintHeap();
        }
        else if (command == 0)
        {
            cout << "bye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid command" << endl;
        }
    }

    return 0;
}