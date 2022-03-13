#include<stdio.h>

#define MAX 3

int queue[MAX];
int front=-1;
int rear=-1;

int del();
void insert();
int peek();
void display();

int main(){
	int option, val;
	do{
		printf("\n***********MAIN MENU**********\n");
		printf("1)insert\n2)delete\n3)peek\n4)display\n5)exit\nEnter your option: ");
		scanf("%d", &option);
		switch(option){
		case 1:
			insert();
			break;
		case 2:
			val=del();
			printf("The element deleted is: %d\n", val);
			break;
		case 3:
			val=peek();
			printf("The first value of the queue is: %d\n", val);
			break;
		case 4:
			display();
			break;
		}
	}
	while(option!=5);
	return 0;
} 

void insert(){
	int n;
	printf("Enter the number to be inserted: ");
	scanf("%d", &n);
	if(rear==MAX-1 && front==0){
		printf("overflow\n");
	}
	else if(rear==-1 && front == -1){
		rear=front=0;
		queue[rear]=n;
	}
	else if(rear==MAX-1 && front!=0){
		rear=0;
		queue[rear]=n;
	}
	else{
		rear++;
		queue[rear]=n;
	}
}

int del(){
	int value;
	if(front==-1 && rear ==-1){
		printf("underflow\n");
	}
	value=queue[front];
	if(front==MAX-1){
		front=0;
	}
	else{
		front++;
	}
	return value;
}

int peek(){
	int value;
	if(front==-1 && rear==-1){
		printf("underflow\n");
	}
	else{
		value=queue[front];
		return value;
	}
}

void display(){
	int i;
	if(front<=rear){
		for(i=front;i<=rear;i++){
			printf("%d\t", queue[i]);
		}
	}
	else{
		for(i=front;i<MAX;i++){
			printf("%d\t", queue[i]);
		}
		for(i=0;i<=rear;i++){
			printf("%d\t", queue[i]);
		}
	}
}
