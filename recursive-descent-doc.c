#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char input[100];
int i = 0;

void E();
void R();
void T();
void P();
void F();
void error();

int main() {
    printf("=== Recursive Descent Parser ===\n");
    printf("Grammar:\n");
    printf("E -> T R\n");
    printf("R -> + T R | epsilon\n");
    printf("T -> F P\n");
    printf("P -> * F P | epsilon\n");
    printf("F -> ( E ) | a\n\n");

    printf("Enter input string (end with $): ");
    scanf("%s", input);

    printf("\n=== Parsing Process ===\n");
    E();

    if (input[i] == '$') {
        printf("\nParsing Successful!\n");
    } else {
        printf("\nParsing Failed!\n");
        printf("Unexpected symbol at position %d: %c\n", i, input[i]);
    }
    return 0;
}

void E() {
    printf("E -> T R\n");
    T();
    R();
}

void R() {
    if (input[i] == '+') {
        printf("R -> + T R\n");
        i++;
        T();
        R();
    } else {
        printf("R -> epsilon\n");
    }
}

void T() {
    printf("T -> F P\n");
    F();
    P();
}

void P() {
    if (input[i] == '*') {
        printf("P -> * F P\n");
        i++;
        F();
        P();
    } else {
        printf("P -> epsilon\n");
    }
}

void F() {
    if (input[i] == '(') {
        printf("F -> ( E )\n");
        i++;
        E();
        if (input[i] == ')') {
            i++;
        } else {
            error();
        }
    } else if (input[i] == 'a') {
        printf("F -> a\n");
        i++;
    } else {
        error();
    }
}

void error() {
    printf("\nSyntax Error at Position %d\n", i);
    printf("Unexpected symbol: %c\n", input[i]);
    exit(1);
}
