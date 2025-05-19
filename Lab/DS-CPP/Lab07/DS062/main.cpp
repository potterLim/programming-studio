#include <iostream>
#include "MyLLQueue.h"

using namespace std;

static const char* GetOrdinalSuffix(const int number)
{
    int mod100 = number % 100;
    if (mod100 >= 11 && mod100 <= 13)
    {
        return "th";
    }
    int mod10 = number % 10;
    if (mod10 == 1)
    {
        return "st";
    }
    else if (mod10 == 2)
    {
        return "nd";
    }
    else if (mod10 == 3)
    {
        return "rd";
    }
    else
    {
        return "th";
    }
}

int main()
{
    int termCount = 0;
    if (!(cin >> termCount))
    {
        return 0;
    }
    if (termCount >= 1)
    {
        cout << "1st : 1\n";
    }
    if (termCount >= 2)
    {
        cout << "2nd : 1\n";
    }
    if (termCount >= 3)
    {
        MyLLQueue windowQueue;
        windowQueue.Enqueue(1);
        windowQueue.Enqueue(1);
        for (int i = 3; i <= termCount; ++i)
        {
            int previousValue = windowQueue.ShowFront();
            int lastValue = windowQueue.ShowRear();
            int currentValue = previousValue + lastValue;

            windowQueue.Dequeue();
            windowQueue.Enqueue(currentValue);

            cout << i << GetOrdinalSuffix(i) << " : " << currentValue << "\n";
        }
        cout << "=> fibonacci(" << termCount << ") : " << windowQueue.ShowRear() << "\n";
    }
    else
    {
        cout << "=> fibonacci(" << termCount << ") : 1\n";
    }
    return 0;
}