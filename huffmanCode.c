#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node* left;
  struct node* right;
}Node;

Node* head = NULL;

void buildTree(int*, int);
Node *createNode(int);
void printTree(Node*, int*, int);


int main(){
  int codes[100];
  int arr[] = {4,2,9,8,7,5,6};
  int size = sizeof(arr)/sizeof(*arr);
  buildTree(arr, size);
  printf("Huffman codes:\n");
  printTree(head,codes,0);
  return 0;
}

void buildTree(int* arr, int size){
  Node* arrNode[size];
  for(int i = 0; i < size; i++)
    arrNode[i] = createNode(arr[i]);
  for(int iterator = 0; iterator < size - 1; iterator++){
    for(int i = iterator; i < size - 1; i++)
      for(int j = i+1; j < size; j++)
        if(arrNode[i]->value > arrNode[j]->value){
          Node* temp = arrNode[i];
          arrNode[i] = arrNode[j];
          arrNode[j] = temp;
        }
    Node *newNode = createNode(arrNode[iterator]->value + arrNode[iterator+1]->value);
    newNode->left = arrNode[iterator];
    newNode->right = arrNode[iterator + 1];
    arrNode[iterator + 1] = newNode;
  }
  head = arrNode[size-1];
}

Node *createNode(int value){
  Node* newNode = malloc(sizeof(Node));
  newNode->value = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void printTree(Node* head, int *codes, int top){
  if(head->left){
    codes[top] = 0;
    printTree(head->left, codes, top+1);
  }
  if(head->right){
    codes[top] = 1;
    printTree(head->right, codes, top+1);
  }
  if(!head->left && !head->right){
    printf("number: %d.\tcode: ",head->value);
    for(int i = 0; i < top; i++){
      printf("%d",codes[i]);
    }
    printf("\n");
  }
}


