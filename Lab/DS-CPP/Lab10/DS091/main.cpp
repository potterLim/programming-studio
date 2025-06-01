#include <iostream>
#include <string>
#include <vector>

#include "MyLinkedStack.h"

using namespace std;

int main()
{
    string line;
    while (true)
    {
        if (!getline(cin, line))
        {
            break;
        }
        if (line == "q")
        {
            break;
        }

        MyLinkedStack leftStack;
        MyLinkedStack rightStack;

        for (size_t i = 0; i < line.size(); ++i)
        {
            char currentChar = line[i];
            if (currentChar == '<')
            {
                if (!leftStack.IsEmpty())
                {
                    rightStack.Push(leftStack.Top());
                    leftStack.Pop();
                }
            }
            else if (currentChar == '>')
            {
                if (!rightStack.IsEmpty())
                {
                    leftStack.Push(rightStack.Top());
                    rightStack.Pop();
                }
            }
            else
            {
                leftStack.Push(currentChar);
            }
        }

        string result;
        MyLinkedStack tempStack;
        while (!leftStack.IsEmpty())
        {
            tempStack.Push(leftStack.Top());
            leftStack.Pop();
        }
        while (!tempStack.IsEmpty())
        {
            result.push_back(tempStack.Top());
            leftStack.Push(tempStack.Top());
            tempStack.Pop();
        }

        vector<char> rightChars;
        while (!rightStack.IsEmpty())
        {
            rightChars.push_back(rightStack.Top());
            rightStack.Pop();
        }
        for (size_t j = 0; j < rightChars.size(); ++j)
        {
            result.push_back(rightChars[j]);
        }
        for (int k = static_cast<int>(rightChars.size()) - 1; k >= 0; --k)
        {
            rightStack.Push(rightChars[k]);
        }

        cout << "=> " << result << endl;
    }

    return 0;
}
