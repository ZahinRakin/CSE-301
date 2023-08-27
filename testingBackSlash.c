#include <stdio.h>
#include <string.h>

int* f(int*, int, int*, int*);

int main(){
    int a[] = {8, 3, 1, 5, 2, 6, 4, 2, 6, 9, 2, 3};
    int size = sizeof(a)/sizeof(*a);
    int maxLen, maxIndex;
    int* l = f(a, size, &maxLen, &maxIndex);
    return 0;
}

int* f(int* arr, int n, int* ml, int* mi){
    for(int i = 0; i < n; i++){
        for(int j = )
    }
}