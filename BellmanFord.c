#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct{
    int src,dest,weight;
} Edge;

int V,E;

void initEdges(Edge[]);
int* bellmanFord(Edge[],int*);

int main(){
    V = 5;
    E = 8;
    Edge edges[E];
    initEdges(edges);
    int *parent = malloc(sizeof(int)*V);

    parent = bellmanFord(edges,parent);

    return 0;
}

void initEdges(Edge edges[]){
    // add edge 0-1 (or A-B in above figure)
    edges[0].src = 0;
    edges[0].dest = 1;
    edges[0].weight = -1;

    // add edge 0-2 (or A-C in above figure)
    edges[1].src = 0;
    edges[1].dest = 2;
    edges[1].weight = 4;

    // add edge 1-2 (or B-C in above figure)
    edges[2].src = 1;
    edges[2].dest = 2;
    edges[2].weight = 3;

    // add edge 1-3 (or B-D in above figure)
    edges[3].src = 1;
    edges[3].dest = 3;
    edges[3].weight = 2;

    // add edge 1-4 (or B-E in above figure)
    edges[4].src = 1;
    edges[4].dest = 4;
    edges[4].weight = 2;

    // add edge 3-2 (or D-C in above figure)
    edges[5].src = 3;
    edges[5].dest = 2;
    edges[5].weight = 5;

    // add edge 3-1 (or D-B in above figure)
    edges[6].src = 3;
    edges[6].dest = 1;
    edges[6].weight = 1;

    // add edge 4-3 (or E-D in above figure)
    edges[7].src = 4;
    edges[7].dest = 3;
    edges[7].weight = -3;
}

int* bellmanFord(Edge edges[], int* p){
    int d[V];
    for(int i = 0; i < V; i++){
        d[i] = INT_MAX;
    }
    p[0] = -1;
    d[0] = 0;
    for(int i = 1; i < V; i++){
        for(int j = 0; j < E; j++){
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;
            if(d[u] != INT_MAX && d[u] + w < d[v]){
                d[v] = d[u] + w;
                p[v] = u;
            }
        }
    }
    //one more time relaxation for determining the negative cycle.
    for(int i = 0; i < E; i++){
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;
        if(d[u] != INT_MAX && d[u] + w < d[v]){
            printf("negative cycle exists\n\n");
            exit(0);
        }
    }
    printf("Vertex     distance from src\n");
    for(int i = 0; i < V; i++){
        printf("%d\t\t%d\n",i,d[i]);
    }
    return p;
}

