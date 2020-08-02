#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"
void heapify(int[], int, int);
void countSort(int[], int, int);
int getMax(int[], int);
/****************************************************
 * Uses bubble sort to sort A[0..N-1]
 ****************************************************/
void BubbleSort(int A[], int N) {
	// Fill this in
	int temp;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
} //end-BubbleSort

/****************************************************
 * Uses selection sort to sort A[0..N-1]
 ****************************************************/
void SelectionSort(int A[], int N) {
	// Fill this in
	int i, j, min_index, temp;
	for (i = 0; i < N - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < N; j++)
			if (A[j] < A[min_index])
				min_index = j;
		temp = A[i];
		A[i] = A[min_index];
		A[min_index] = temp;
	}
} //end-SelectionSort

/****************************************************
 * Uses insertion sort to sort A[0..N-1]
 ****************************************************/
void InsertionSort(int A[], int N) {
	// Fill this in
	int i, key, j;
	for (i = 1; i < N; i++)
	{
		key = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			j = j - 1;
		}
		A[j + 1] = key;
	}
} //end-InsertionSort

/****************************************************
 * Uses mergesort to sort A[0..N-1]
 ****************************************************/
int min(int x, int y)
{
	return (x < y) ? x : y;
}
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L = new int[n1];
	int* R = new int[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
void MergeSort(int A[], int N) {
	// Fill this in
	int curr_size;
	int left_start;
	for (curr_size = 1; curr_size <= N - 1; curr_size = 2 * curr_size)
	{
		for (left_start = 0; left_start < N - 1; left_start += 2 * curr_size)
		{
			int mid = min(left_start + curr_size - 1, N - 1);
			int right_end = min(left_start + 2 * curr_size - 1, N - 1);
			merge(A, left_start, mid, right_end);
		}
	}
}//end-MergeSort

/****************************************************
 * Uses quicksort sort to sort A[0..N-1]
 ****************************************************/
int partition(int A[], int l, int h)
{
	int x = A[h];
	int i = (l - 1);
	int temp = 0;
	for (int j = l; j <= h - 1; j++) {
		if (A[j] <= x)
		{
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	temp = A[i + 1];
	A[i + 1] = A[h];
	A[h] = temp;
	return (i + 1);
}
void QuickSort(int A[], int N)
{
	// Fill this in
	int l = 0;
	int h = N - 1;
	int* stack = new int[h - l + 1];
	int top = -1;
	stack[++top] = l;
	stack[++top] = h;
	while (top >= 0) {
		h = stack[top--];
		l = stack[top--];
		int p = partition(A, l, h);
		if (p - 1 > l) {
			stack[++top] = l;
			stack[++top] = p - 1;
		}
		if (p + 1 < h) {
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	} //end-QuickSort
}
/****************************************************
 * Uses heapsort to sort A[0..N]
 * NOTICE: The first element is in A[0] not in A[1]
 ****************************************************/
void HeapSort(int A[], int N) {
	// Fill this in
	int temp;
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(A, N, i);
	for (int i = N - 1; i > 0; i--)
	{
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		heapify(A, i, 0);
	}
} //end-HeapSort

/****************************************************
 * Uses radixsort to sort A[0..N]
 ****************************************************/
void RadixSort(int A[], int N) {
	// Fill this in
	int max = getMax(A, N);
	for (int place = 1; max / place > 0; place *= 10)
		countSort(A, N, place);
} //end-RadixSort

/****************************************************
 * Uses countingsort to sort A[0..N]
 ****************************************************/
void CountingSort(int A[], int N) {
	// Fill this in
	int max = getMax(A, N);
	int* output = new int[max];
	int* count = new int[max];
	// Initialize count array with all zeros.
	for (int i = 0; i <= max; ++i) {
		count[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		count[A[i]]++;
	}

	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}

	for (int i = N - 1; i >= 0; i--) {
		output[count[A[i]] - 1] = A[i];
		count[A[i]]--;
	}

	for (int i = 0; i < N; i++) {
		A[i] = output[i];
	}
} //end-CountingSort


int getMax(int A[], int N) {
	int max = A[0];
	for (int i = 1; i <= N - 1; i++)
	{
		if (A[i] > max)
			max = A[i];
	}
	return max;
}

void countSort(int Array[], int N, int place) {
	int* output = new int[N];
	int i, count[10] = { 0 };

	for (i = 0; i < N; i++)
		count[(Array[i] / place) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = N - 1; i >= 0; i--)
	{
		output[count[(Array[i] / place) % 10] - 1] = Array[i];
		count[(Array[i] / place) % 10]--;
	}
	for (i = 0; i < N; i++)
		Array[i] = output[i];
}

void heapify(int A[], int N, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if ((left < N) && (A[left] > A[largest]))
		largest = left;
	if ((right < N) && (A[right] > A[largest]))
		largest = right;
	if (largest != i)
	{
		int	temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		heapify(A, N, largest);
	}
}