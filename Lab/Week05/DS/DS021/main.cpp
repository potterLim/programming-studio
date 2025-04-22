#include "Student.h"

int main()
{
    Student student;

    cin >> student.sid >> student.score[0] >> student.score[1] >> student.score[2];
    cin.ignore();
    getline(cin, student.name);

    student.Print();

    return 0;
}