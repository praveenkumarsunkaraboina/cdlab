#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

struct SymbolTable
{
    char name[30];
    char type[10];
} symbolTable[MAX];

int symbolCount = 0;

void addSymbol(char *name,char *type);
char* getType(char *name);
int typeCheck(char *type1,char *op, char *type2);
char* resultType(char *type1,char *type2);

int main(){
    char var1[30], var2[30], op[5], result[10];
    int choice;
    while(1){
        printf("\n=== Type Checking System ===\n");
        printf("1. Declare Variable\n");
        printf("2. Check Expression Type\n");
        printf("3. Display Symbol Table\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter variable name: ");
                scanf("%s",var1);
                printf("Enter type (int/float/char): ");
                scanf("%s",result);
                addSymbol(var1,result);
                printf("Variable declared successfully!\n");
                break;
            
            case 2:
                printf("Enter expression (var1 op var2): ");
                scanf("%s %s %s",var1, op, var2);
                char *type1=getType(var1);
                char *type2=getType(var2);
                if(type1==NULL||type2==NULL){
                    printf("Type Error: Undeclared variable!\n");
                    break;
                }
                if(typeCheck(type1,op,type2)){
                    char *resType=resultType(type1,type2);
                    printf("Type Checking PASSED!\n");
                    printf("Result Type: %s\n",resType);
                }
                else{
                    printf("Type Error: Incompatible types for operation!\n");
                }
                break;
            case 3:
                printf("\n=== Symbol Table ===\n");
                printf("%-15s %-10s\n","Name","Type");
                printf("---------------------------\n");
                for(int i=0;i<symbolCount;i++){
                    printf("%-15s %-10s\n",symbolTable[i].name,symbolTable[i].type);
                }
                break;
            
            case 4:
                exit(0);
            
            default:
                printf("Invalid Choice!\n");

        }
    }
    return 0;
}

void addSymbol(char *name,char *type){
    strcpy(symbolTable[symbolCount].name,name);
    strcpy(symbolTable[symbolCount].type,type);
    symbolCount++;
}

char* getType(char *name){
    for(int i=0;i<symbolCount;i++){
        if(strcmp(symbolTable[i].name,name)==0){
            return symbolTable[i].type;
        }
    }
    return NULL;
}

int typeCheck(char *type1,char *op,char *type2){
    if(strcmp(op,"+")==0||strcmp(op,"-")==0||strcmp(op,"*")==0||strcmp(op,"/")==0){
        if((strcmp(type1,"int")==0||strcmp(type1,"float")==0||strcmp(type1,"char"))&&(strcmp(type2,"int")==0||strcmp(type2,"float")==0||strcmp(type2,"char"))){
            return 1;
        }
    }
    if(strcmp(type1,type2)==0){
        return 1;
    }
    return 0;
}

char* resultType(char *type1,char *type2){
    if(strcmp(type1,"float")==0||strcmp(type2,"float")==0){
        return "float";
    }
    else if(strcmp(type1,"int")==0||strcmp(type2,"int")==0){
        return "int";
    }
    return "char";
}
