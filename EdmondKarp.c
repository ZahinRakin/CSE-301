//edmond karps algorithm.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define V 6

typedef struct node{
    int value;
    struct node* next;
}Node;

typedef struct queue{
    Node* head;
    Node* tail;
}Queue;

Queue* initQueue(Queue*);
void enqueue(Queue*, int);
int dequeue(Queue*);
bool BFS(int [][V], int, int, int[]);
int fordFulkerson(int[][V],int,int);

int main(){
    
    int graph[V][V] = {
            { 0, 16, 13, 0, 0, 0 },
            { 0, 0, 10, 12, 0, 0 },
            { 0, 4, 0, 0, 14, 0 },
            { 0, 0, 9, 0, 0, 20 },
            { 0, 0, 0, 7, 0, 4 },
            { 0, 0, 0, 0, 0, 0 }
        };
    printf("MaxFlow = %d\n\n",fordFulkerson(graph, 0, 5));
    return 0;
}

Queue* initQueue(Queue* q){
    q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue(Queue* q, int v){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = v;
    newNode->next = NULL;
    if(q->head == NULL){
        q->head = newNode;
        q->tail = newNode;
    }else{
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

int dequeue(Queue* q){
    Node* temp;
    if(q->head){
        temp = q->head;
        q->head = q->head->next;
        if(!q->head){
            q->tail = NULL;
        }
    }
    int value = temp->value;
    free(temp);
    return value;
}

bool BFS(int rGraph[][V],int s, int e, int parent[]){
    Queue* q = initQueue(q);
    bool visited[V];
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }

    visited[s] = true;// i made mistake here. i thought that this will be placed inside while loop. for some reason that made sense and seemed familiar.
    parent[s] = -1;

    enqueue(q,s);
    while(q->head){
        s = dequeue(q);
        for(int v = 0; v < V; v++){
            if(rGraph[s][v] && !visited[v]){//rGraph = residual graph.
                if(v == e){
                    parent[v] = s;
                    return true;
                }
                visited[v] = true;
                enqueue(q,v);
                parent[v] = s;
            }
        }
    }

    return false;
}

int fordFulkerson(int Graph[][V], int s, int t){
    int parent[V];
    parent[s] = -1;

    int maxFlow = 0;

    int rGraph[V][V];
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            rGraph[i][j] = Graph[i][j];
        }
    }

    while(BFS(rGraph,s,t,parent)){
        int pathFlow = INT_MAX;
        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            pathFlow = (pathFlow < rGraph[u][v]) ? pathFlow : rGraph[u][v];
        }
        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}