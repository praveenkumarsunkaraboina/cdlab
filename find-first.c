#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 10

char productions[MAX][MAX];
char first[MAX][MAX];
int n;

void findFirst(char c);
int isTerminal(char c);
void addToFirst(char c, char symbol);

int main() {
    int i;
    char choice, c;
    
    printf("=== FIRST SET CALCULATOR ===\n\n");
    printf("Enter number of productions: ");
    scanf("%d", &n);
    
    printf("Enter productions (format: E=E+T or E=@):\n");
    printf("Use @ for epsilon\n");
    for(i = 0; i < n; i++) {
        printf("Production %d: ", i + 1);
        scanf("%s", productions[i]);
    }
    
    // Initialize first sets
    for(i = 0; i < MAX; i++)
        first[i][0] = '\0';
    
    do {
        printf("\nEnter non-terminal to find FIRST (uppercase): ");
        scanf(" %c", &c);
        
        if(!isupper(c)) {
            printf("Please enter a non-terminal (uppercase letter)\n");
            continue;
        }
        
        findFirst(c);
        
        printf("\nFIRST(%c) = { ", c);
        for(i = 0; i < strlen(first[c - 'A']); i++) {
            if(i > 0) printf(", ");
            if(first[c - 'A'][i] == '@')
                printf("ε");
            else
                printf("%c", first[c - 'A'][i]);
        }
        printf(" }\n");
        
        printf("\nContinue? (y/n): ");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');
    
    return 0;
}

void findFirst(char c) {
    int i, j, k;
    int index = c - 'A';
    
    // If already computed, return
    if(strlen(first[index]) > 0)
        return;
    
    // If terminal, add itself
    if(isTerminal(c)) {
        addToFirst(c, c);
        return;
    }
    
    // Check all productions with c on left side
    for(i = 0; i < n; i++) {
        if(productions[i][0] == c) {
            // Check right side of production
            if(productions[i][2] == '@') {  // epsilon production
                addToFirst(c, '@');
            } else if(isTerminal(productions[i][2])) {
                addToFirst(c, productions[i][2]);
            } else {
                // Non-terminal - recursively find its FIRST
                findFirst(productions[i][2]);
                for(j = 0; j < strlen(first[productions[i][2] - 'A']); j++) {
                    addToFirst(c, first[productions[i][2] - 'A'][j]);
                }
            }
        }
    }
}

int isTerminal(char c) {
    return !isupper(c);
}

void addToFirst(char c, char symbol) {
    int index = c - 'A';
    // Check if symbol already exists
    if(strchr(first[index], symbol) == NULL) {
        int len = strlen(first[index]);
        first[index][len] = symbol;
        first[index][len + 1] = '\0';
    }
}