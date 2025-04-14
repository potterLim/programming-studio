#include <iostream>
#include <fstream>
#include <string>

#include "MyStack.h"

using namespace std;

int main()
{
    MyStack stack(100);
    stack.Initialize();

    double highestGpa = 0.0;

    ifstream fin("Data/input.txt");
    if (!fin.is_open())
    {
        cerr << "Error: Failed to open the file." << endl;
        return 1;
    }

    double gpa;
    string name;
    while (fin >> gpa >> name)
    {
        if (gpa > highestGpa)
        {
            highestGpa = gpa;
            stack.Clear();
            Student student
            {
                gpa,
                name
            };
            stack.Push(student);
        }
        else if (gpa == highestGpa)
        {
            Student student
            {
                gpa,
                name
            };
            stack.Push(student);
        }
    }

    fin.close();

    stack.Print();

    return 0;
}