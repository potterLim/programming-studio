#include <iostream>

using namespace std;

int main()
{
    int heightCm;
    int weightKg;
    double bmi;

    cin >> heightCm >> weightKg;
    bmi = weightKg / ((heightCm / 100.0) * (heightCm / 100.0));

    if (bmi >= 25)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}