#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string inputLine;
    getline(cin, inputLine);

    int alphaCount = 0;
    int digitCount = 0;
    int spaceCount = 0;
    for (char c : inputLine)
    {
        if (isalpha(c))
        {
            ++alphaCount;
        }
        else if (isdigit(c))
        {
            ++digitCount;
        }
        else if (isspace(c))
        {
            ++spaceCount;
        }
    }
    cout << "알파벳: " << alphaCount << endl;
    cout << "숫자: " << digitCount << endl;
    cout << "공백: " << spaceCount << endl;
    return 0;
}