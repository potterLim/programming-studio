#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    double startX;
    double startY;
    double endX;
    double endY;

    cin >> startX >> startY;
    cin >> endX >> endY;
    double distance = sqrt((endX - startX) * (endX - startX) + (endY - startY) * (endY - startY));

    cout << fixed << setprecision(1) << distance << endl;
    return 0;
}