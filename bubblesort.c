#include<stdio.h>

void swap(int* arr, int i, int j) {
  arr[i] ^= arr[j];
  arr[j] ^= arr[i];
  arr[i] ^= arr[j];
}

void bubble_sort(int* arr, int size) {
  for(int i=0; i<size - 1; i++)
    for(int j=0; j<size - 1; j++)
      if (arr[j+1] < arr[j])
	swap(arr, j, j+1);
}

void print_arr(int* arr, int size) {
  for(int i=0; i<size; i++)
    printf("%d ", arr[i]);
}

void main() {
  int arr[] = {9, 4, 5, 7, 10, 1, 0, 3};
  int size = sizeof(arr)/sizeof(arr[0]);
  bubble_sort(arr, size);
  print_arr(arr, size);
}
