#include <iostream>
#include <string>

using namespace std;

string GetCommonPrefix(const string& firstString, const string& secondString);

int main()
{
    string firstString;
    string secondString;
    string thirdString;

    cin >> firstString >> secondString >> thirdString;

    string prefixFirstSecond = GetCommonPrefix(firstString, secondString);
    string prefixAll = GetCommonPrefix(prefixFirstSecond, thirdString);

    if (prefixAll.size() == 0)
    {
        cout << "?" << endl;
    }
    else
    {
        cout << prefixAll << endl;
    }
    return 0;
}

string GetCommonPrefix(const string& firstString, const string& secondString)
{
    const char* cFirstString = firstString.c_str();
    const char* cSecondString = secondString.c_str();

    int i = 0;
    while (cFirstString[i] != '\0' && cSecondString[i] != '\0')
    {
        if (cFirstString[i] != cSecondString[i])
        {
            break;
        }
        ++i;
    }
    return firstString.substr(0, i);
}
