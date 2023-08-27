#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* generatePassword(char*);

void main(){
  srand(time(0));
  char* p = generatePassword(p);
  printf("The password is: ");
  puts(p);
}

char* generatePassword(char* password){
  int length, i;
  length = rand()%46 + 6;
  password = malloc(length*sizeof(char));
  for(i = 0; i < length-1; i++){
    password[i] = (char)(rand()%93 + 33);
  }
  password[i] = '\0';
  return password;
}
