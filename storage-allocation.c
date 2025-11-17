#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_SIZE 1000

typedef struct
{
    char name[30];
    char type[10];
    int size;
    int offset;
} StackFrame;

StackFrame stack[100];
int frameCount = 0;
int stackPointer = 0;

void allocate(char *name, char *type, int size);
void deallocate();
void display();
int getSize(char *type);

int main()
{
    int choice, size;
    char name[30], type[10];
    while (1)
    {
        printf("\n=== Stack Storage Allocation ===\n");
        printf("Stack Size: %d bytes\n", STACK_SIZE);
        printf("Used: %d bytes\n", stackPointer);
        printf("Free: %d bytes\n\n", STACK_SIZE - stackPointer);

        printf("1. Allocate Variable\n");
        printf("2. Deallocate (Pop)\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter variable name: ");
                scanf("%s", name);
                printf("Enter type (int/float/char/double):");
                scanf("%s", type);
                size = getSize(type);
                allocate(name, type, size);
                break;
            case 2:
                deallocate();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

void allocate(char *name, char *type, int size)
{
    if (stackPointer + size > STACK_SIZE)
    {
        printf("Stack Overflow! Cannot allocate!\n");
        return;
    }
    strcpy(stack[frameCount].name, name);
    strcpy(stack[frameCount].type, type);
    stack[frameCount].size = size;
    stack[frameCount].offset = stackPointer;

    stackPointer += size;
    frameCount++;

    printf("Allocated %d bytes for %s at offset %d\n", size, name, stackPointer - size);
}

void deallocate()
{
    if (frameCount == 0)
    {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    frameCount--;
    stackPointer -= stack[frameCount].size;
    printf("Deallocated '%s' (%d bytes)\n", stack[frameCount].name, stack[frameCount].size);
}

void display()
{
    if (frameCount == 0)
    {
        printf("Stack is Empty!\n");
        return;
    }

    printf("\n=== Stack Frame Contents ===\n");
    printf("%-15s %-10s %-10s %-10s\n", "Variable", "Type", "Size", "Offset");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < frameCount; i++)
    {
        printf("%-15s %-10s %-10d %-10d\n",
               stack[i].name, stack[i].type, stack[i].size, stack[i].offset);
    }
    printf("\nStack Pointer: %d\n", stackPointer);
}

int getSize(char *type)
{
    if (strcmp(type, "int") == 0)
    {
        return 4;
    }
    else if (strcmp(type, "float") == 0)
    {
        return 4;
    }
    else if (strcmp(type, "char") == 0)
    {
        return 1;
    }
    else if (strcmp(type, "double") == 0)
    {
        return 8;
    }
    return 4;
}