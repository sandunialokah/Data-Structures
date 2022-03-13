#include<stdio.h>
#define MAX 3

int queue[MAX];
int front=0; 
int count=0; 
int rear=0;

void display();
void del();
void insert();

int main(){
	int option;
	do{
		printf("\noperations are:\n1)insert\n2)delete\n3)display\n4)exit\n Enter your choice: ");
		scanf("%d", &option);
		switch(option){
			case 1:
				insert();
				break;
			case 2:
				del();
				break;
			case 3:
				display();
				break;
		}
	}while(option!=4);
	return 0;
}

void insert(){
	int n;
	if(count==MAX){
		printf("overflow\n");
	}
	else{
		printf("Enter the element to be inserted: ");
		scanf("%d", &n);
		queue[rear]=n;
		rear=(rear+1)%MAX;
		count++;
	}
}

void del(){
	int val;
	if(count==0){
		printf("underflow\n");		
	}
	else{
		val=queue[front];
		front=(front+1)%MAX;
		count--;
		printf("The element deleted is: %d", val);
	}
}

void display(){
	if(count==0){
		printf("queue is empty\n");
	}
	else{
		int i, j;
		j=count;
		for(i=front;j!=0;j--){
			printf("%d\t", queue[i]);
			i=(i+1)%MAX;
		}
	}
}
