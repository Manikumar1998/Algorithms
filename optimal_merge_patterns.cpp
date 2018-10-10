/*

Merge a set of sorted files of different length into
a single sorted file. We need to find an optimal solution,
where the resultant file will be generated in minimum time.

Implementation: Using min Heap

*/


#include<iostream>
using namespace std;

void insert(int);
void swap(int, int);
int pop();
void heapify_down(int);
void print();
void heapify(int);

#define N 10
int arr[N];
int counter = -1;

void insert(int val) {
  arr[++counter] = val;
  heapify(counter);
}

void swap(int i,int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int pop() {
  int temp = arr[0];
  arr[0] = arr[counter];
  counter--;
  heapify_down(0);
  return temp;
}

void heapify_down(int n) {
    if (arr[2*n+1] < arr[2*n+2])
      if (arr[2*n+1] < arr[n]) {
	swap(n, 2*n+1);
	heapify_down(2*n+1);
      }
    else
      if (arr[2*n+2] < arr[n]) {
	swap(n, 2*n+2);
	heapify_down(2*n+2);
      }
}

void print() {
  cout << "\nSize of the root node: ";
  for(int i=0; i<=counter; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

void heapify(int n) {
  if (n == 0)
    return;
  else if (arr[n] < arr[(n-1)/2]) {
    swap(n, (n-1)/2);
    heapify((n-1)/2);
  }
}

int main() {
  int input[] = {20, 30, 10, 5, 30};
  for(int i:input) {
    insert(i);
  }

  int sum = 0;
  while(counter > 0) {
    int a = pop();
    int b = pop();
    sum += (a+b);
    cout << "Adding " << a+b << " (" << a << "+" << b << ") " << "to heap\n";
    insert(a+b);
  }
  cout << "Optimal merge operations: "<< sum;
  print();
}
