#include "Student.h"

Student::Student()
    : lcScore(0)
    , rcScore(0)
{
}

Student::Student(const string& name, int lc, int rc)
    : name(name)
    , lcScore(lc)
    , rcScore(rc)
{
}

void Student::Input()
{
    getline(cin, name);

    cout << "LC> ";
    cin >> lcScore;
    while (!isValidScore(lcScore))
    {
        cout << "LC> ";
        cin >> lcScore;
    }

    cout << "RC> ";
    cin >> rcScore;
    while (!isValidScore(rcScore))
    {
        cout << "RC> ";
        cin >> rcScore;
    }
}

void Student::PrintResult() const
{
    cout << "[" << name << "]" << endl;
    cout << "LC - " << lcScore << " " << getResult(lcScore) << endl;
    cout << "RC - " << rcScore << " " << getResult(rcScore) << endl;
    cout << "Total - " << (lcScore + rcScore) << endl;
}

bool Student::isValidScore(int score) const
{
    return score >= 0 && score <= 495;
}

string Student::getResult(int score) const
{
    if (score >= 350)
    {
        return "Pass";
    }

    return "Fail";
}