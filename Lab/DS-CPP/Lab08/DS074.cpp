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

void QuickSort(int arr[], int low, int high, const int size, bool isInitialCall = false)
{
#ifdef DEBUG
    if (isInitialCall)
    {
        PrintArray(arr, size);
    }
#endif
    if (low >= high) 
    {
        return;
    }
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (arr[j] < pivot)
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
#ifdef DEBUG
    PrintArray(arr, size);
#endif
    QuickSort(arr, low, i, size);
    QuickSort(arr, i + 2, high, size);
}

void QuickSort(int arr[], const int size)
{
    QuickSort(arr, 0, size - 1, size, true);
}

int main()
{
    int size;
    cin >> size;
    int* arr = new int[size];

    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
    QuickSort(arr, size);

    delete[] arr;
    return 0;
}