#include <iostream>
#include "SortLibrary.h"

using namespace std;

int main()
{
    int choice = 0;
    while (true)
    {
        cout << "1.selection 2.insertion 3.bubble 4.quick 5.merge 6.exit > ";
        cin >> choice;
        if (choice == 6)
        {
            cout << "bye!" << "\n";
            break;
        }

        int count = 0;
        cout << "Enter count: ";
        cin >> count;
        int* numbers = new int[count];
        cout << "Enter numbers: ";
        for (int i = 0; i < count; ++i)
        {
            cin >> numbers[i];
        }

        switch (choice)
        {
            case 1:
                cout << "==== selection sort ====" << "\n";
                SelectionSort(numbers, count);
                break;
            case 2:
                cout << "==== insertion sort ====" << "\n";
                InsertionSort(numbers, count);
                break;
            case 3:
                cout << "==== bubble sort ====" << "\n";
                BubbleSortAscending(numbers, count);
                BubbleSortDescending(numbers, count);
                break;
            case 4:
                cout << "==== quick sort ====" << "\n";
                QuickSort(numbers, count);
                break;
            case 5:
                cout << "==== merge sort ====" << "\n";
                MergeSort(numbers, count);
                break;
        }

        delete[] numbers;
    }
    return 0;
}