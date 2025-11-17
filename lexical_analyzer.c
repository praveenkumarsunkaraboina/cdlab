#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char keywords[32][10] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};

int isKeyword(char *str){
    for(int i=0;i<32;i++){
        if(strcmp(keywords[i],str)==0){
            return 1;
        }
    }
    return 0;
}

int isOperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='='||ch=='<'||ch=='>'||ch=='&'||ch=='|'||ch=='!'||ch=='%'){
        return 1;
    }
    return 0;
}

int isDelimiter(char ch){
    if(ch==','||ch=='('||ch==')'||ch=='{'||ch=='}'||ch=='['||ch==']'||ch==';'||ch=='\n'||ch=='\t'||ch==' '){
        return 1;
    }
    return 0;
}

void analyze(char *input){
    int i=0;
    while(input[i]!='\0'){
        char current_char = input[i];
        
        if(isOperator(current_char)){
            printf("[OPERATOR]: %c\n",current_char);
            i++;
            continue;
        }

        if(isDelimiter(current_char)){
            printf("[DELIMITER]: %c\n",current_char);
            i++;
            continue;
        }

        if(isalpha(current_char)||current_char=='_'){
            char buffer[50];
            int j=0;
            while(isalnum(input[i])||input[i]=='_'){
                buffer[j++]=input[i++];
            }
            buffer[j]='\0';
            if(isKeyword(buffer)){
                printf("[KEYWORD]: %s\n",buffer);
            }
            else{
                printf("[IDENTIFIER]: %s\n",buffer);
            }
            continue;
        }

        if(isdigit(current_char)){
            char buffer[50];
            int j=0;
            while(isdigit(input[i])){
                buffer[j++]=input[i++];
            }
            buffer[j]='\0';
            printf("[CONSTANT (Integer)]: %s\n",buffer);
        }

        if(current_char=='/'&&input[i+1]=='/'){
            printf("{COMMENT}: ");
            i+=2;
            while(input[i]!='\n'&&input[i]!='\0'){
                printf("%c",input[i]);
                i++;
            }
            printf("\n");
            continue;
        }
        i++;
    }
}

int main(){
    char code[]="int x=10; //start\nif (x>5) {return x;}";
    printf("---Input Code---\n%s\n",code);
    printf("---Output Tokens---\n");
    analyze(code);
    return 0;
}