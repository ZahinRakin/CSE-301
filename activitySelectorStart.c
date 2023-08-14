#include <stdio.h>
#include <stdlib.h>

// Function to solve the activity selection problem
void activitySelection(int start[], int finish[], int n) {
    printf("Selected activities:\n");
    
    // Select the first activity
    int prevActivity = 0;
    printf("(%d, %d)\n", start[0], finish[0]);
    
    // Iterate over the remaining activities
    for (int i = 1; i < n; i++) {
        if (start[i] >= finish[prevActivity]) {
            printf("(%d, %d)\n", start[i], finish[i]);
            prevActivity = i;
        }
    }
}

int main() {
    int start[] = {1, 0, 1, 4, 2, 5};
    int finish[] = {3, 4, 2, 6, 9, 8};
    int n = sizeof(start) / sizeof(start[0]);
    for(int i = 0; i < n; i++){
      printf("start: %d\tend: %d\n",start[i],finish[i]);
    }
    
    activitySelection(start, finish, n);
    
    return 0;
}

