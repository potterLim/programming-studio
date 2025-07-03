#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string inputLine;
    getline(cin, inputLine);

    reverse(inputLine.begin(), inputLine.end());
    cout << inputLine << endl;

    return 0;
}