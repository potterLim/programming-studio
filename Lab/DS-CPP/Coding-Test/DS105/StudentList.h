#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#include "StudentNode.h"

class StudentList
{
public:
    StudentList();
    ~StudentList();

    void AddStudent(int score, const std::string& name);
    void BubbleSortDescending();
    void PrintList() const;
    void Clear();

private:
    StudentNode* mHead;
    StudentNode* mTail;
};

#endif /* STUDENT_LIST_H */