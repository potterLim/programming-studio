#include <iostream>

#include "MyLLQueue.h"

using namespace std;

int main()
{
    MyLLQueue queue;

    while (true)
    {
        cout << "1.enqueue 2.dequeue 3.showfront 4.showrear 5.displayQueue 6.exit > ";
        int choice = 0;
        cin >> choice;

        if (choice == 6)
        {
            cout << "bye!\n";
            break;
        }

        if (choice == 1)
        {
            cout << "Enter a Value: ";
            int value = 0;
            cin >> value;
            queue.Enqueue(value);
        }
        else if (choice == 2)
        {
            queue.Dequeue();
        }
        else if (choice == 3)
        {
            if (queue.IsEmpty())
            {
                cout << "element at front: -1\n";
            }
            else
            {
                cout << "element at front: " << queue.ShowFront() << "\n";
            }
        }
        else if (choice == 4)
        {
            if (queue.IsEmpty())
            {
                cout << "element at rear: -1\n";
            }
            else
            {
                cout << "element at rear: " << queue.ShowRear() << "\n";
            }
        }
        else if (choice == 5)
        {
            queue.DisplayQueue();
        }
    }

    return 0;
}
