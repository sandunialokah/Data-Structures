#include<stdio.h>
#define MAX 5

int queue[MAX];
int front=-1;
int rear=-1;

void display();
void insertrear(int data);
void insertfront(int data);
void deleterear();
void deletefront();

int main(){
	insertfront(4);
	insertfront(5);
	insertfront(6);
	insertrear(7);
	insertrear(8);
	display();
	deletefront();
	deletefront();
	deleterear();
	deleterear();
	display();
	deleterear();
	display();
	deletefront();
}

void insertfront(int data){
	if((front==0 && rear==MAX-1) || (front==rear+1)){
		printf("\nQueue is full\n");
	}
	else if(front==-1 && rear==-1){
		front=rear=0;
		queue[front]=data;
	}
	else if(front==0){
		front=MAX-1;
		queue[front]=data;
	}
	else{
		front--;
		queue[front]=data;
	}
}

void insertrear(int data){
	if((front==0 && rear==MAX-1) || (front==rear+1)){
		printf("\nQueue is full\n");
	}
	else if(front==-1 && rear==MAX-1){
		front=rear=0;
		queue[rear]=data;
	}
	else if(rear==MAX-1){
		rear=0;
		queue[rear]=data;
	}
	else{
		rear++;
		queue[rear]=data;
	}
}

void display(){
	int i=front;
	while(i!=rear){
		printf("%d ", queue[i]);
		i=(i+1)%MAX;
	}
	printf("%d\n", queue[rear]);
}

void deletefront(){
	if(front==-1 && rear==-1){
		printf("\nQueue is empty\n");
	}
	else if(front==rear){
		front=rear=-1;
	}
	else if(front==MAX-1){
		front=0;
	}
	else{
		front++;
	}
}

void deleterear(){
	if(front==-1 && rear==-1){
		printf("\nQueue is empty\n");
	}
	else if(front==rear){
		front=rear=-1;
	}
	else if(rear==0){
		rear=MAX-1;
	}
	else{
		rear--;
	}
}


