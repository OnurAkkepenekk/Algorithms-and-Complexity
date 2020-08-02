#ifndef _SORTING_H_
#define _SORTING_H_

/****************************************************
 * Uses bubble sort to sort A[0..N-1]
 ****************************************************/
void BubbleSort(int A[], int N);

/****************************************************
 * Uses selection sort to sort A[0..N-1]
 ****************************************************/
void SelectionSort(int A[], int N);

/****************************************************
 * Uses insertion sort to sort A[0..N-1]
 ****************************************************/
void InsertionSort(int A[], int N);

/****************************************************
 * Uses mergesort to sort A[0..N-1]
 ****************************************************/
void MergeSort(int A[], int N);

/****************************************************
 * Uses quicksort sort to sort A[0..N-1]
 ****************************************************/
void QuickSort(int A[], int N);

/****************************************************
 * Uses heapsort to sort A[0..N]
 * NOTICE: The first element is in A[0] not in A[1]
 ****************************************************/
void HeapSort(int A[], int N);

/****************************************************
 * Uses radixsort to sort A[0..N]
 ****************************************************/
void RadixSort(int A[], int N);

/****************************************************
 * Uses countingsort to sort A[0..N]
 ****************************************************/
void CountingSort(int A[], int N);

#endif