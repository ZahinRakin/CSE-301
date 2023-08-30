#include <stdio.h>
#include <stdlib.h>

void activitySelectionByStartingTime(int*, int*, int);

int main(){
  int s[] = {7,6,10,13,17};
  int f[] = {9,8,11,17,20};//finishing time must be sorted in ascending order
  printf("Start Time Finishing Time\n");
  int n = sizeof(s)/sizeof(*s);
  for(int i = 0; i < n; i++){
    printf("%d\t   %d\n",s[i],f[i]);
  }
  printf("Schedule for the programs:\n");
  activitySelectionByStartingTime(s,f,n);
  return 0;
}

void activitySelectionByStartingTime(int* start, int* finish, int size){
  int prevAct = 0;
  printf("%d\t%d\n",start[prevAct],finish[prevAct]);
  for(int i = 1; i < size; i++){
    if(start[i] >= finish[prevAct]){
      printf("%d\t%d\n",start[i],finish[i]);
      prevAct = i;
    }
  }
}
