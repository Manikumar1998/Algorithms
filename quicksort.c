#include<stdio.h>

#define N 9

void swap(int* arr, int i, int j){
  arr[i] ^= arr[j];
  arr[j] ^= arr[i];
  arr[i] ^= arr[j];
}

int partition(int* arr,int low,int high){
  int pivot = arr[high];

  int r = high-1;
  int l = low;

  /* printf("%d %d\n", l, r); */
  
  for(int i=l; i<=r; i++){
    if(arr[i] >= pivot){
      for(int j=r; j>=l; j--){
	if(arr[j] <= pivot){
	  swap(arr, i, j);
	  break;
	}
	else if(j == i){
	  swap(arr, j, high);
	  printf("a");
	  return j;
	}
      }
    }
  }
  printf("b");
  return high;
}

void print(int* arr){
  for(int i=0; i<N; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void quicksort(int* arr,int low, int high){
  if(low < high){
    printf("Low: %d, High: %d ", low, high);
    int pi = partition(arr, low, high);
    printf("PI: %d     ", pi);
    print(arr);
    quicksort(arr, low, pi-1);
    quicksort(arr, pi+1, high);
  }
}

int main(){
  int arr[] = {3, 5, 8, 1, 2, 9, 4, 7, 6};
  /* int arr[]  = {2, 6, 9, 1, 4, 8, 5, 3, 7}; */
  quicksort(arr, 0, N-1);
  for(int i=0; i<N; i++)
    printf("%d ", arr[i]);
  return 0;
}
