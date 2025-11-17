#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char input[100];
int i=0;

void S();
void L();
void error();

int main(){
    printf("=== Recursive Descent Parser For Lists ===\n");
    printf("Grammar:\n");
    printf("S -> ( L ) | a\n");
    printf("L -> L , S | S\n\n");

    printf("Enter input string (end with $): ");
    scanf("%s", input);

    printf("\n=== Parsing Process ===\n");
    S();

    if(input[i]=='$'){
        printf("\n Parsing Successfull!\n");
    }
    else{
        printf("\n Parsing Failed!\n");
        printf("Unexpected symbol at position %d: %c\n",i,input[i]);
    }
    return 0;
}

void S(){
    if(input[i]=='('){
        printf("S -> ( L )\n");
        i++;
        L();
        if(input[i]==')'){
            i++;
        }
        else{
            error();
        }
    }
    else if(input[i]=='a'){
        printf("S -> a\n");
        i++;
    }
    else{
        error();
    }
}

void L(){
    printf("L -> S L'\n");
    S();

    while(input[i]==','){
        printf("L' -> , S L'\n");
        i++;
        S();
    }
    printf("L' -> epsilon\n");
}

void error(){
    printf("\n Syntax Error at Position %d\n",i);
    printf("Unexpected symbol: %c\n",input[i]);
    exit(1);
}