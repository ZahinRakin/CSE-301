#include <stdio.h>
#include <limits.h>

int maxSubSeq(int*, int);
void print(int*, int*, int);

int main(){
    int arr[] = {9,-3,1,7,-15,2,3,-4,2,-7,6,-2,8,4,-9};
    int size = sizeof(arr)/sizeof(*arr);
    printf("\nMax Sum :%d\n",maxSubSeq(arr, size));
    return 0;
}

int maxSubSeq(int* arr, int len){
    int sum[len];
    int prev[len];
    int maxSum = 0;
    int index;
    int i = -1;
    sum[0] = (arr[0] > 0)?arr[0]:0;
    prev[0] = -1;
    for(int i = 1; i < len; i++){
        sum[i] = sum[i-1] + arr[i];
        prev[i] = i-1;
        if(sum[i] < arr[i]){
            sum[i] = arr[i];
            prev[i] = 0;
        }
        if(maxSum < sum[i]){
            maxSum = sum[i];
            index = i; 
        }
    }
    print(arr, prev, index);
    return maxSum;
}

void print(int* arr, int* prev, int index){
    if(prev[index] >= 0){
        print(arr, prev, prev[index]);
        printf("%d ",arr[index]);
    }
}