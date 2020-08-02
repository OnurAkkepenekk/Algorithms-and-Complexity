#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Sorting.h"

//#define N 1024*8192*2
//#define N 1024*4096
#define N 1024*32
int A[N];

typedef void (*SortingFunction)(int *, int);

/****************************************************
 * Test
 ****************************************************/
float Test(SortingFunction F, char *msg){
  int B[] = {4, 2, 5, 7, 8, 1, 10, 9, 15, 34, 6, 17, 66, 55, 44, 33};
 
  // Use the sorting algorithm
  F(B, 16);

  printf("Using %s to sort %d numbers...\n", msg, 16);

  // Check the result
  if (B[0]!=1 || B[1]!=2 || B[2]!=4 || B[3]!=5) return 0;
  if (B[4]!=6 || B[5]!=7 || B[6]!=8 || B[7]!=9) return 0;
  if (B[8]!=10 || B[9]!=15 || B[10]!=17 || B[11]!=33) return 0;
  if (B[12]!=34 || B[13]!=44 || B[14]!=55 || B[15]!=66) return 0;

  // Do a big test
  bool cs = false;
  if (strcmp(msg, "CountingSort") == 0) cs = true;

  srand((unsigned int)time(NULL));
  int i;
  int min = INT_MAX;
  int max = 0;
  for (i=0; i<N;i++){
    A[i]=rand();
    if (cs) A[i] = A[i] % 1000000;

    if (A[i]<min) min=A[i];
    else if (A[i]>max) max=A[i];
  } //end-for

  printf("Using %s to sort %d numbers...", msg, N);
  time_t t1 = time(NULL);
  F(A, N);
  time_t t2 = time(NULL);
  printf("took %I64d seconds\n", t2-t1);

  // Check the result
  if (A[0]!=min ||A[N-1]!=max) return 0;
  for (i=0; i<N-1; i++){
    if (A[i]>A[i+1]) return 0;
  } //end-for

  return 12.5;
} //end-Test

/****************************************************
 * Main function
 ****************************************************/
int main(){
  float grade = 0;

  printf("======================= TEST1 =======================\n");
  grade += Test(BubbleSort, "BubbleSort");

  printf("======================= TEST2 =======================\n");
  grade += Test(SelectionSort, "SelectionSort");

  printf("======================= TEST3 =======================\n");
  grade += Test(InsertionSort, "InsertionSort");

  printf("======================= TEST4 =======================\n");
  grade += Test(MergeSort, "MergeSort");

  printf("======================= TEST5 =======================\n");
  grade += Test(QuickSort, "QuickSort");

  printf("======================= TEST6 =======================\n");
  grade += Test(HeapSort, "HeapSort");

  printf("======================= TEST7 =======================\n");
  grade += Test(RadixSort, "RadixSort");

  printf("======================= TEST8 =======================\n");
  grade += Test(CountingSort, "CountingSort");

  printf("=====================================================\n");
  printf("Final grade: %.1f\n", grade);

  return 0;
} //end-main
