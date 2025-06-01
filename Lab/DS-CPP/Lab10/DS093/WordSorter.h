#ifndef WORD_SORTER_H
#define WORD_SORTER_H

#include <string>
#include <vector>

class WordSorter
{
public:
    void AddWord(const std::string& word);
    void SortWords();
    void PrintWords() const;

private:
    std::vector<std::string> mWords;
    bool Contains(const std::string& word) const;
};

#endif /* WORD_SORTER_H */
