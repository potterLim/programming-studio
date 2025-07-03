#include <iostream>
#include <queue>

using namespace std;

int main()
{
    const int NUM_CARDS = 3;

    queue<int> player1Deck;
    queue<int> player2Deck;
    int cardInput;

    cout << "Player 1: ";
    for (int i = 0; i < NUM_CARDS; ++i)
    {
        cin >> cardInput;
        player1Deck.push(cardInput);
    }

    cout << "Player 2: ";
    for (int i = 0; i < NUM_CARDS; ++i)
    {
        cin >> cardInput;
        player2Deck.push(cardInput);
    }

    int player1WinCount = 0;
    int player2WinCount = 0;
    int drawCount = 0;

    for (int i = 0; i < NUM_CARDS; ++i)
    {
        int cardFromPlayer1 = player1Deck.front();
        player1Deck.pop();

        int cardFromPlayer2 = player2Deck.front();
        player2Deck.pop();

        if (cardFromPlayer1 > cardFromPlayer2)
        {
            ++player1WinCount;
        }
        else if (cardFromPlayer2 > cardFromPlayer1)
        {
            ++player2WinCount;
        }
        else
        {
            ++drawCount;
        }
    }

    if (player1WinCount > player2WinCount)
    {
        cout << "P1 wins! (" << player1WinCount << " : " << player2WinCount << ")" << endl;
    }
    else if (player2WinCount > player1WinCount)
    {
        cout << "P2 wins! (" << player2WinCount << " : " << player1WinCount << ")" << endl;
    }
    else
    {
        cout << "It's a tie! (" << player1WinCount << " : " << player2WinCount << ") and Draw: " << drawCount << endl;
    }

    return 0;
}
