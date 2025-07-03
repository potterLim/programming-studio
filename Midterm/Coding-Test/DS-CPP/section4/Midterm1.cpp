#include <iostream>

using namespace std;

int main()
{
    int inputNumber;
    cin >> inputNumber;
    if (inputNumber % 2 == 0)
    {
        cout << "짝수입니다." << endl;
    }
    else
    {
        cout << "홀수입니다." << endl;
    }
    return 0;
}