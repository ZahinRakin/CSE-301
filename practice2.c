#include <stdio.h>
#include <stdlib.h>

int rc(int*, int*, int, int);
int max(int, int);

int main(){
  int length[] = {1,2,3,4,5,6,7};
  int price[] = {1,4,3,5,6,4,6};
  printf("%d\n",rc(length, price, size, 4));
  return 0;
}

int rc(int* l, int* p, int s, int rl){
  int m = 0;
  if(rl > 0)
    m = max(m, price[rl] + rc(l, p, s, rl-1));
  return m;
}

int max(int a, int b){
  return (a>b) ? a : b;
}
