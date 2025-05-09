#include <iostream>
#include <fstream>

#include "MyCircularStudentQueue.h"

using namespace std;

int main()
{
    ifstream file("Data/input.txt");

    float gpa;
    string name;

    MyCircularStudentQueue studentQueue;
    float highestGpa = 0.0f;

    while (file >> gpa >> name)
    {
        StudentInfo student;
        student.gpa = gpa;
        student.name = name;

        studentQueue.Enqueue(student);

        if (gpa > highestGpa)
        {
            highestGpa = gpa;
        }
    }

    cout << "Highest GPA = " << highestGpa << endl;

    int count = studentQueue.Size();

    for (int i = 0; i < count; ++i)
    {
        const StudentInfo& student = studentQueue.Front();

        if (student.gpa == highestGpa)
        {
            cout << student.name << " " << student.gpa << endl;
        }

        studentQueue.Dequeue();
    }

    return 0;
}
