#include<stdio.h>

#define MAX 100

int queue[MAX];
int front=-1;
int rear=-1;

void insert();
int del();
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
	if(rear==MAX -1){
		printf("overflow\n");
	}
	else if(rear== -1 && front == -1){
		rear=front=0;
	}
	else{
		rear++;
	}
	queue[rear]=n;
}

int del(){
	int value;
	if(front== -1  || front > rear){
		printf("underflow\n");
		return 0;
	}
	else{
		value = queue[front];
		front++;
			if(front>rear){
				front = rear = -1;
			}
			return value;
	}

}

int peek(){
	int value;
	if(front == -1 || front > rear){
		printf("underflow\n");
	}
	else{
		value=queue[front];
		return value;
	}
}

void display(){
	int i;
	for(i=front;i<=rear;i++){
		printf("%d\t", queue[i]);
	}
}


