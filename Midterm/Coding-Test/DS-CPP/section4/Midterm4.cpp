#include <iostream>

using namespace std;

int main()
{
    int arraySize;
    cout << "배열 크기: ";
    cin >> arraySize;

    int* array = new int[arraySize];
    for (int i = 0; i < arraySize; ++i)
    {
        cin >> array[i];
    }
    for (int i = 0; i < arraySize; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;
    return 0;
}