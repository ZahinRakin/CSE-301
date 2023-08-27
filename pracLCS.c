#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100

typedef struct {
    int c[MAX_LENGTH][MAX_LENGTH];
    char b[MAX_LENGTH][MAX_LENGTH];
}lcs;

lcs* LCS(lcs*, char*, char*, int, int);
void print(lcs*,char* ,int, int);

void main(){
    char str1[] = "hellco";
    char str2[] = "ahbellco";
    lcs* output = malloc(sizeof(lcs));
    output = LCS(output, str1, str2, strlen(str1), strlen(str2));
    printf("Longest subsequence: ");
    print(output, str1, strlen(str1), strlen(str2));
    printf("\n");
}

lcs* LCS(lcs* ot, char* s1, char* s2, int l1, int l2){
    for(int i = 0; i <= l1; i++){
        for(int j = 0; j <= l2; j++){
            if(i == 0 || j == 0){
                ot->c[i][j] = 0;
                ot->b[i][j] = ' ';
            }
            else if(s1[i-1] == s2[j-1]){
                ot->c[i][j] = 1+ot->c[i-1][j-1];
                ot->b[i][j] = '\\';
            }
            else {
                if(ot->c[i-1][j] >= ot->c[i][j-1]){
                    ot->c[i][j] = ot->c[i-1][j];
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
            printf("%c%d ",ot->b[i][j],ot->c[i][j]);
        }
        printf("\n");
    }
    return ot;
}

void print(lcs* ot, char* s, int l1, int l2){
    if(l1 == 0 || l2 == 0)
        return;
    if(ot->b[l1][l2] == '\\'){
        print(ot, s, l1-1, l2-1);
        printf("%c",s[l1-1]);
    }
    else if(ot->b[l1][l2] == '|'){
        print(ot, s, l1-1, l2);
    }
    else {
        print(ot, s, l1, l2-1);
    }
}