#include <iostream>
#include <string>

using namespace std;

string LTrim(const string& inputStr);
string RTrim(const string& inputStr);
int GetLastWordLength(const string& inputStr);

int main()
{
    string inputStr;
    getline(cin, inputStr);

    inputStr = LTrim(inputStr);
    inputStr = RTrim(inputStr);

    cout << GetLastWordLength(inputStr) << endl;
    return 0;
}

string LTrim(const string& inputStr)
{
    size_t startPos = inputStr.find_first_not_of(" \t");
    if (startPos == string::npos)
    {
        return "";
    }
    return inputStr.substr(startPos);
}

string RTrim(const string& inputStr)
{
    size_t endPos = inputStr.find_last_not_of(" \t");
    if (endPos == string::npos)
    {
        return "";
    }
    return inputStr.substr(0, endPos + 1);
}

int GetLastWordLength(const string& inputStr)
{
    if (inputStr.empty())
    {
        return 0;
    }

    size_t lastSpace = inputStr.find_last_of(" \t");
    if (lastSpace == string::npos)
    {
        return static_cast<int>(inputStr.size());
    }

    return static_cast<int>(inputStr.size() - (lastSpace + 1));
}
