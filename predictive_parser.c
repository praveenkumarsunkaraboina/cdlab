#include <stdio.h>
#include <stdlib.h>

char stack[20];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

void error() {
    printf("Parsing not successful\n");
    exit(0);
}

void main() {
    char str[10], ch;
    int ip = 0;
    
    printf("Enter string ending with $: ");
    scanf("%s", str);
    
    push('$');
    push('E');
    
    while ((ch = pop()) != '$') {
        switch (ch) {
        case 'E':
            if (str[ip] == 'a' || str[ip] == '(') {
                push('R');
                push('T');
            } else error();
            break;
            
        case 'R':
            if (str[ip] == '+') {
                push('R');
                push('T');
                push('+');
            } else if (str[ip] != ')' && str[ip] != '$') error();
            break;
            
        case 'T':
            if (str[ip] == 'a' || str[ip] == '(') {
                push('P');
                push('F');
            } else error();
            break;
            
        case 'P':
            if (str[ip] == '*') {
                push('P');
                push('F');
                push('*');
            } else if (str[ip] != '+' && str[ip] != ')' && str[ip] != '$') error();
            break;
            
        case 'F':
            if (str[ip] == 'a') {
                push('a');
            } else if (str[ip] == '(') {
                push(')');
                push('E');
                push('(');
            } else error();
            break;
            
        case '+': case '*': case '(': case ')': case 'a':
            if (str[ip] == ch) ip++;
            break;
        }
    }
    
    if (str[ip] == '$')
        printf("Parsing successful\n");
    else
        printf("Parsing not successful\n");
}

// a+a$           → Parsing successful
// a*(a+a)$       → Parsing successful
// a+*a$          → Error/Parsing not successful
// (a+a)*a$       → Parsing successful
