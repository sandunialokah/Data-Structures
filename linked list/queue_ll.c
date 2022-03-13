#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct queue{
	struct node *front;
	struct node *rear;
};

struct queue *q;
struct queue *create();
struct queue *enqueue();
struct queue *display();
struct queue *dequeue();
struct queue *peek();

int main(){
	int option;
	q=create();
	do{
		printf("\n***********MAIN MENU**********\n");
		printf("1)display\n");
		printf("2)enqueue\n");
		printf("3)dequeue\n");
		printf("4)peek\n");
		printf("5)exit\n");
		printf("Enter option: ");
		scanf("%d", &option);
		switch(option){
			case 1:
				q=display();
				break;
			case 2:
				q=enqueue();
				break;
			case 3:
				q=dequeue();
				break;
			case 4:
				q=peek();
				break;
		}
	}while(option!=5);
}

struct queue *create(){
	q=(struct queue*)malloc(sizeof(struct queue));
	q->rear=NULL;
	q->front=NULL;
	return q;
}

struct queue *enqueue(){
	struct node *new_node;
	int num;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d", &num);
	new_node->data=num;
	if(q->front==NULL){
		q->front=new_node;
		q->rear=new_node;
		q->front->next=q->rear->next=NULL;
	}
	else{
		q->rear->next=new_node;
		q->rear=new_node;
		q->rear->next=NULL;
	}
	return q;
}

struct queue *display(){
	struct node *ptr;
	ptr=q->front;
	if(ptr==NULL){
		printf("queue is empty\n");
	}
	else{
		while(ptr!=q->rear){
			printf("%d ", ptr->data);
			ptr=ptr->next;
		}	
		printf("%d\n", ptr->data);
	}
	return q;
}

struct queue *dequeue(){
	struct node *ptr;
	ptr=q->front;
	if(ptr==NULL){
		printf("underflow\n");
	}
	else{
		q->front=q->front->next;
		printf("The deleted value is: %d\n", ptr->data);
		free(ptr);
	}
	return q;
}

struct queue *peek(){
	if(q->front==NULL){
		printf("queue is empty\n");
	}
	else{
		printf("%d\n", q->front->data);
	}
	return q;
}
