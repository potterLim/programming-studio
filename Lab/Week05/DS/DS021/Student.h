#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Student
{
public:
    Student();
    ~Student();

    string name;
    string sid;
    int* score;

    void Print() const;

private:
    double getAvg() const;
};

#endif // STUDENT_H