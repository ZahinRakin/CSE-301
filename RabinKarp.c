#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search(char[], char[]);

int main(){
    char txt[100] = "GEEKS FOR GEEKS";
    char pat[100] = "GEEK";
    search(txt,pat);
    return 0;
}

void search(char txt[], char pat[]){
    int M = strlen(pat);
    int N = strlen(txt);
    int p = 0;
    int t = 0;
    int h = 1;
    int d = 10;
    int q = 101; //this has to be a prime number.

    for(int i = 0; i < M; i++){
        p = ((p*d) + (int)pat[i])%q;
        t = ((t*d) + (int)txt[i])%q;
    }

    for(int i = 0; i < M-1; i++){
        h = (h*d)%q;
    }

    for(int i = 0;i <= N-M; i++){
        if(p == t){
            int j;
            for(j = 0; j < M; j++){
                if(txt[i+j] != pat[j]){
                    break;
                }
            }
            if(j == M){
                printf("Pattern Found at : %d\n\n",i);
            }
        }
        if(i < N-M){
            t = (d*(t-(int)txt[i]*h) + (int)txt[i+M])%q;
            //i missed a very hidden case. if the t's value if negative i have to turn that into positive by adding the q
            if(t<0){
                t += q;
            }
        }
    }
}