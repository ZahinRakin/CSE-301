#include <stdio.h>
#include <limits.h>

int m[100][100];
int s[100][100];

void fill() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            m[i][j] = INT_MAX;
        }
    }
}

void RMC(int p[], int n) {
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int min = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                if (min < m[i][j]) {
                    m[i][j] = min;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printParenthesis(int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        printParenthesis(i, s[i][j]);
        printParenthesis(s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int p[n + 1];
    printf("Enter all the dimensions: ");
    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);
    fill();
    RMC(p, n);
    printf("Minimum operations needed: %d\n", m[1][n]);
    printParenthesis(1, n);
    printf("\n");
    return 0;
}

