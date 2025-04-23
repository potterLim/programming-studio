#include "Student.h"

Student::Student()
    : score(new int[3])
{
}

Student::~Student()
{
    delete[] score;
}

void Student::Print() const
{
    cout << "[" << sid << "] " << name << endl;
    cout.setf(ios::fixed);
    cout.precision(1);
    cout << "The Average score is " << getAvg() << endl;
}

double Student::getAvg() const
{
    double sum = 0;

    for (int i = 0; i < 3; ++i)
    {
        sum += score[i];
    }

    return sum / 3.0;
}