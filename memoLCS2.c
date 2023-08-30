#include <stdio.h>
#include <string.h>

int memo[100][100];
char b[100][100];

int max(int , int);

void print(char*, int, int);

int lcs( char*, char*, int , int);

int main() {
   	for(int i = 0; i < 100; i++){
   		for(int j = 0; j < 100; j++){
   			memo[i][j] = -1;
   		}
   	}

    char str1[100];
    char str2[100];
    
    printf("Enter string 1: ");
    scanf("%s",str1);
    getchar();
    printf("Enter string 2: ");
    scanf("%s",str2);
    getchar();
    
    int size1 = strlen(str1);
    int size2 = strlen(str2);

    int result = lcs(str1, str2, size1, size2);
    printf("\n");

    printf("Length of Longest Common Subsequence: %d\n", result);
    printf("Longest subsequence is: ");
    print(str2, size1,  size2);
  
	printf("\n");
    return 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lcs(char* str1, char* str2, int s1, int s2) {
    if (s1 == 0 || s2 == 0){
		b[s1][s2] = ' ';
        return 0;
	}
    if (memo[s1][s2] != -1)
        return memo[s1][s2];

    if (str1[s1 - 1] == str2[s2 - 1]) {
    	b[s1][s2] = '\\';
        memo[s1][s2] = 1 + lcs(str1, str2, s1 - 1, s2 - 1);
    } 
    else {
        memo[s1][s2] = max(lcs(str1, str2, s1 - 1, s2), lcs(str1, str2, s1, s2 - 1));
        b[s1][s2] = (lcs(str1, str2, s1 - 1, s2) > lcs(str1, str2, s1, s2 - 1)) ? '|' : '-';
    }
    return memo[s1][s2];
}

void print(char* str2, int i, int j){
    if(i == 0 || j == 0)
        return;
    if(b[i][j] == '\\'){
        print(str2,i-1, j-1);
        printf("%c", str2[j-1]);
    }
    else if(b[i][j] == '|'){
        print(str2,i-1, j);
    }
    else{
        print(str2,i, j-1);
    }
}
