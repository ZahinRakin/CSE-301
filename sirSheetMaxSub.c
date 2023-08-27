#include <stdio.h>
#include <limits.h>

void sumonSir(int*, int);

void main(){
  int n;
  printf("Enter array size: ");
  scanf("%d",&n);
  getchar();
  int arr[n];
  for(int i = 0; i < n; i++)
    scanf("%d",&arr[i]);
  sumonSir(arr,n);
}

void sumonSir(int* arr, int size){
  int sum[size];
  int prev[size];
  sum[0] = arr[0];
  for(int i = 1; i < size; i++){
    sum[i] = sum[i-1] + arr[i];
    prev[i] = i-1;
    if(sum[i] < arr[i]){
      sum[i] = arr[i];
      prev[i] = 0;
    }
  }
  printf("sum     prev\n");
  for(int i = 0; i < size; i++){
    printf("%d\t%d\n",sum[i],prev[i]);
  }
}
