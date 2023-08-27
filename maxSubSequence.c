#include <stdio.h>
#include <limits.h>

int maxSubSeq(int*, int);
void print(int*, int*, int);

int main(){
    int arr[] = {2,-5,9,-3,1,7,-15,2,3};
    int size = sizeof(arr)/sizeof(*arr);
    printf("\nMax Sum :%d\n",maxSubSeq(arr, size));
    return 0;
}

int maxSubSeq(int* arr, int len){
    int sum[len];
    int prev[len];
    sum[0] = (arr[0]>0)?arr[0]:0;
    int maxSum = 0;
    int index = -1;
    for(int i = 0; i < len; i++){
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
    for(int i = 0; i < len; i++){
        printf("sum[i]:%d prev[i]:%d\n",sum[i],prev[i]);
    }
    print(arr, prev,index);
     return maxSum;
}

void print(int* arr, int* prev, int i){
    if(prev[i] >= 0){
        print(arr, prev, prev[i]);
        printf("%d ",arr[i]);
    }
}