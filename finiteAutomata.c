#include <stdio.h>
#include <string.h>

#define NUMBER_OF_ALPHABET 3

void search(char[], char[], int, int[][NUMBER_OF_ALPHABET]);
void buildTrnsTable(char[], char[], int, int[][NUMBER_OF_ALPHABET]);
int computeNextState(char[], char[], int, int[][NUMBER_OF_ALPHABET], int, int);

int main(){
    char txt[] = "abababacaba";
    char pat[] = "ababaca";
    char alph[] = "abc";
    int M = strlen(pat);
    int delta[M][NUMBER_OF_ALPHABET];

    buildTrnsTable(pat, alph, M, delta);

    printf("Transition table:\nstate   a b c\n");
    printf("-------------\n");
    for(int i = 0; i <= M; i++){
        printf("q%d\t",i);
        for(int j = 0; j < NUMBER_OF_ALPHABET; j++){
            printf("%d ",delta[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    search(txt, alph, M, delta);
    printf("\n");

    return 0;
}

void search(char txt[],char alph[], int M, int delta[][NUMBER_OF_ALPHABET]){
    int N = strlen(txt);
    int q = 0;

    for(int i = 0; i < N; i++){
        int temp = txt[i] - alph[0];
        q = delta[q][temp];
        if(q == M){
            printf("Pattern Found at : %d\n\n",i-M+1);
        }
    }
}

void buildTrnsTable(char pat[],char alph[], int M, int delta[][NUMBER_OF_ALPHABET]){// M is the final state or number of char in pat
    for(int state = 0; state <= M; state++){
        for(int x = 0; x < NUMBER_OF_ALPHABET; x++){
            delta[state][x] = computeNextState(pat, alph, M, delta, state, x);
        }
    }
}

int computeNextState(char pat[], char alph[], int M, int delta[][NUMBER_OF_ALPHABET], int state, int x){
    if(state < M && pat[state] == alph[x])
        return state+1; // is i return value++. then first the value is returned and then the value is incremented.

    int ns, i;

    for(ns = state; ns > 0; ns--){
        if(pat[ns-1] == alph[x]){
            for(i = 0; i < ns-1; i++){
                if(pat[i] != pat[state - (ns-1) + i])
                    break;
            }
            if(i == ns-1)
                return ns;
        }
    }

    return 0;
}