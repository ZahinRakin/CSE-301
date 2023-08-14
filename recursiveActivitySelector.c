#include <stdio.h>

void recursiveActivitySelector(int s[], int f[], int n, int i) {
    int m = i + 1;

    while (m <= n && s[m] < f[i]) {
        m = m + 1;
    }

    if (m <= n) {
        printf("%d \n", m); // Print the selected activity index (am)
        recursiveActivitySelector(s, f, n, m); // Recursively solve the subproblem Si+1,n
    }
}

int main() {
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(s) / sizeof(s[0]);

    printf("Selected activities:\n");
    recursiveActivitySelector(s, f, n, -1); // Start with i = -1 for the base case

    return 0;
}

