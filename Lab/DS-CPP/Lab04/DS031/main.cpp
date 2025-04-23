#include <iostream>
#include <sstream>
#include <string>

#include "MyStack.h"

using namespace std;

int main()
{
    int size;
    cin >> size;
    cin.ignore();

    MyStack stack(size);

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
        else if (command == "print")
        {
            stack.Print();
            break;
        }
        else
        {
            cout << "Unknown command: " << command << endl;
        }
    }

    return 0;
}