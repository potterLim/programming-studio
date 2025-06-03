#ifndef SORT_LIBRARY_H
#define SORT_LIBRARY_H

#include <iostream>
using namespace std;

void SelectionSort(int arr[], int size);
void InsertionSort(int arr[], int size);
void BubbleSortAscending(int arr[], const int size);
void BubbleSortDescending(int arr[], const int size);
void QuickSort(int arr[], int size);
void MergeSort(int arr[], int size);

#endif  /* SORT_LIBRARY_H */