#include <iostream>
#include "Circle.h"

using namespace std;

int main()
{
    cout << "반지름 입력: ";
    int radius;
    cin >> radius;

    Circle circle(radius);
    cout << "원의 넓이: " << circle.GetArea() << endl;

    return 0;
}