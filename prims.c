#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define V 9
#define INFINITY INT_MAX


int Graph[9][9] = {
    { 0, 4, 0,0,0,0,0,0,8,0},
    { 4,0,8,0,0,0,0,11,0},
    { 0,8,0,7,0,4,0,0,2},
    { 0,0,7,0,9,14,0,0,0},
    { 0,0,0,9,0,10,0,0,0},
    {0,0,4,14,10,0,2,0,0},
    {0,0,0,0,0,2,0,1,6},
    {8,11,0,0,0,0,1,0,7},
    {0,0,2,0,0,0,6,7,0} 
};

int* buildMst(int*);
int minKey(int*,bool*);
void printMst(int*);

int main(){
    int* parent = malloc(sizeof(int)*V);
    parent = buildMst(parent);
    printMst(parent);
    return 0;
}

int* buildMst(int* p){
    bool mstSet[V];
    int key[V];

    //now let's initialize these bad boys.
    for(int i = 0; i < V; i++){
        mstSet[i] = false;
        key[i] = INFINITY;
    }

    p[0] = -1;
    key[0] = 0;

    for(int noOfEdges = 0; noOfEdges < V-1; noOfEdges++){
        int u = minKey(key,mstSet);
        mstSet[u] = true;
        for(int v = 0; v < V; v++){
            if (Graph[u][v]&&
                !mstSet[v]&&
                Graph[u][v] < key[v]){
                    key[v] = Graph[u][v];
                    p[v] = u;
                }
        }
    }

    return p;
}

int minKey(int* key, bool* mstSet){
    int minValue = INFINITY;
    int minIndex;
    for(int i = 0; i < V; i++){
        if(!mstSet[i] && minValue > key[i]){
            minValue = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void printMst(int* parent){
    printf("Edges \tweight\n");
    for(int i = 1; i < V; i++){
        printf("%d - %d \t%d\n",parent[i],i,Graph[i][parent[i]]);
    }
}