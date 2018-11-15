#include<stdio.h>
#include<limits.h>

#define _min(a, b)({(a < b)?a:b;})

void print_matrix(int arr[][4], int m, int n) {
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

void floyd_warshall(int arr[][4], int size) {
  for (int k=0; k<size; k++)
    for(int i=0; i<size; i++)
      for(int j=0; j<size; j++)
	arr[i][j] = _min(arr[i][j], arr[i][k] + arr[k][j]);
  
  print_matrix(arr, size, size);
}

void main() {
  int inf = INT_MAX - 100;
  int arr[][4] = {{0, 3, inf, 7},
		  {8, 0, 2, inf},
		  {5, inf, 0, 1},
		  {2, inf, inf, 0}};
  
  int size = sizeof(arr)/sizeof(arr[0]);
  floyd_warshall(arr, size);
}
