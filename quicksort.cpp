#include<iostream>
using namespace std;

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

  for(int i=l; i<=r; i++){
    if(arr[i] >= pivot){
      for(int j=r; j>=l; j--){
	if(arr[j] <= pivot){
	  swap(arr, i, j);
	  break;
	}
	else if(j == i){
	  swap(arr, j, high);
	  return j;
	}
      }
    }
  }
}


void quicksort(int* arr,int low, int high){
  if(low <= high){
    int pi = partition(arr, low, high);
    quicksort(arr, low, pi-1);
    quicksort(arr, pi+1, high);
  }
}

int main(){
  int arr[] = {6, 7, 3, 2, 9, 8, 1, 4, 5};
  quicksort(arr, 0, N-1);
  for(int i=0; i<N; i++)
    cout << arr[i]<< " ";
  return 0;
}
