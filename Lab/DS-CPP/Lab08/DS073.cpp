#include <iostream>

#define DEBUG

using namespace std;

#ifdef DEBUG
void PrintArray(const int arr[], const int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "[" << arr[i] << "] ";
    }
    cout << endl;
}
#endif

void BubbleSortAscending(int arr[], const int size)
{
#ifdef DEBUG
    cout << "=== ascending order ===" << endl;
    PrintArray(arr, size);
#endif

    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
#ifdef DEBUG
        PrintArray(arr, size);
#endif
    }
}

void BubbleSortDescending(int arr[], const int size)
{
#ifdef DEBUG
    cout << "=== descending order ===" << endl;
    PrintArray(arr, size);
#endif
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - 1 - i; ++j)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
#ifdef DEBUG
        PrintArray(arr, size);
#endif
    }
}

int main()
{
    int size;
    cin >> size;
    int* arr = new int[size];
    int* arrCopy = new int[size];

    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
        arrCopy[i] = arr[i];
    }
    BubbleSortAscending(arr, size);
    BubbleSortDescending(arrCopy, size);

    delete[] arr;
    delete[] arrCopy;
    return 0;
}