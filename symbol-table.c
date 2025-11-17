#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct SymbolTable {
    char name[30];
    char type[10];
    int size;
    int address;
} st[MAX];

int count=0;

void insert();
void display();
int search(char *);
void modify();
void delete();

int main(){
    int choice;
    char symbol[30];
    int result;

    while(1){
        printf("\n\n=== Symbol Table Operations ===\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Modify\n");
        printf("5. Delete\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter symbol to search: ");
                scanf("%s",symbol);
                result=search(symbol);
                if(result==-1){
                    printf("Symbol not found!\n");
                }
                else{
                    printf("Symbol found at index %d\n",result);
                }
                break;
            
                case 4:
                    modify();
                    break;
                case 5:
                    delete();
                    break;
                case 6:
                    exit(0);
                default:
                    printf("Invalid choice!\n");
        }
    }
    return 0;
}

void insert(){
    if(count>=MAX){
        printf("Symbol table is full!\n");
        return;
    }

    printf("Enter symbol name: ");
    scanf("%s",st[count].name);

    if(search(st[count].name)!=-1){
        printf("Symbol already exists!\n");
        return;
    }

    printf("Enter type (int/float/char): ");
    scanf("%s",st[count].type);
    printf("Enter size: ");
    scanf("%d",&st[count].size);
    printf("Enter address: ");
    scanf("%d",&st[count].address);

    count++;
    printf("Symbol inserted successfully!\n");
}

void display(){
    if(count==0){
        printf("Symbol table is empty!\n");
        return;
    }
    printf("\n%-15s %-10s %-10s %-10s\n", "Name", "Type", "Size", "Address");
    printf("----------------------------------------------------\n");
    for(int i = 0; i < count; i++) {
        printf("%-15s %-10s %-10d %-10d\n", 
               st[i].name, st[i].type, st[i].size, st[i].address);
    }
}

int search(char *name){
    for(int i=0;i<count;i++){
        if(strcmp(st[i].name,name)==0){
            return i;
        }
    }
    return -1;
}

void modify(){
    char name[30];
    int index;

    printf("Enter symbol name to modify: ");
    scanf("%s",name);

    index = search(name);
    if(index==-1){
        printf("Symbol not found!\n");
        return;
    }

    printf("Enter new type: ");
    scanf("%s", st[index].type);
    printf("Enter new size: ");
    scanf("%d", &st[index].size);
    printf("Enter new address: ");
    scanf("%d", &st[index].address);

    printf("Symbol modified successfully!\n");
}

void delete(){
    char name[30];
    int index;

    printf("Enter symbol name to delete: ");
    scanf("%s",name);

    index =search(name);
    if(index==-1){
        printf("Symbol not found!\n");
        return;
    }
    for(int i=index;i<count-1;i++){
        st[i]=st[i+1];
    }
    count--;
    printf("Symbol deleted successfully!\n");
}