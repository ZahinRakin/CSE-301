#include<stdio.h>
#include<limits.h>
#define MAX_INDEX 100

int fib(int*, int);

int main(){
	int F[MAX_INDEX];
	int n;
	printf("Enter a number:");
	scanf("%d",&n);
	for(int i = 0; i <= n; i++){
		F[i] = INT_MIN;
	}
	printf("fibonacci number: %d\n",fib(F,n));
	return 0;
}

int fib(int* F, int n){
	if(F[n] >= 0)
		return F[n];
	if(n<=1){
		F[n] = n;
	}
	else{
		F[n] = fib(F, n-1)+fib(F, n-2);
	}
	return F[n];
}
