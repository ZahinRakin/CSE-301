#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <time.h>

void createAccount();
void logIn();
int checkStrength(char*);
void generatePassword(char*);

void main(){
  printf("Welcome to Master Password.\n");
  int choice;
  printf("1.Create Account.\n2.Log In.\nChoice:");
  scanf("%d",&choice);
  if(choice == 1)
    createAccount();
  else if(choice == 2)
    logIn();
  else 
    printf("Wrong command!\n");
}

void createAccount(){
  char userName[20];
  printf("Username:");
  scanf("%s",userName);
  getchar();
  int choice;
  char password[53];
  printf("1.Generate Password.\n2.Password.\nChoice:");
  scanf("%d",&choice);
  if(choice == 1){
    generatePassword(password);
  }
  else if(choice == 2){
    Again:
    scanf("%s",password);
    int temp = checkStrength(password);
    if(temp == 1){
      goto Again;
    }
  }
 } 
void logIn(){}

void generatePassword(char* password){}

int checkStrength(char* password){}
