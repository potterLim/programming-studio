#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    Student() : score(new int[3]) {}
    ~Student()
    {
        delete[] score;
    }
    void Print() const
    {
        cout << "[" << sid << "] " << name << endl;
        cout.setf(ios::fixed);
        cout.precision(1);
        cout << "The Average score is " << getAvg() << endl;
    }
    string name;
    string sid;
    int *score;

private:
    double getAvg() const
    {
        double sum = 0;
        for (int i = 0; i < 3; ++i)
        {
            sum += score[i];
        }
        return sum / 3.0;
    }
};

int main()
{
    Student student;
    cin >> student.sid >> student.score[0] >> student.score[1] >> student.score[2];
    cin.ignore();
    getline(cin, student.name);
    student.Print();
    return 0;
}
