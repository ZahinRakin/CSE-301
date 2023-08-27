#include <stdio.h>

void activitySelector(int*, int*, int, int);

void main(){
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(s) / sizeof(s[0]);

    printf("Selected activities:\n");
    activitySelector(s, f, n, -1);
}

void activitySelector(int* start, int* finish, int n, int i){
  int m = i+1;
  while(m <= n && start[m] < finish[i])
    m++;
  if(m <= n){
    printf("%d \n",m);
    activitySelector(start, finish, n, m);
  }
}
