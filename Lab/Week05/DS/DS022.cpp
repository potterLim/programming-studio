#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    Student() : lcScore(0), rcScore(0) {}
    Student(const string& name, int lc, int rc)
        : name(name), lcScore(lc), rcScore(rc)
    {
    }
    void Input()
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
    void PrintResult() const
    {
        cout << "[" << name << "]" << endl;
        cout << "LC - " << lcScore << " " << getResult(lcScore) << endl;
        cout << "RC - " << rcScore << " " << getResult(rcScore) << endl;
        cout << "Total - " << (lcScore + rcScore) << endl;
    }

private:
    bool isValidScore(int score) const
    {
        return score >= 0 && score <= 495;
    }
    string getResult(int score) const
    {
        return (score >= 350) ? "Pass" : "Fail";
    }
    string name;
    int lcScore;
    int rcScore;
};

int main()
{
    Student student;
    student.Input();
    student.PrintResult();
    return 0;
}
