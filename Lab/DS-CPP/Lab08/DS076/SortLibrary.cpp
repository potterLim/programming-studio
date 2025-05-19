#include "SortLibrary.h"

static void PrintArray(const int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "[" << arr[i] << "] ";
    }
    cout << endl;
}

void SelectionSort(int arr[], int size)
{
    PrintArray(arr, size);
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
        PrintArray(arr, size);
    }
}

void InsertionSort(int arr[], int size)
{
    PrintArray(arr, size);
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
        PrintArray(arr, size);
    }
}

void BubbleSortAscending(int arr[], const int size)
{
    cout << "=== ascending order ===" << endl;
    PrintArray(arr, size);

    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
        PrintArray(arr, size);
    }
}

void BubbleSortDescending(int arr[], const int size)
{
    cout << "=== descending order ===" << endl;
    PrintArray(arr, size);
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - 1 - i; ++j)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
        PrintArray(arr, size);
    }
}

static void QuickSortRecursive(int arr[], int low, int high, int size)
{
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
    PrintArray(arr, size);
    QuickSortRecursive(arr, low, i, size);
    QuickSortRecursive(arr, i + 2, high, size);
}

void QuickSort(int arr[], int size)
{
    PrintArray(arr, size);
    QuickSortRecursive(arr, 0, size - 1, size);
}

static void Merge(int arr[], int left, int mid, int right, int size)
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
    PrintArray(arr, size);
}

static void MergeSortRecursive(int arr[], int left, int right, int size)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        MergeSortRecursive(arr, left, mid, size);
        MergeSortRecursive(arr, mid + 1, right, size);
        Merge(arr, left, mid, right, size);
    }
}

void MergeSort(int arr[], int size)
{
    PrintArray(arr, size);
    MergeSortRecursive(arr, 0, size - 1, size);
}
