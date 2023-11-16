#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack_01(int weights[], int values[], int n, int capacity) {
    int P[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                P[i][w] = 0;
            else if (weights[i - 1] > w)
                P[i][w] = P[i - 1][w];//this is for the first part. when upto some weight value i need to put the previous value.
            else
                P[i][w] = max(values[i - 1] + P[i - 1][w - weights[i - 1]], P[i - 1][w]);
        }
    }

    return P[n][capacity];
}

int main() {
    int capacity, n;
    //printf("Enter knapsack capacity: ");
    freopen("snck.txt","r",stdin);
    scanf("%d", &capacity);
    //printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];
    //printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
   // printf("Enter values of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    int max_value = knapsack_01(weights, values, n, capacity);
    printf("Maximum value: %d\n", max_value);

    return 0;
}
