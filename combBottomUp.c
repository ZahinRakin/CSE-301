#include <stdio.h>

int comb(int, int);
int min(int, int);

int main()
{
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

int comb(int n, int r) 
{
    int arr[n+1][r+1];
    for (int i = 0; i < n+1; i++)
        for (int j = 0; j < r+1; j++)
            arr[i][j] = -1;

    for (int i = 0; i < n+1; i++)
    {
        for(int j = 0; j <= min(i,r); j++)
        {
            if (j == 1)
            {
                arr[i][j] = i;
            }
            else if (j == 0 || j == i)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
    }
    return arr[n][r];
}

int min(int a, int b)
{
    return (a<b)?a:b;
}