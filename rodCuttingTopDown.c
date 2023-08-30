#include<stdio.h>
#include<limits.h>

int cutRod(int*, int);

int main(){
	int p[] = {1,3,4,5,4,6,5};
	printf("Maximum profit: %d\n",cutRod(p,n));
	return 0;
}

int cutRod(int* p, int n){
	int q = INT_MIN;
	if(n==0)
		return n;
	for(int i = 1; i <= n; i++){
		q = max(q, cutRod(p,n-i)+p[i]);
	}
	return q;
}
