#include <iostream>
#include "StudentList.h"

using namespace std;

int main()
{
    int studentCount;
    cin >> studentCount;

    StudentList list;

    for (int i = 0; i < studentCount; ++i)
    {
        int score;
        string name;
        cin >> score >> name;
        list.AddStudent(score, name);
    }

    list.BubbleSortDescending();
    list.PrintList();

    return 0;
}