#include <iostream>
#include <sstream>
#include <string>

#include "MyLinkedStack.h"

using namespace std;

int main()
{
    MyLinkedStack stack;
    string line;

    while (getline(cin, line))
    {
        istringstream iss(line);
        string command;
        iss >> command;

        if (command == "push")
        {
            int value;
            iss >> value;
            stack.Push(value);
        }
        else if (command == "pop")
        {
            stack.Pop();
        }
        else if (command == "top")
        {
            int topVal = stack.Top();
            if (!stack.IsEmpty())
            {
                cout << topVal << endl;
            }
        }
        else if (command == "print")
        {
            stack.PrintAll();
        }
        else if (command == "clear")
        {
            stack.Initialize();
        }
        else if (command == "q")
        {
            cout << "Bye!" << endl;
            break;
        }
        else
        {
            cout << "Unknown command: " << command << endl;
        }
    }

    return 0;
}
