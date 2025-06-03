#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string inputString;
    cin >> inputString;

    stack<char> characterStack;

    for (char ch : inputString)
    {
        if (!characterStack.empty() && characterStack.top() == ch)
        {
            characterStack.pop();
        }
        else
        {
            characterStack.push(ch);
        }
    }

    string result;
    while (!characterStack.empty())
    {
        result += characterStack.top();
        characterStack.pop();
    }

    reverse(result.begin(), result.end());
    cout << result << endl;

    return 0;
}
