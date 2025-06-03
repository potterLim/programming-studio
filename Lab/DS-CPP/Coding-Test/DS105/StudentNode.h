#ifndef STUDENT_NODE_H
#define STUDENT_NODE_H

#include <string>

class StudentNode
{
public:
    int mScore;
    std::string mName;
    StudentNode* mNext;

    StudentNode(int score, const std::string& name);
};

#endif /* STUDENT_NODE_H */
