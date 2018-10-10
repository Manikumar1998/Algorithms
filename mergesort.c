#include<stdio.h>
#include<stdlib.h>

#define N 10

void merge(int* arr, int start, int mid, int end) {
  int size1 = mid-start+1;
  int size2 = end-mid;
  int left[size1];
  int right[size2];

  for(int i=0; i<size1; i++)
    left[i] = arr[i+start];

  for(int i=0; i<size2; i++)
    right[i] = arr[mid+i+1];

  int l_index = 0;
  int r_index = 0;
  int arr_index = start;

    
  while(l_index < size1 && r_index < size2) {
    if (left[l_index] < right[r_index]) {
      arr[arr_index] = left[l_index];
      l_index++;
    }
    else {
      arr[arr_index] = right[r_index];
      r_index++;
    }
    arr_index++;
  }

  while(l_index < size1) {
    arr[arr_index] = left[l_index];
    arr_index++;
    l_index++;
  }

  while(r_index < size2) {
    arr[arr_index] = right[r_index];
    arr_index++;
    r_index++;
  }
  
}


void mergesort(int* arr, int start, int end) {
  if(start < end) {
    int mid = (start+end)/2;
    mergesort(arr, start, mid);
    mergesort(arr, mid+1, end);
    merge(arr, start, mid, end);
  }
}


void main() {
  int arr[N] = {7, 8, 1, 4, 3, 9, 6, 2, 5, 10};
  mergesort(arr, 0, N);
  for(int i=0; i<N; i++)
    printf("%d ", arr[i]);

}
