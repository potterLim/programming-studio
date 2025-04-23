#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string inputLine;
    getline(cin, inputLine);

    int blankCount = 0;
    int alphabetCount[26] = {0};

    for (char ch : inputLine)
    {
        if (ch == ' ')
        {
            ++blankCount;
        }
        else if (isalpha(ch))
        {
            alphabetCount[toupper(ch) - 'A']++;
        }
    }

    cout << "blanks : " << blankCount << endl;
    for (char c = 'A'; c <= 'Z'; ++c)
    {
        if (alphabetCount[c - 'A'] != 0)
        {
            cout << c << " : " << alphabetCount[c - 'A'] << endl;
        }
    }
    
    return 0;
}