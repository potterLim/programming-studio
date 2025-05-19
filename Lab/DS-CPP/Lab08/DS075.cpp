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

void Merge(int arr[], int left, int mid, int right, const int size)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    for (int i = 0; i < n1; ++i) 
    {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) 
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j]) 
        {
            arr[k++] = leftArr[i++];
        }
        else 
        {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1) 
    {
        arr[k++] = leftArr[i++];
    }
    while (j < n2) 
    {
        arr[k++] = rightArr[j++];
    }

    delete[] leftArr;
    delete[] rightArr;
#ifdef DEBUG
    PrintArray(arr, size);
#endif
}

void MergeSort(int arr[], int left, int right, const int size, bool isInitialCall = false)
{
#ifdef DEBUG
    if (isInitialCall)
    {
        PrintArray(arr, size);
    }
#endif

    if (left < right)
    {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid, size);
        MergeSort(arr, mid + 1, right, size);
        Merge(arr, left, mid, right, size);
    }
}

void MergeSort(int arr[], const int size)
{
    MergeSort(arr, 0, size - 1, size, true);
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
    MergeSort(arr, size);

    delete[] arr;
    return 0;
}