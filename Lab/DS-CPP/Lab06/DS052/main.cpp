#include <iostream>
#include <string>

#include "MyCircularQueue.h"

using namespace std;

int main()
{
    int capacity = 0;
    if (!(cin >> capacity))
    {
        return 0;
    }

    MyCircularQueue queue(capacity);
    queue.Initialize();

    while (true)
    {
        string command;
        cin >> command;
        if (command == "q")
        {
            cout << "bye!\n";
            break;
        }

        if (command == "en")
        {
            int value = 0;
            cin >> value;
            queue.Enqueue(value);
        }
        else if (command == "de")
        {
            queue.Dequeue();
        }
        else if (command == "front")
        {
            if (queue.IsEmpty())
            {
                cout << "=> -1\n";
            }
            else
            {
                cout << "=> " << queue.Front() << "\n";
            }
        }
        else if (command == "rear")
        {
            if (queue.IsEmpty())
            {
                cout << "=> -1\n";
            }
            else
            {
                cout << "=> " << queue.Rear() << "\n";
            }
        }
        else if (command == "size")
        {
            cout << "=> " << queue.Size() << "\n";
        }
        else if (command == "empty")
        {
            cout << "=> " << (queue.IsEmpty() ? 1 : 0) << "\n";
        }
        else if (command == "print")
        {
            int count = queue.Size();
            for (int i = 0; i < count; ++i)
            {
                int frontValue = queue.Front();
                cout << frontValue;
                if (i + 1 < count)
                {
                    cout << " => ";
                }
                queue.Dequeue();
                queue.Enqueue(frontValue);
            }
            cout << "\n";
        }
    }

    return 0;
}
