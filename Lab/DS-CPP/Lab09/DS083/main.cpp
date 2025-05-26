#include <iostream>
#include "MaxHeap.h"

using namespace std;

int main()
{
    MaxHeap heap;
    int menu;

    while (true)
    {
        cout << "1. insert 2. delete 3. print 4. quit > ";
        cin >> menu;

        if (menu == 1)
        {
            int value;
            cout << "new value? ";
            cin >> value;
            heap.insert(value);
        }
        else if (menu == 2)
        {
            heap.delete_();
        }
        else if (menu == 3)
        {
            heap.printHeap();
        }
        else if (menu == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid option" << endl;
        }
    }

    cout << "Bye!" << endl;
    return 0;
}