#include <stdio.h>
#include <string.h>

void KMP(char[], char[]);
void computeLpsArray(char[],  int, char[]);

int main(){
    char txt[100] = "ABABDABACDABABCABAB";
    char pat[100] = "ABABCABAB";
    KMP(txt,pat);
    return 0;
}

void KMP(char txt[], char pat[]){
    int M = strlen(pat);
    int N = strlen(txt);
    char lps[M];

    computeLpsArray(pat, M, lps);

    int i = 0;
    int j = 0;

    while((N-i) >= (M-j)){
        if(txt[i] == pat[j]){
            i++;
            j++;
        }
        if(j == M){
            printf("Pattern Found : %d\n\n",(i-j));
            j = lps[j-1];
        }else if(i < N && txt[i] != pat[j]){
            if(!j){
                i++;
                j++;
            }else{
                j = lps[j-1];
            }
        }
    }
}

void computeLpsArray( char pat[],  int M, char lps[]){
    int i = 1;
    int len = 0;

    while(i < M){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len){
                len = lps[len-1];
            }else{
                lps[i] = len;
                i++;
            }
        }
    }
}