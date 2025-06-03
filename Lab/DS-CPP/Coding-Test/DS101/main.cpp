#include <iostream>

#include "SortLibrary.h"

using namespace std;

int main()
{
    int count;
    cin >> count;

    int* numbers = new int[count];

    for (int index = 0; index < count; ++index)
    {
        cin >> numbers[index];
    }

    BubbleSortDescending(numbers, count);

    for (int index = 0; index < count; ++index)
    {
        cout << numbers[index] << " ";
    }
    cout << endl;

    delete[] numbers;
    return 0;
}
