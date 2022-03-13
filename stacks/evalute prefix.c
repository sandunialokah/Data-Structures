#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX 100

int evaluate(char exp[]);
int pop();
void push(char data);

char st[MAX];
int top=-1;

int main(){
	char exp[MAX];
	int val;
	printf("Enter the prefix to be evaluated: ");
	scanf("%s", &exp);
	val = evaluate(exp);
	printf("Evaluated prefix: %d", val);
}

int evaluate(char exp[]){
	int i, op1, op2, val;
	int n=strlen(exp);
	for(i=n-1;i>-1;i--){
		if(isdigit(exp[i])){
			push((int)(exp[i]-'0'));
		}
		else{
			op1=pop();
			op2=pop();
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
			}
			push(val);
		}
	}
	return val;
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
		val=st[top];
		top--;
		return val;
	}
}
