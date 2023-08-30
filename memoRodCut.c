#include<stdio.h>
#include<limits.h>
#define max 100

int cutRod(int*, int*, int);
int max(int a, int b);

int main(){
	int r[max];
	int p[] = {1,3,4,5,4,6,5};
	int size = sizeof(p)/sizeof(*p);
	for(int i = 0; i <= p; i++){
		r[i] = INT_MIN;
	}
	printf("Maximum profit: %d\n",cutRod(p,r,n));
	return 0;
}

int cutRod(int* p, int* r, int n){
	if(r[n] >= 0){
		return r[n];
	}
	if(n == 0)
		q = 0;
	else 
		q = INT_MIN;
	for(int i = 1; i<=n; i++){
		q = max(q, p[i] + cutRod(p,r,n-i));
	}
	r[n] = q;
	return q;
}

int max(int a, int b){
	return (a>b)?a:b;
}
