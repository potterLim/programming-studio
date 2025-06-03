#include <iostream>
#include "SortLibrary.h"

using namespace std;

int main()
{
    int cardCount;
    int maxSwapCount;
    cin >> cardCount >> maxSwapCount;

    int* aDeck = new int[cardCount];
    int* bDeck = new int[cardCount];

    for (int i = 0; i < cardCount; ++i)
    {
        cin >> aDeck[i];
    }

    for (int i = 0; i < cardCount; ++i)
    {
        cin >> bDeck[i];
    }

    BubbleSortAscending(aDeck, cardCount);
    BubbleSortDescending(bDeck, cardCount);

    int swapCount = 0;
    for (int i = 0; i < cardCount && swapCount < maxSwapCount; ++i)
    {
        if (aDeck[i] < bDeck[i])
        {
            int temp = aDeck[i];
            aDeck[i] = bDeck[i];
            bDeck[i] = temp;
            ++swapCount;
        }
        else
        {
            break;
        }
    }

    int sum = 0;
    for (int i = 0; i < cardCount; ++i)
    {
        sum += aDeck[i];
    }

    cout << swapCount << " " << sum << endl;

    delete[] aDeck;
    delete[] bDeck;

    return 0;
}