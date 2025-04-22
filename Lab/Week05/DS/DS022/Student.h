#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

using namespace std;

class Student
{
public:
    Student();
    Student(const string& name, int lc, int rc);

    void Input();
    void PrintResult() const;

    string name;
    int lcScore;
    int rcScore;

private:
    bool isValidScore(int score) const;
    string getResult(int score) const;
};

#endif /* STUDENT_H */
