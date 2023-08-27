#include <stdio.h>
#include <limits.h>

int kodane(int*, int);

void main(){
  int n;
  printf("Enter array size: ");
  scanf("%d",&n);
  getchar();
  int arr[n];// = {-5,-1,5,-3,-1,2,3,-6};
  //int size = sizeof(arr)/sizeof(*arr);
  for(int i = 0; i < n; i++)
    scanf("%d",&arr[i]);
  printf("maximum sum of subarray: %d\n",kodane(arr, n));
}

int kodane(int* arr, int size){
  int maxSum = INT_MIN;
  int currentSum = 0;
  for(int i = 0; i < size; i++){
    if(currentSum < 0 && arr[i] > currentSum)
      currentSum = 0;
    currentSum += arr[i];
    maxSum = currentSum > maxSum ? currentSum : maxSum;
  }
  return maxSum;
}
