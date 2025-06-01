#include <iostream>
#include <string>
#include "WordSorter.h"

using namespace std;

int main()
{
    int wordCount;
    cin >> wordCount;

    WordSorter sorter;
    for (int i = 0; i < wordCount; ++i)
    {
        string word;
        cin >> word;
        sorter.AddWord(word);
    }

    sorter.SortWords();
    sorter.PrintWords();

    return 0;
}
