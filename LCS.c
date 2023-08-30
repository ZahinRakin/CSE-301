#include <stdio.h>
#include <string.h>

char b[100][100];
int c[100][100];
char str1[] = "rakin";
char str2[] = "rakib";

int lcs(char*, char*, int, int);
void print(int, int);

int main(){
    
    
    int size1 = strlen(str1);
    int size2 = strlen(str2);
    lcs(str1,str2,size1,size2);
    return 0;
}

int lcs(char* str1, char* str2, int s1, int s2){
    for(int i = 0; i <= s1; i++){
        for(int j = 0; j <= s2; j++){
            if(i == 0 || j == 0){
                c[i][j] = 0;
                b[i][j] = ' ';
            }
            else if(str1[i-1] == str2[j-1]){
                c[i][j] = 1+c[i-1][j-1];
                b[i][j] = '\\';
            }
            else if(str1[i-1] != str2[j-1]){
                if(c[i-1][j] >= c[i][j-1]){
                    c[i][j] = c[i-1][j];
                    b[i][j] = '|';
                }
                else{
                    c[i][j] = c[i][j-1];
                    b[i][j] = '-';
                }
            }
        }
    }
    for(int i = 0; i <= s1; i++){
        for(int j = 0; j <= s2; j++){
            printf("%c%d ",b[i][j],c[i][j]);
        }
        printf("\n");
    }
    print(s1,s2);
    printf("\n");
}

void print(int i, int j){
    if(i == 0 || j == 0)
        return;
    if(b[i][j] == '\\'){
        print(i-1, j-1);
        printf("%c", str2[j-1]);
    }
    else if(b[i][j] == '|'){
        print(i-1, j);
    }
    else{
        print(i, j-1);
    }
}

