#include <iomanip>
#include <iostream>

using namespace std;

struct StudentScore
{
    int Kor;
    int Eng;
    int Math;
    int Total;
    double Average;
};

int main()
{
    StudentScore student;

    cin >> student.Kor >> student.Eng >> student.Math;
    student.Total = student.Kor + student.Eng + student.Math;
    student.Average = student.Total / 3.0;

    cout << student.Total << " " << fixed << setprecision(1) << student.Average << endl;

    cout << "Korean - ";
    if (student.Kor >= 70)
    {
        cout << "Pass" << endl;
    }
    else
    {
        cout << "Fail" << endl;
    }

    cout << "English - ";
    if (student.Eng >= 70)
    {
        cout << "Pass" << endl;
    }
    else
    {
        cout << "Fail" << endl;
    }

    cout << "Math - ";
    if (student.Math >= 70)
    {
        cout << "Pass" << endl;
    }
    else
    {
        cout << "Fail" << endl;
    }

    return 0;
}