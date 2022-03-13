#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX 100

char st[MAX];
int top=-1;

int InfixToPostfix(char infix[], char postfix[]);
void push(char val);
char pop();
int priority(char val);
int is_operator(char val);

int main(){
	char infix[MAX], postfix[MAX];
	printf("Enter the infix expression: ");
	scanf("%s", &infix);
	InfixToPostfix(infix,postfix);
	printf("The postfix expression is: %s", postfix);
}

void push(char val){
	if(top==MAX-1){
		printf("stack overflow\n");
	}
	else{
		top++;
		st[top]=val;
	}
}

char pop(){
	char val;
	if(top==-1){
		printf("stack uderflow");
	}
	else{
		val=st[top];
		top--;
		return val;
	}
}

int InfixToPostfix(char infix[], char postfix[]){
	int i, j;
	i=0;
	j=0;
	char op, temp;
	push('(');
	strcat(infix, ")");
	while(st[top]!='\0'){
		if(infix[i]=='('){
			push(infix[i]);
		}
		else if(isdigit(infix[i]) || isalpha(infix[i])){
			postfix[j]=infix[i];
			j++;
		}
		else if(infix[i]==')'){
			while(st[top]!='('){
				postfix[j]=pop();
				j++;
			}
			temp=pop();
		}
		else if(is_operator(infix[i])){
			op=pop();
			while(is_operator(op) && priority(op)>=priority(infix[i])){
				postfix[j]=op;
				j++;
				op=pop();
			}
			push(op);
			push(infix[i]);
		}
		else{
			printf("Invalid expression\n");
			return 0;
		}
		i++;
	}
	if(top!=-1){
		printf("Invalid expression\n");
		return 0;
	}
	postfix[j]='\0';
}

int is_operator(char val){
	if(val=='+' || val=='-' || val=='*' || val=='/' || val=='%'){
		return 1;
	}
	else{
		return 0;
	}
}

int priority(char val){
	if(val=='*' || val=='/' || val=='%'){
		return 1;
	}
	else if(val=='+' || val=='-'){
		return 0;
	}
}
