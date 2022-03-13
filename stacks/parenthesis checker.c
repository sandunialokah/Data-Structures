#include<stdio.h>

#define MAX 10

int top=-1;
char stk[MAX];

void push(char data);
char pop();
int check(char a, char b);


int main(){
	char exp[20], value;
	int i;
	printf("Enter the expression: ");
	scanf("%s", &exp);
	for(i=0;i<sizeof(exp);i++){
		if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
			push(exp[i]);
		}
		else if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
			if(top==-1){
				printf("Invalid expresssion\n");
				return 0;
			}
			else{
				value=pop();
				if(check(value,exp[i])==0){
					printf("Invalid expression\n");
					return 0;
				}
			}
		}
	}
	if(top==-1){
		printf("Valid expression\n");
		return 1;
	}
	else{
		printf("Invalid expression\n");
		return 0;
	}
}

void push(char data){
	if(top==MAX-1){
		printf("overflow\n");
	}
	else{
		top++;
		stk[top]=data;
	}
}

char pop(){
	char value;
	if(top==-1){
		printf("uderflow\n");
	}
	else{
		value=stk[top];
		top--;
		return value;
	}
}

int check(char a, char b){
	if(a=='(' && b==')'){
		return 1;
	}
	else if(a=='{' && b=='}'){
		return 1;
	}
	else if(a=='[' && b==']'){
		return 1;
	}
	else{
		return 0;
	}
}
