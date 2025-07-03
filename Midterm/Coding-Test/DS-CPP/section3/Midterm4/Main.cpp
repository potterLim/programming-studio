#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;

int main()
{
    Queue queue;
    string command;

    while (true)
    {
        cin >> command;
        if (command == "enqueue")
        {
            int value;
            cin >> value;
            queue.Enqueue(value);
        }
        else if (command == "dequeue")
        {
            queue.Dequeue();
        }
        else if (command == "print")
        {
            queue.Print();
        }
        else
        {
            break;
        }
    }

    return 0;
}