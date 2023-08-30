#include<stdio.h>
#define MAX_INDEX 100

int fib( int);

int main(){
	int n;
	printf("Enter a number:");
	scanf("%d",&n);
	getchar();
	printf("fibonacci number: %d\n",fib(n));
	return 0;
}

int fib(int n){
	if(n<=1)
		return n;
	else{
		return fib(n-1)+fib(n-2);
	}
}
