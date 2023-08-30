#include <stdio.h>
#include <stdlib.h>

void printLIS(int arr[], int prev[], int index)
{
    if (index == -1)
        return;
    printLIS(arr, prev, prev[index]);
    printf("%d ", arr[index]);
}

int* findLongestIncreasingSubsequence(int* a, int n, int* maxLength, int* maxIndex) {
    int* L = (int*)malloc(n * sizeof(int));
    int* prev = (int*)malloc(n * sizeof(int));
    
    L[0] = 1;
    prev[0] = -1;
    
    *maxLength = 1;
    *maxIndex = 0;
    
    for (int i = 1; i < n; i++) {
        L[i] = 1;
        prev[i] = -1;
        
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && L[j] + 1 > L[i]) {
                L[i] = L[j] + 1;
                prev[i] = j;
            }
        }
        
        if (L[i] > *maxLength) {
            *maxLength = L[i];
            *maxIndex = i;
        }
    }
    
    return L;
}

int main() {
    int a[] = {8, 3, 1, 5, 2, 6, 4, 2, 6, 9, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);
    
    int maxLength, maxIndex;
    int* L = findLongestIncreasingSubsequence(a, n, &maxLength, &maxIndex);
    
    printf("Longest Increasing Subsequence Length: %d\n", maxLength);
    printf("Max Index: %d\n", maxIndex);
    free(L);

    return 0;
}
