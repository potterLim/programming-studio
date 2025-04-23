#include <iostream>

using namespace std;

int GetSum(int* pArr, int elementCount);
int GetMax(int* pArr, int elementCount);

int main()
{
    int elementCount;
    cin >> elementCount;

    int* pNumbers = new int[elementCount];
    for (int i = 0; i < elementCount; ++i)
    {
        cin >> pNumbers[i];
    }

    int totalSum = GetSum(pNumbers, elementCount);
    int maxValue = GetMax(pNumbers, elementCount);

    cout << totalSum << " " << maxValue << endl;

    delete[] pNumbers;
    return 0;
}

int GetSum(int* pArr, int elementCount)
{
    int totalSum = 0;
    for (int i = 0; i < elementCount; ++i)
    {
        totalSum += pArr[i];
    }
    return totalSum;
}

int GetMax(int* pArr, int elementCount)
{
    int maxValue = pArr[0];
    for (int i = 1; i < elementCount; ++i)
    {
        if (pArr[i] > maxValue)
        {
            maxValue = pArr[i];
        }
    }
    return maxValue;
}
