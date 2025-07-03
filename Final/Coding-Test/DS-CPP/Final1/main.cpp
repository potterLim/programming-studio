#include <iostream>
#include <string>

#include "LinkedListStack.h"

using namespace std;

int main()
{
    LinkedListStack stack;

    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    for (char ch : input)
    {
        stack.Push(ch);
    }

    cout << "Reversed string: ";
    while (!stack.IsEmpty())
    {
        cout << stack.Pop();
    }

    cout << endl;
    return 0;
}
