#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define V 5
#define NIL INT_MIN
#define INF INT_MAX

int w[5][5]={{0,3,8,INF,-4},
            { INF,0,INF,1,7},
            { INF,4,0,INF,INF},
            { 2,INF,-5,0,INF},
            { INF,INF,INF,6,0}};

void PrintPath(int**, int, int);
void floyedWarshal();
int add(int, int);

int main(){
    printf("The graph is from sir's slide:\n\n");
    floyedWarshal();
    return 0;
}

void floyedWarshal(){
    int **p, **d;
    p = (int**)malloc(sizeof(int*)*V);
    d = (int**)malloc(sizeof(int*)*V);
    for(int i = 0; i < V; i++){
        p[i] = (int*)malloc(sizeof(int)*V);
        d[i] = (int*)malloc(sizeof(int)*V);
    }
    //let's initialize the p and d
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            d[i][j] = w[i][j];
            if(i == j || w[i][j] == INF){
                p[i][j] = NIL;
            }else if(i != j && w[i][j] != INF){
                p[i][j] = i;
            }
        }
    }    

    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(d[i][j] > add(d[i][k],d[k][j])){
                    d[i][j] = add(d[i][k],d[k][j]);
                    p[i][j] = p[k][j];
                }
            }
        }
    }
    printf("\ndistance from each pair of vertices:\n");
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(d[i][j] == INF){
                printf("I ");
            }else{
                printf("%d ",d[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nthe parent matrix:\n");

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(p[i][j] == NIL){
                printf("NIL ");
            }else{
                printf("%d ",p[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");

    printf("\n");
    printf("Distance between 2 to 0:\n");
    PrintPath(p,2,0);
    printf(" 0");
    printf("\n\n");
}

void PrintPath(int** p, int s, int d){
    if(p[s][d] == NIL){
        printf("No path!\n\n");
        return;
    }else if(p[s][d] == s){
        printf(" %d -",s);
    }else{
        PrintPath(p,s,p[s][d]);
        PrintPath(p,p[s][d],d);
    }
}

int add(int a, int b){
    if(a == INF || b == INF){
        return INF;
    }else{
        return a+b;
    }
}