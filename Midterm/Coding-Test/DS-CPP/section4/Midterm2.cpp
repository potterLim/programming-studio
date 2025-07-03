#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    int numbers[5];
    int sum = 0;
    for (int i = 0; i < 5; ++i)
    {
        cin >> numbers[i];
        sum += numbers[i];
    }
    double average = sum / 5.0;
    cout << "평균: " << fixed << setprecision(1) << average << endl;
    return 0;
}