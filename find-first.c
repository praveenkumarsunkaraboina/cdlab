
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char firstE[10], firstT[10], firstF[10];
int eIndex = 0, tIndex = 0, fIndex = 0;

void addToSet(char arr[], int *idx, char symbol) {
    for (int i = 0; i < *idx; i++) {
        if (arr[i] == symbol)
            return; // avoid duplicates
    }
    arr[(*idx)++] = symbol;
}

// FIRST(F)
void computeFIRST_F() {
    addToSet(firstF, &fIndex, '(');  // from F → (E)
    addToSet(firstF, &fIndex, 'i');  // from F → id (taking i as first char of id)
}

// FIRST(T)
void computeFIRST_T() {
    // T → T * F | F
    // FIRST(T) = FIRST(F)
    for (int i = 0; i < fIndex; i++)
        addToSet(firstT, &tIndex, firstF[i]);
}

// FIRST(E)
void computeFIRST_E() {
    // E → E + T | T
    // FIRST(E) = FIRST(T)
    for (int i = 0; i < tIndex; i++)
        addToSet(firstE, &eIndex, firstT[i]);
}

int main() {
    computeFIRST_F();
    computeFIRST_T();
    computeFIRST_E();

    printf("FIRST(E) = { ");
    for (int i = 0; i < eIndex; i++)
        printf("%c ", firstE[i]);
    printf("}\n");

    printf("FIRST(T) = { ");
    for (int i = 0; i < tIndex; i++)
        printf("%c ", firstT[i]);
    printf("}\n");

    printf("FIRST(F) = { ");
    for (int i = 0; i < fIndex; i++)
        printf("%c ", firstF[i]);
    printf("}\n");

    return 0;
}
    return 0;

