#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int sizeA, sizeB;
    cin >> sizeA >> sizeB;

    vector<int> allScores(sizeA + sizeB);

    for (int i = 0; i < sizeA; ++i)
    {
        cin >> allScores[i];
    }

    for (int i = sizeA; i < sizeA + sizeB; ++i)
    {
        cin >> allScores[i];
    }

    int totalSize = sizeA + sizeB;

    for (int i = 0; i < totalSize - 1; ++i)
    {
        for (int j = 0; j < totalSize - 1 - i; ++j)
        {
            if (allScores[j] < allScores[j + 1])
            {
                int temp = allScores[j];
                allScores[j] = allScores[j + 1];
                allScores[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < totalSize; ++i)
    {
        cout << allScores[i] << ' ';
    }
    cout << endl;

    return 0;
}
