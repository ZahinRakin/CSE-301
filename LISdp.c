#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

void LIS_Fast_DP(int* a, int n, int* L, int* L_prime, int* prev) {
    L[0] = -1; // Sentinel value
    L_prime[0] = -1; // Sentinel value
    prev[0] = -1; // Sentinel value
    
    int L_length = 0;
    
    for (int i = 1; i <= n; i++) {
        if (L[L_length] < a[i]) {
            L[++L_length] = a[i];
            L_prime[L_length] = i;
            prev[i] = L_prime[L_length - 1];
        } else {
            int s = 0, h = L_length;
            
            while (s < h) {
                int m = (s + h) / 2;
                if (L[m] < a[i]) {
                    s = m + 1;
                } else {
                    h = m;
                }
            }
            
            L[s] = a[i];
            L_prime[s] = i;
            prev[i] = L_prime[s - 1];
        }
    }
}

void printLIS(int* a, int* prev, int idx) {
    if (idx == -1) {
        return;
    }
    if (prev[idx] != -1) {
        printLIS(a, prev, prev[idx]);
    }
    printf("%d ", a[idx]);
}


int main() {
    int arr[] = {0, 2, 5, 3, 6, 1, 2, 10, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int L[MAX_LEN];
    int L_prime[MAX_LEN];
    int prev[MAX_LEN];
    
    LIS_Fast_DP(arr, n, L, L_prime, prev);
    
    printf("Longest Increasing Subsequence: ");
    printLIS(arr, prev, L_prime[n]);
    printf("\n");
    
    return 0;
}
