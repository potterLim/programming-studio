#include "WordSorter.h"
#include <iostream>
#include <algorithm>

using namespace std;

bool Compare(const string& a, const string& b)
{
    if (a.length() != b.length())
    {
        return a.length() < b.length();
    }

    return a < b;
}

void WordSorter::AddWord(const string& word)
{
    if (!Contains(word))
    {
        mWords.push_back(word);
    }
}

bool WordSorter::Contains(const string& word) const
{
    for (size_t i = 0; i < mWords.size(); ++i)
    {
        if (mWords[i] == word)
        {
            return true;
        }
    }

    return false;
}

void WordSorter::SortWords()
{
    sort(mWords.begin(), mWords.end(), Compare);
}

void WordSorter::PrintWords() const
{
    for (size_t i = 0; i < mWords.size(); ++i)
    {
        cout << mWords[i] << endl;
    }
}
