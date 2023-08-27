#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

typedef struct{
    int L[MAX_LEN];
    int L_prime[MAX_LEN];
    int prev[MAX_LEN];
}block;

block* LIS(block*, int*, int);
void print(int*, int*, int);
int binarySearch(int*, int, int, int);

int main(){
    int arr[] = {2,5,3,6,1,2,10,7,9};
    int size = sizeof(arr)/sizeof(*arr);
    block* b = LIS(b, arr, size);
    
    for(int i = 0; i < size; i++){
        printf("L: %d L_prime: %d prev: %d\n",b->L[i],b->L_prime[i],b->prev[i]);
    }
    print(arr, b->prev, b->L_prime[size-1]);
    printf("\n");
    return 0;
}

block* LIS(block* b, int* a, int l){
    b = (block*)malloc(sizeof(block));
    int j = 0;
    b->L[0] = a[0];
    b->L_prime[0] = -1;
    b->prev[0] = -1;
    for(int i = 1; i < l; i++){
        if(a[i] > b->L[j]){
            b->L[++j] = a[i];
            b->L_prime[j] = i;
            b->prev[j] = b->L_prime[j-1];
        }
        else{
            int s = binarySearch(b->L, 0, j, a[i]);
            b->L[s] = a[i];
            b->L_prime[s] = i;
            b->prev[i] = b->L_prime[s-1];
        }
    }
    return b;
}

int binarySearch(int* arr, int s, int e, int k){
    if(s <= e){
        int mid = (s + e) / 2;
        if(arr[mid] == k || (arr[mid] > k && arr[mid-1] < k))
            return mid;
        else if(arr[mid] < k)
            return binarySearch(arr, mid + 1, e, k);
        else
            return binarySearch(arr, s, mid, k);
    }
    return s;
}


void print(int* a, int* prev, int i){
    if(i == -1)
        return;
    print(a,prev,prev[i]);
    printf("%d ",a[i]);
}
