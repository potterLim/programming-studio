#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList list;
    int size;

    while (true)
    {
        cout << "How many numbers do you want to create (0:exit) ... ";
        cin >> size;

        if (size == 0)
        {
            cout << "bye!" << endl;
            break;
        }

        cout << "Enter numbers: ";
        for (int i = 0; i < size; ++i)
        {
            int number;
            cin >> number;
            list.AddLast(number);
        }

        list.SelectionSort();
        cout << "Sorted list:\n";
        list.Print();

        list.Clear();
    }

    return 0;
}
