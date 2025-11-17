#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[20];
int top = -1;

void push(char);
char pop();
void error();

void main() {
    char str[50], ch;
    int ip = 0;
    
    printf("Enter string ending with $: ");
    scanf("%s", str);
    
    push('$');
    push('E');
    
    printf("\nParsing Steps:\n");
    printf("%-15s %-15s %-20s\n", "Stack", "Input", "Action");
    printf("--------------------------------------------------------\n");
    
    while((ch = pop()) != '$') {
        // Print current state
        printf("%-15s %-15s ", stack, &str[ip]);
        
        if(ch == 'E') {
            if(str[ip] == 'a' || str[ip] == '(') {
                printf("E -> TR\n");
                push('R');
                push('T');
            }
            else 
                error();
        }
        else if(ch == 'R') {
            if(str[ip] == '+') {
                printf("R -> +TR\n");
                push('R');
                push('T');
                push('+');
            }
            else if(str[ip] == ')' || str[ip] == '$') {
                printf("R -> epsilon\n");
                // Epsilon production - do nothing
            }
            else 
                error();
        }
        else if(ch == 'T') {
            if(str[ip] == 'a' || str[ip] == '(') {
                printf("T -> FP\n");
                push('P');
                push('F');
            }
            else 
                error();
        }
        else if(ch == 'P') {
            if(str[ip] == '*') {
                printf("P -> *FP\n");
                push('P');
                push('F');
                push('*');
            }
            else if(str[ip] == '+' || str[ip] == ')' || str[ip] == '$') {
                printf("P -> epsilon\n");
                // Epsilon production - do nothing
            }
            else 
                error();
        }
        else if(ch == 'F') {
            if(str[ip] == 'a') {
                printf("F -> a\n");
                push('a');
            }
            else if(str[ip] == '(') {
                printf("F -> (E)\n");
                push(')');
                push('E');
                push('(');
            }
            else 
                error();
        }
        else if(ch == '+') {
            if(str[ip] == '+') {
                printf("Match '+'\n");
                ip++;
            }
            else 
                error();
        }
        else if(ch == '*') {
            if(str[ip] == '*') {
                printf("Match '*'\n");
                ip++;
            }
            else 
                error();
        }
        else if(ch == '(') {
            if(str[ip] == '(') {
                printf("Match '('\n");
                ip++;
            }
            else 
                error();
        }
        else if(ch == ')') {
            if(str[ip] == ')') {
                printf("Match ')'\n");
                ip++;
            }
            else 
                error();
        }
        else if(ch == 'a') {
            if(str[ip] == 'a') {
                printf("Match 'a'\n");
                ip++;
            }
            else 
                error();
        }
    }
    
    // Check if input is fully consumed
    if(str[ip] == '$') {
        printf("\n*** Parsing is successful ***\n");
    }
    else {
        printf("\n*** Parsing failed: Input not fully consumed ***\n");
    }
}

void error() {
    printf("Error\n");
    printf("\n*** Parsing is not successful ***\n");
    exit(0);
}

void push(char c) {
    if(top >= 19) {
        printf("Stack overflow\n");
        exit(1);
    }
    top++;
    stack[top] = c;
    stack[top + 1] = '\0';  // Null terminate for printing
}

char pop() {
    if(top < 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    char c = stack[top];
    stack[top] = '\0';  // Clear the position
    top--;
    return c;
}
