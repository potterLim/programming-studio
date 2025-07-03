#include <iostream>

using namespace std;

int main()
{
    int maxValue = 0;
    int currentValue;

    for (int i = 0; i < 7; ++i)
    {
        cin >> currentValue;
        if (currentValue > maxValue)
        {
            maxValue = currentValue;
        }
    }

    cout << "최댓값: " << maxValue << endl;
    return 0;
}