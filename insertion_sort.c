#include<stdio.h>

void print_arr(int*, int);

void insertion_sort(int* arr, int size) {
  int j, temp;
  for (int i=0; i<size; i++) {
    j = i;
    temp = arr[j];
    while(j > 0 && arr[j-1] > temp) {
      arr[j] = arr[j-1];
      j--;
    }
    arr[j] = temp;
  }
}

void print_arr(int* arr, int size) {
  for(int i=0; i<size; i++)
    printf("%d ", arr[i]);
}

void main() {
  int arr[] = {9, 4, 5, 7, 10, 1, 0, 3};
  int size = sizeof(arr)/sizeof(arr[0]);
  insertion_sort(arr, size);
  print_arr(arr, size);
}
