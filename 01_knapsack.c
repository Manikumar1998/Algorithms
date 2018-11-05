#include<stdio.h>
#include<stdlib.h>

struct Result {
  int* results;
  int size;
  int profit;
};

typedef struct Result Result;

int max(int a, int b) {
  return (a > b)?a:b;
}

void print_matrix(int** arr, int m, int n) {
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}


void backtrack(int** memoization, int m, int n, int W[], Result* res) {
  int i = m - 1;
  int j = n - 1;
  int capacity = n - 1;

  int sum = 0;
  int result[m];
  int counter = 0;

  while(sum < capacity) {
    if (memoization[i][j] != memoization[i-1][j]) {
      sum += W[i - 1];
      j -= W[i - 1];
      result[counter++] = W[i - 1];
    }
    i--;
  }

  res -> results = (int*)malloc(counter*sizeof(int));
  for(int k=0; k<counter; k++)
    res -> results[k] = result[k];
  res -> size = counter;
}

Result compute_knapsack(int n, int capacity, int P[], int W[]) {
  int n_rows = n + 1;
  int n_cols = capacity + 1;
  
  int** memoization = (int**)malloc((n_rows)*sizeof(int*));
  for (int i=0; i<=n; i++)
    memoization[i] = (int*)malloc((n_cols)*sizeof(int));

  for (int i=0; i<n_rows; i++)
    memoization[i][0] = 0;

  for (int j=0; j<n_cols; j++)
    memoization[0][j] = 0;
    
  for (int i=1; i<n_rows; i++)
    for (int j=1; j<n_cols; j++) {
      if (W[i-1] > j)
	memoization[i][j] = memoization[i-1][j];

      else
	memoization[i][j] = max(memoization[i-1][j], P[i-1] + memoization[i-1][j - W[i-1]]);
    }

  Result res;
  res.profit = memoization[n_rows - 1][n_cols - 1];

  printf("\n\nMemoization matrix \n------------------\n");
  print_matrix(memoization, n_rows, n_cols);
  backtrack(memoization, n_rows, n_cols, W, &res);

  for(int i=0; i<n_rows; i++)
    free(memoization[i]);
  free(memoization);
  
  return res;
}

void main() {
  int n = 4;
  int capacity = 8;

  int P[] = {1, 2, 5, 6};
  int W[] = {2, 3, 4, 5};

  printf("Weights: ");
  for(int i=0; i<n; i++)
    printf("%d ", W[i]);
  
  printf("\nProfits: ");
  for(int i=0; i<n; i++)
    printf("%d ", P[i]);

  Result result = compute_knapsack(n, capacity, P, W);
  printf("\nTotal Profit: %d", result.profit);

  printf("\nThe Weights to add are: ");
  for (int i=0; i<result.size; i++) {
    printf("%d ", result.results[i]);
  }
}
