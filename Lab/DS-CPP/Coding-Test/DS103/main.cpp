#include <iostream>

#include "SortLibrary.h"

using namespace std;

int main()
{
    int studentCount;
    int awardCount;
    cin >> studentCount >> awardCount;

    int* scores = new int[studentCount];
    for (int i = 0; i < studentCount; ++i)
    {
        cin >> scores[i];
    }

    BubbleSortDescending(scores, studentCount);

    cout << scores[awardCount - 1] << endl;

    delete[] scores;

    return 0;
}
