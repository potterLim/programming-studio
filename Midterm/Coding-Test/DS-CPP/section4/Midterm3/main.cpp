#include <iostream>
#include "Rectangle.h"

using namespace std;

int main()
{
    int widthValue;
    int heightValue;
    cout << "가로: ";
    cin >> widthValue;
    cout << "세로: ";
    cin >> heightValue;

    Rectangle rectangle(widthValue, heightValue);

    cout << "넓이: " << rectangle.GetArea() << endl;
    cout << "둘레: " << rectangle.GetPerimeter() << endl;
    return 0;
}