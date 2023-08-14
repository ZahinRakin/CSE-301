#include <stdio.h>
#include <stdlib.h>

void activitySelectionByLength(int*, int*, int*, int);

int main(){
  int start[] = {1, 0, 1, 4, 2, 5};
  int finish[] = {3, 4, 2, 6, 9, 8};
  int length[] = {2, 4, 1, 2, 7, 3};
  int n = sizeof(start) / sizeof(start[0]);
  activitySelectionByLength(start, finish, length, n);
  return 0;
}

void activitySelectionByLength(int* start, int* finish, int* length, int size){
  int indices[size];
  for(int i = 0; i < size; i++)
    indices[i] = i;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (length[indices[j]] < length[indices[j + 1]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
    
    printf("Selected activities:\n");
    
    int prevActivity = 0;
    printf("(%d, %d)\n", start[indices[prevActivity]], finish[indices[prevActivity]]);
    
    for (int i = 1; i < size; i++) {
        if (start[indices[i]] >= finish[indices[prevActivity]]) {
            printf("(%d, %d)\n", start[indices[i]], finish[indices[i]]);
            prevActivity = i;
        }
    }
}
