#include <iostream>
#include "MyLLQueue.h"

using namespace std;

int main()
{
    int cardCount = 0;
    if (!(cin >> cardCount))
    {
        return 0;
    }

    MyLLQueue queue1;
    MyLLQueue queue2;
    for (int i = 0; i < cardCount; ++i)
    {
        int cardValue = 0;
        cin >> cardValue;
        queue1.Enqueue(cardValue);
    }
    for (int i = 0; i < cardCount; ++i)
    {
        int cardValue = 0;
        cin >> cardValue;
        queue2.Enqueue(cardValue);
    }

    int p1Score = 0;
    int p2Score = 0;
    int prevP1Duel = 0;
    int prevP2Duel = 0;
    int prevWinner = 0;

    for (int roundNumber = 1; roundNumber <= cardCount; ++roundNumber)
    {
        int card1 = queue1.ShowFront();
        queue1.Dequeue();
        int card2 = queue2.ShowFront();
        queue2.Dequeue();

        int duel1 = 0;
        int duel2 = 0;
        if (roundNumber == 1)
        {
            duel1 = card1;
            duel2 = card2;
        }
        else if (prevWinner == 1)
        {
            duel1 = card1 + (prevP1Duel - prevP2Duel - 1);
            duel2 = card2;
        }
        else if (prevWinner == 2)
        {
            duel1 = card1;
            duel2 = card2 + (prevP2Duel - prevP1Duel - 1);
        }
        else
        {
            duel1 = card1;
            duel2 = card2;
        }

        int winner = 0;
        if (duel1 > duel2)
        {
            winner = 1;
            ++p1Score;
            cout << "Round" << roundNumber << " - P1 win!" << "\n";
        }
        else if (duel2 > duel1)
        {
            winner = 2;
            ++p2Score;
            cout << "Round" << roundNumber << " - P2 win!" << "\n";
        }
        else
        {
            cout << "Round" << roundNumber << " - Draw!" << "\n";
        }

        prevP1Duel = duel1;
        prevP2Duel = duel2;
        prevWinner = winner;
    }

    if (p1Score > p2Score)
    {
        cout << "Final - P1 win!" << "\n";
    }
    else if (p2Score > p1Score)
    {
        cout << "Final - P2 win!" << "\n";
    }
    else
    {
        cout << "Final - Draw!" << "\n";
    }

    return 0;
}