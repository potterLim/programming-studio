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

void InsertionSort(int arr[], const int size)
{
#ifdef DEBUG
    PrintArray(arr, size);
#endif
    for (int i = 1; i < size; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        
        arr[j + 1] = key;
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

    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
    InsertionSort(arr, size);

    delete[] arr;
    return 0;
}