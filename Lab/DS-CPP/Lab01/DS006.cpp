#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Subject
{
    string Name;
    int Credit;
    int Score;
    string LetterGrade;
    double GradePoint;
};

int main()
{
    Subject subjects[3];
    double totalWeighted = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < 3; ++i)
    {
        string inputLine;
        getline(cin, inputLine);

        stringstream ss(inputLine);
        vector<string> tokens;
        string token;

        while (ss >> token)
        {
            tokens.push_back(token);
        }

        subjects[i].Score = stoi(tokens.back());
        tokens.pop_back();
        subjects[i].Credit = stoi(tokens.back());
        tokens.pop_back();

        subjects[i].Name.clear();
        for (int j = 0; j < (int)tokens.size(); ++j)
        {
            subjects[i].Name += tokens[j];
            if (j < (int)tokens.size() - 1)
            {
                subjects[i].Name += " ";
            }
        }

        if (subjects[i].Score >= 95)
        {
            subjects[i].LetterGrade = "A+";
            subjects[i].GradePoint = 4.5;
        }
        else if (subjects[i].Score >= 90)
        {
            subjects[i].LetterGrade = "A";
            subjects[i].GradePoint = 4.0;
        }
        else if (subjects[i].Score >= 85)
        {
            subjects[i].LetterGrade = "B+";
            subjects[i].GradePoint = 3.5;
        }
        else if (subjects[i].Score >= 80)
        {
            subjects[i].LetterGrade = "B";
            subjects[i].GradePoint = 3.0;
        }
        else if (subjects[i].Score >= 75)
        {
            subjects[i].LetterGrade = "C+";
            subjects[i].GradePoint = 2.5;
        }
        else if (subjects[i].Score >= 70)
        {
            subjects[i].LetterGrade = "C";
            subjects[i].GradePoint = 2.0;
        }
        else if (subjects[i].Score >= 65)
        {
            subjects[i].LetterGrade = "D+";
            subjects[i].GradePoint = 1.5;
        }
        else if (subjects[i].Score >= 60)
        {
            subjects[i].LetterGrade = "D";
            subjects[i].GradePoint = 1.0;
        }
        else
        {
            subjects[i].LetterGrade = "F";
            subjects[i].GradePoint = 0.0;
        }

        totalCredits += subjects[i].Credit;
        totalWeighted += subjects[i].GradePoint * subjects[i].Credit;
    }

    double gpa = totalWeighted / totalCredits;
    for (int i = 0; i < 3; ++i)
    {
        cout << subjects[i].Name << "(" << subjects[i].Credit << ") " << subjects[i].LetterGrade << " " << fixed << setprecision(1) << subjects[i].GradePoint << endl;
    }
    cout << "Total Credits " << totalCredits << ", GPA " << fixed << setprecision(2) << floor(gpa * 100) / 100 << endl;

    return 0;
}