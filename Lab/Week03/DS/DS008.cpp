#include <iostream>
#include <string>

using namespace std;

int main()
{
    string romanStr;
    getline(cin, romanStr);

    int totalValue = 0;
    for (int i = 0; i < (int)romanStr.size(); ++i)
    {
        char romanChar = romanStr[i];
        if (romanChar == 'I')
        {
            if (i + 1 < (int)romanStr.size() && (romanStr[i + 1] == 'V' || romanStr[i + 1] == 'X'))
            {
                totalValue -= 1;
            }
            else
            {
                totalValue += 1;
            }
        }
        else if (romanChar == 'V')
        {
            totalValue += 5;
        }
        else if (romanChar == 'X')
        {
            if (i + 1 < (int)romanStr.size() && (romanStr[i + 1] == 'L' || romanStr[i + 1] == 'C'))
            {
                totalValue -= 10;
            }
            else
            {
                totalValue += 10;
            }
        }
        else if (romanChar == 'L')
        {
            totalValue += 50;
        }
        else if (romanChar == 'C')
        {
            if (i + 1 < (int)romanStr.size() && (romanStr[i + 1] == 'D' || romanStr[i + 1] == 'M'))
            {
                totalValue -= 100;
            }
            else
            {
                totalValue += 100;
            }
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