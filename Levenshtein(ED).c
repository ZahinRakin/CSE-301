#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct{ 
    int c[MAX_LEN][MAX_LEN];
    char b[MAX_LEN][MAX_LEN];
}bc;

bc* ed(bc*, char*, char*, int, int);
void print(bc*, char*, char*, int, int);

int main(){
    char str1[MAX_LEN];
    char str2[MAX_LEN];
    bc* output = NULL;
    printf("String you want to convert: ");
    scanf("%s",str1);
    getchar();
    printf("String to what you want to convert to: ");
    scanf("%s",str2);
    getchar();
    output = ed(output, str1, str2, strlen(str1), strlen(str2));
    print(output, str1, str2, strlen(str1), strlen(str2));
    return 0;
}

bc* ed(bc* ot, char* s1, char* s2, int l1, int l2){
    ot = (bc*)malloc(sizeof(bc));
    if(ot == NULL)
        return NULL;
    for(int i = 0; i <= l1; i++){
        for(int j = 0; j <= l2; j++){
            if(i == 0 || j == 0){
                ot->c[i][j] = (i>j) ? i:j;
                ot->b[i][j] = '-';
            }
            else if(s1[i-1] == s2[j-1]){
                ot->c[i][j] = ot->c[i-1][j-1];
                ot->b[i][j] = '*';
            }
            else{
                if(ot->c[i-1][j-1] <= ot->c[i-1][j] && ot->c[i-1][j-1] <= ot->c[i][j-1]){
                    ot->c[i][j] = 1+ot->c[i-1][j-1];
                    ot->b[i][j] = '\\';
                }
                else if(ot->c[i-1][j] <= ot->c[i-1][j-1] && ot->c[i-1][j] <= ot->c[i][j-1]){
                    ot->c[i][j] = 1+ot->c[i-1][j];
                    ot->b[i][j] = '|';
                }
                else{
                    ot->c[i][j] = ot->c[i][j-1];
                    ot->b[i][j] = '-';
                }
            }
        }
    }
    for(int i = 0; i <= l1; i++){
        for(int j = 0; j <= l2; j++){
            printf("%c%d",ot->b[i][j], ot->c[i][j]);
        }
        printf("\n");
    }
    return ot;
}

void print(bc* ot, char* s, char* s2, int l1, int l2){
    if( l1 == 0 && l2 == 0)
        return;
    else if(ot->b[l1][l2] == '\\'){
        print(ot, s, s2, l1-1, l2-1);
        printf("substitute: %c with: %c\n",s[l1-1], s2[l2-1]);
    }
    else if(ot->b[l1][l2] == '-'){
        print(ot, s, s2, l1, l2-1);
        printf("insert: %c index: %d\n",s2[l2-1], l1);
    }
    else if(ot->b[l1][l2] == '|'){
        print(ot, s, s2, l1-1, l2);
        printf("delete: %c\n",s[l1-1]);
    }
    else{
        print(ot, s, s2, l1-1, l2-1);
        printf("keep: %c\n",s[l1-1]);
    }
}