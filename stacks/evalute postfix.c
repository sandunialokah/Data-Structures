#include<stdio.h>
#include<ctype.h>

#define MAX 100

char st[MAX];
int top=-1;

int main(){
	char exp[MAX];
	int val;
	printf("Enter the postfix expression: ");
	scanf("%s", &exp);
	val = evaluate(exp);
	printf("The evaluated expression is: %d", val);
	return 0;
}

void push(char data){
	if(top==MAX-1){
		printf("stack overflow\n");
	}
	else{
		top++;
		st[top]=data;
	}
}

int pop(){
	int val;
	if(top==-1){
		printf("stack underflow\n");
	}
	else{
		val = st[top];
		top--;
		return val;
	}
}

int evaluate(char exp[]){
	int i, op1, op2, val;
	i=0;
	while(exp[i]!='\0'){
		if(isdigit(exp[i])){
			push((int)(exp[i]-'0'));
		}
		else{
			op2=pop();
			op1=pop();
			switch(exp[i]){
				case '+':
					val=op1+op2;
					break;
				case '-':
					val=op1-op2;
					break;
				case '*':
					val=op1*op2;
					break;
				case '/':
					val=op1/op2;
					break;
				case '%':
					val=op1%op2;
					break;	
			}
			push(val);
		}
		i++;
	}
	return pop();
}
