#include<stdio.h>
#include<stdlib.h>

void heapify_down();
void heapify_up();
void print_arr(int*, int);

//Global heap array
int* heap;
int _index;

void swap(int i, int j) {
  int temp = heap[i];
  heap[i] = heap[j];
  heap[j] = temp;
}

void heap_push(int a) {
  heap[_index++] = a;
  heapify_up();
}

int heap_pop() {
  int temp = heap[0];
  heapify_down();
  return temp;
}

void heapify_up() {
  int i = _index - 1;
  while(i > 0 && heap[i] < heap[(i-1)/2]) {
    swap(i, (i-1)/2);
    i = (i-1)/2;
  }
}

void heapify_down() {
  heap[0] = heap[--_index];
  for (int i=0; i<(_index - 1)/2; i++) {
    if (heap[2*i+1] < heap[2*i+2]) {
      if (heap[i] > heap[2*i+1]) {
	swap(i, 2*i+1);
	i = 2*i+1;
      }
    }
    else {
      if (heap[i] > heap[2*i+2]) {
	swap(i, 2*i+2);
	i = 2*i+2;
      }
    }
  }
}

void heap_sort(int* arr, int size) {
  for (int i=0; i<size; i++)
    heap_push(arr[i]);

  for (int i=0; i<size; i++)
    arr[i] = heap_pop();
}

void initialize_heap(int size) {
  heap = (int*)malloc(size*sizeof(int));
  for(int i=0; i<size; i++)
    heap[i] = 99;
  _index = 0;
}

void print_arr(int* arr, int size) {
  for(int i=0; i<size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void main() {
  int arr[] = {9, 4, 5, 7, 10, 1, 0, 3};
  int size = sizeof(arr)/sizeof(arr[0]);
  initialize_heap(size);
  heap_sort(arr, size);
  print_arr(arr, size);
}
