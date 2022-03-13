#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 20

char stack[MAX];
int top=-1;
char temp[MAX];

void push(char val);
int infixtopostfix(char infix[], char postfix[]);
int priority(char a);
int isoperator(char a);
char pop();
void reverse();

int main(){
	char infix[MAX], postfix[MAX];
	printf("Enter: ");
	scanf("%s", &infix);
	reverse(infix);
	infixtopostfix(infix,postfix);
	reverse(postfix);
	printf("The prefix expression is: ");
	printf("%s", temp);
}

void push(char val){
	if(top==MAX-1){
		printf("Stack overflow\n");
	}
	else{
		top++;
		stack[top]=val;
	}
}

char pop(){
	char val;
	if(top==-1){
		printf("Stack underflow\n");
	}
	else{
		val=stack[top];
		top--;
	}
	return val;
}

int isoperator(char a){
	if(a=='+' || a=='-' || a=='*' || a=='/'){
		return 1;
	}
	else{
		return 0;
	}
}

int priority(char a){
	if(a=='*' || a=='/'){
		return 1;
	}
	else if(a=='+' || a=='-'){
		return 0;
	}
}

int infixtopostfix(char infix[], char postfix[]){
	int i, j;
	i=0;
	j=0;
	char temp, op;
	push('(');
	strcat(infix,")");
	while(infix[i]!='\0'){
		if(infix[i]=='('){
			push(infix[i]);
		}
		else if(isalpha(infix[i]) || isdigit(infix[i])){
			postfix[j]=infix[i];
			j++;
		}
		else if(infix[i]==')'){
			while(stack[top]!='('){
				postfix[j]=pop();
				j++;
			}
			temp=pop();
		}
		else if(isoperator(infix[i])){
			op=pop();
			while(isoperator(op) && priority(op)>priority(infix[i])){
				postfix[j]=op;
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

void reverse(char str[]){
	int len, i, j;
	i=0;

	len=strlen(str);
	j=len-1;
	while(j>=0){
		if(str[j]==')'){
			temp[i]='(';
		}
		else if(str[j]=='('){
			temp[i]=')';
		}
		else{
			temp[i]=str[j];
		}
		i++; j--;
	}
	temp[i]='\0';
}
