#include<stdio.h>

int arr[20];
int top=-1;
int max=sizeof(arr)/sizeof(arr[0]);

void push(int data);
int pop();
int peek();
int IsFull();
int IsEmpty();

int main(){
	int n, value;
	do{
		printf("\n*****MAIN MENU*****\n");
		printf("1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\n");
		printf("Enter your option: ");
		scanf("%d", &n);
		switch(n){
			case 1:
				printf("Enter the number to be pushed to stack: ");
				scanf("%d", &value);
				push(value);
				break;
			case 2:
				value = pop();
				printf("The value poped is: %d", value);
				break;
			case 3:
				value = peek();
				printf("The value stored at the top of the stack is: %d", value);
				break;
			case 4:
				display();
				break;
		}	
	}while(n!=5);
	
	
			
}

void push(int data){
	if(IsFull()){
		printf("overflow\n");
	}
	else{
		top++;
		arr[top]=data;
	}
}

int pop(){
	int value;
	if(IsEmpty()){
		printf("uderflow\n");
	}
	else{
		value=arr[top];
		top--;
	}
	return value;
}

int peek(){
	int value;
	if(IsEmpty()){
		printf("stack is empty\n");
	}
	else{
		value=arr[top];
		return top;
	}
}

int IsFull(){
	if(top==max-1){
		return 1;
	}
	else{
		return 0;
	}
}

int IsEmpty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}

int display(){
	int i;
	for(i=top;i>-1;i--){
		printf("%d\t", arr[i]);
	}
}

