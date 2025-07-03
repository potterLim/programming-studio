#include <iostream>
#include <string>
#include <sstream>

#include "LinkedListStack.h"

using namespace std;

int main()
{
    LinkedListStack stack;

    cout << "Enter postfix expression: ";
    string input;
    getline(cin, input);

    string token;
    istringstream iss(input);

    while (iss >> token)
    {
        if (isdigit(token[0]))
        {
            stack.Push(token[0]);
        }
        else
        {
            char rightOperand = stack.Pop();
            char leftOperand = stack.Pop();
            int result;

            switch (token[0])
            {
            case '+':
                result = (leftOperand - '0') + (rightOperand - '0');
                break;
            case '-':
                result = (leftOperand - '0') - (rightOperand - '0');
                break;
            case '*':
                result = (leftOperand - '0') * (rightOperand - '0');
                break;
            case '/':
                result = (leftOperand - '0') / (rightOperand - '0');
                break;
            default:
                cout << "Unknown operator: " << token << endl;
                return 1;
            }

            stack.Push(result + '0');
        }
    }

    if (!stack.IsEmpty())
    {
        cout << "Result: " << (stack.Pop() - '0') << endl;
    }
    else
    {
        cout << "Stack is empty" << endl;
    }

    return 0;
}
