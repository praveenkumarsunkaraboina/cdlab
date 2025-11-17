#include<stdio.h>
#include<process.h>
#include<conio.h>
char stack[20];
int top=-1;
void push(char);
char pop();
void error();
void main()
{
char str[10],ch;
int ip=0;
clrscr();
printf("enter string ending with $");
scanf("%s",str);
push('$');
push('E');
while((ch=pop())!='$')
{
switch(ch)
{
case 'E':{
	 if(str[ip]=='a'||str[ip]=='(')
	 {
	 push('R');
	 push('T');
	 }
	 else error();
	 }
	 break;
case 'R':{
	 if(str[ip]=='+')
	 {
	 push('R');
	 push('T');
	 push('+');
	 }
	 else if(str[ip]==')'||str[ip]=='$')
	 {
	 }
	 else error();
	 }
	 break;
case 'T':{
	 if(str[ip]=='a'||str[ip]=='(')
	 {
	 push('P');
	 push('F');
	 }
	 else error();
	 }
	 break;
case 'P':{
	 if(str[ip]=='*')
	 {
	 push('P');
	 push('F');
	 push('*');
	 }
	 else if(str[ip]=='+'||str[ip]==')'||str[ip]=='$')
	 {
	 }
	 else error();
	 }
	 break;
case 'F':{
	 if(str[ip]=='a')
	 push('a');
	 else if(str[ip]=='(')
	 {
	 push(')');
	 push('E');
	 push('(');
	 }
	 else error();
	 }
	 break;
case '+':if(str[ip]=='+')
	 ip++;
	 break;
case '*':if(str[ip]=='*')
	 ip++;
	 break;
case '(':if(str[ip]=='(')
	 ip++;
	 break;
case ')':if(str[ip]==')')
	 ip++;
	 break;
case 'a':if(str[ip]=='a')
	 ip++;
	 break;
}
}
if(stack[top+1]=='$')
printf("parsing is succesful");
}
void error()
{
printf("parsing is not successful");
exit(0);
}
void push(char c)
{
top++;
stack[top]=c;
}
char pop()
{
top--;
return(stack[top+1]);
}
