#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char input[100];
int i=0;

void E();
void EPrime();
void T();
void TPrime();
void F();
void error();

int main(){
    printf("=== Recursive Descent Parser ===\n");
    printf("Grammar:\n");
    printf("E -> T E'\n");
    printf("E' -> + T E'| epsilon\n");
    printf("T -> F T'\n");
    printf("T' -> * F T'| epsilon\n");
    printf("F -> (E) | id\n\n");

    printf("Enter input string (end with $): ");
    scanf("%s",input);

    printf("\n=== Parsing Process ===\n");
    E();

    if(input[i]=='$'){
        printf("\n Parsing Successfull!\n");
    }
    else{
        printf("\n Parsing Failed!\n");
        printf("Unexpected symbol at position %d: %c\n",i,input[i]);
    }
    return 0;
}

void E(){
    printf("E -> T E'\n");
    T();
    EPrime();
}

void EPrime(){
    if(input[i]=='+'){
        printf("E' -> + T E'\n");
        i++;
        T();
        EPrime();
    }
    else{
        printf("E' -> epsilon\n");
    }
}

void T(){
    printf("T -> F T'\n");
    F();
    TPrime();
}

void TPrime(){
    if(input[i]=='*'){
        printf("T' -> * F T'\n");
        i++;
        F();
        TPrime();
    }
    else{
        printf("T' -> epsilon\n");
    }
}

void F(){
    if(input[i]=='('){
        printf("F -> ( E )\n");
        i++;
        E();
        if(input[i]==')'){
            i++;
        }
        else{
            error();
        }
    }
    else if(isalpha(input[i])||isdigit(input[i])){
        printf("F -> id (%c)\n",input[i]);
        i++;
    }
    else{
        error();
    }
}

void error(){
    printf("\n Syntax Error at Position %d\n",i);
    printf("Unexpected symbol: %c\n",input[i]);
    exit(1);
}