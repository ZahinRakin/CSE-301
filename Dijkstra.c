#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define V 9

int Graph[9][9]={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

int* buildSpt(int*);
int minDist(int*,bool*);
void printSpt(int*);

int main(){
    int* parent = malloc(sizeof(int)*V);
    parent = buildSpt(parent);
    printSpt(parent);
    return 0;
}

int* buildSpt(int* p){
    bool sptSet[V];
    int d[V];

    for(int i = 0; i < V; i++){
        d[i] = INT_MAX;
        sptSet[i] = false;
    }

    d[0] = 0;
    p[0] = -1;

    for(int i = 0; i < V-1; i++){
        int u = minDist(d,sptSet);
        sptSet[u] = true;
        for(int v = 0; v < V; v++){
            if(!sptSet[v] &&
            Graph[u][v] &&
            d[u] != INT_MAX &&
            d[u] + Graph[u][v] < d[v]){
                d[v] = d[u] + Graph[u][v];
                p[v] = u;
            }
        }
    }
    return p;
}

int minDist(int* d, bool* sptSet){
    int minValue = INT_MAX;
    int minIndex = -1;
    for(int i = 0; i < V; i++){
        if(!sptSet[i] && minValue > d[i]){
            minValue = d[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void printSpt(int* p){
    printf("vertex\tprev\tdistance from src\n");
    for(int i = 0; i < V; i++){
        printf("%d   -   %d \t%d\n",i,p[i],Graph[i][p[i]]);
    }
}