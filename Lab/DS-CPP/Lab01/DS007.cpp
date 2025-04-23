#include <iostream>
#include <string>

using namespace std;

int main()
{
    string romanStr;
    getline(cin, romanStr);

    int totalValue = 0;
    for (char romanChar : romanStr)
    {
        if (romanChar == 'I')
        {
            totalValue += 1;
        }
        else if (romanChar == 'V')
        {
            totalValue += 5;
        }
        else if (romanChar == 'X')
        {
            totalValue += 10;
        }
        else if (romanChar == 'L')
        {
            totalValue += 50;
        }
        else if (romanChar == 'C')
        {
            totalValue += 100;
        }
        else if (romanChar == 'D')
        {
            totalValue += 500;
        }
        else if (romanChar == 'M')
        {
            totalValue += 1000;
        }
    }

    cout << totalValue << endl;
    return 0;
}