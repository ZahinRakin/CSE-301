#include <stdio.h>

int comb(int, int);

int main(){
    int number;
    int r;
    printf("Combination\n");
    printf("Enter total number: ");
    scanf("%d", &number);
    getchar();
    printf("Enter element number: ");
    scanf("%d", &r);
    getchar();
    printf("combinations: %d\n", comb(number, r));
    return 0;
}

int comb(int n, int r){
    if (r == n || r == 0)
        return 1;
    if (r == 1)
        return n;
    else
        return comb(n - 1, r - 1) + comb(n - 1, r);
}
