#include <deque>
#include <iostream>

using namespace std;

int main()
{
    int numCards;
    cin >> numCards;

    deque<int> cards;
    for (int i = 1; i <= numCards; ++i)
    {
        cards.push_back(i);
    }

    while (cards.size() > 1)
    {
        cards.pop_front();

        int topCard = cards.front();
        cards.pop_front();
        cards.push_back(topCard);
    }

    cout << cards.front() << endl;

    return 0;
}
