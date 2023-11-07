#include <stdio.h>
#include <stdlib.h>

//kruskal's algorithm is typically used to find the MST of undirected graph.

#define max 30

typedef struct {
    int s,d,w;
} Edge;

typedef struct {
    int P;
    int r;
} Subset;

int V,E;

Edge* initEdges(Edge*);
Subset* Union(Subset* , int, int);
int find(Subset* , int);
void kruskal(Subset* , Edge* , Edge[]);
Edge* sort(Edge*, int, int);


int main(){
    Edge* edges;
    edges = initEdges(edges);
    printf("edges: \n");
    for(int i = 0; i < E; i++){
        printf("%d -- %d = %d\n", edges[i].s, edges[i].d, edges[i].w);
    }
    printf("initEdges worked\n");
    //let's create a set for every vertex on the graph;
    Subset subsets[V];
    for(int i = 0; i < V; i++){
        subsets[i].P = i;
        subsets[i].r = 0;
    }
    printf("let's see if kruskal works or not?\n");
    Edge MST[V-1];
    kruskal(subsets,edges,MST);
    for(int i = 0; i < V-1; i++){
        printf("%d -> %d = %d\n",MST[i].s,MST[i].d,MST[i].w);
    }
    printf("Kruskal worked fine!\n");
    return 0;
}

Edge* initEdges(Edge* edges){
    E = 14;
    edges = (Edge*)malloc(sizeof(Edge)*E);

    V = 9;

    edges[0].s = 0;
    edges[0].d = 1;
    edges[0].w = 4;//au -> authentic -> double checked
    
    edges[1].s = 0;
    edges[1].d = 7;
    edges[1].w = 8;//au

    edges[2].s = 1;
    edges[2].d = 2;
    edges[2].w = 8;///au

    edges[3].s = 1;
    edges[3].d = 7;
    edges[3].w = 11;////au
    
    edges[4].s = 2;
    edges[4].d = 3;
    edges[4].w = 8;/////au

    edges[5].s = 2;
    edges[5].d = 5;
    edges[5].w = 4;//////au

    edges[6].s = 2;
    edges[6].d = 8;
    edges[6].w = 2;///////au

    edges[7].s = 3;
    edges[7].d = 4;
    edges[7].w = 9;////////au

    edges[8].s = 3;
    edges[8].d = 5;
    edges[8].w = 14;///au

    edges[9].s = 4;
    edges[9].d = 5;
    edges[9].w = 10;////au
    
    edges[10].s = 5;
    edges[10].d = 6;
    edges[10].w = 2;/////au

    edges[11].s = 6;
    edges[11].d = 8;
    edges[11].w = 6;//////au

    edges[12].s = 6;
    edges[12].d = 7;
    edges[12].w = 1;///////au

    edges[13].s = 7;
    edges[13].d = 8;
    edges[13].w = 7;////////au

    return edges;
}

void kruskal(Subset* subsets, Edge* edges, Edge MST[]){
    printf("let's see if sort works or not:\n");
    edges = sort(edges,0,E-1);
    for(int i = 0; i < E; i++){
        printf("%d -- %d = %d\n",edges[i].s, edges[i].d, edges[i].w);
    }
    printf("sort worked fine!\n");


    int j = 0;
    int numOfEdge = 0;

    while(numOfEdge < V-1){
        int x = find(subsets,edges[j].s);
        int y = find(subsets, edges[j].d);
        if(x != y){
            subsets = Union(subsets,x,y);
            MST[numOfEdge] = edges[j];
            numOfEdge++;
        }
        j++;
    }
    // printf("checking whether the subsets got loaded or not:\n");
}

Edge* sort(Edge* edges, int s, int e){
    if(s<e){
        int i = s;
        int j = e;
        int p = s;
        Edge temp;

        while(i < j){
            while(edges[i].w <= edges[p].w){
                i++;
            }
            while(edges[j].w > edges[p].w){
                j--;
            }
            if(i < j){
                temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }

        temp = edges[j];
        edges[j] = edges[p];
        edges[p] = temp;

        edges = sort(edges,s,j-1);
        edges = sort(edges,j+1,e);//here instead of j i used p. actuallly the original position of p is j. that's why here j is used instead of p. because p's index is sttill the first position.
    }
    return edges;
}

Subset* Union(Subset* subsets, int x, int y){
    int rootx = find(subsets, x);
    int rooty = find(subsets,y);
    if(subsets[rootx].r > subsets[rooty].r){
        subsets[rooty].P = rootx;
    }else if(subsets[rootx].r < subsets[rooty].r){
        subsets[rootx].P = rooty;
    }else{
        subsets[rooty].P = rootx;
        subsets[rootx].r++;
    }
    return subsets;
}

int find(Subset* subsets, int i){
    while(i != subsets[i].P){
        i = subsets[i].P;
    }
    return i;

    // if (subsets[i].P == i) 
    //     return subsets[i].P; 
    // subsets[i].P = find(subsets, subsets[i].P); 
    // return subsets[i].P; 
}