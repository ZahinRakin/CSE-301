#include <stdio.h>
#include <stdlib.h>

struct node {
    int i;
    struct node* left;
    struct node* right;
};

struct node* createNode(int);
void buildHuffmanTree(struct node**, int);
void printHuffmanCodes(struct node*, int[], int);
void freeHuffmanTree(struct node*);

struct node* head = NULL;

int main() {
    int arr[] = {3, 34, 2, 5, 23, 54, 36, 10};
    int size = sizeof(arr) / sizeof(*arr);
    struct node* arrNode[size];

    for (int i = 0; i < size; i++) {
        arrNode[i] = createNode(arr[i]);
    }

    buildHuffmanTree(arrNode, size);

    int codes[100];
    printHuffmanCodes(head, codes, 0);

    freeHuffmanTree(head);

    return 0;
}

void buildHuffmanTree(struct node** arrNode, int size) {
    int iterator = 0;
    while (iterator < size - 1) {
        for (int i = iterator; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (arrNode[i]->i > arrNode[j]->i) {
                    struct node* temp = arrNode[i];
                    arrNode[i] = arrNode[j];
                    arrNode[j] = temp;
                }
            }
        }
        struct node* newNode = createNode(arrNode[iterator]->i + arrNode[iterator + 1]->i);
        newNode->left = arrNode[iterator];
        newNode->right = arrNode[iterator + 1];
        arrNode[iterator+1] = newNode;
        iterator++;
    }
    head = arrNode[size-1]; // Move this line outside the loop
}


void printHuffmanCodes(struct node* root, int codes[], int top) {
    if (root->left) {
        codes[top] = 0;
        printHuffmanCodes(root->left, codes, top + 1);
    }
    if (root->right) {
        codes[top] = 1;
        printHuffmanCodes(root->right, codes, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        printf("Value: %d, Huffman Code: ", root->i);
        for (int i = 0; i < top; i++) {
            printf("%d", codes[i]);
        }
        printf("\n");
    }
}

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode != NULL) {
        newNode->i = value;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

void freeHuffmanTree(struct node* root) {
    if (root) {
        freeHuffmanTree(root->left);
        freeHuffmanTree(root->right);
        free(root);
    }
}

