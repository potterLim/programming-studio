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

void SelectionSort(int arr[], const int size)
{
#ifdef DEBUG
    PrintArray(arr, size);
#endif
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = i;
        
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
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
    SelectionSort(arr, size);

    delete[] arr;
    return 0;
}