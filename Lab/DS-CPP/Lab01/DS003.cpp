#include <iostream>

using namespace std;

int main()
{
    int month;
    int day;
    int totalDays = 0;
    int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    cin >> month >> day;

    for (int i = 0; i < month - 1; ++i)
    {
        totalDays += daysPerMonth[i];
    }
    totalDays += day;

    cout << totalDays << endl;
    return 0;
}