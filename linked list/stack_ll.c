#include<stdio.h>
#include<stdlib.h>

struct node *top=NULL;
struct node *push();
struct node *display();
struct node *pop();
struct node *peek();

struct node{
	int data;
	struct node *next;
};

int main(){
	int option;
	do{
		printf("\n********MAIN MENU*********\n");
		printf("1)display\n");
		printf("2)push\n");
		printf("3)pop\n");
		printf("4)peek\n");
		printf("5)exit\n");
		printf("Enter option: ");
		scanf("%d", &option);
		switch(option){
			case 1:
				top=display();
				break;
			case 2:
				top=push();
				break;
			case 3:
				top=pop();
				break;
			case 4:
				top=peek();
				break;
		}
	}while(option!=5);
}

struct node *push(){
	struct node *new_node;
	int num;
	printf("Enter data: ");
	scanf("%d", &num);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	if(top==NULL){
		top=new_node;
		new_node->next=NULL;
	}
	else{
		new_node->next=top;
		top=new_node;
	}
	return top;
}

struct node *display(){
	struct node *ptr;
	ptr=top;
	if(top==NULL){
		printf("Stack is empty\n");
	}
	else{
		while(ptr!=NULL){
		printf("%d ", ptr->data);
		ptr=ptr->next;
		}
	}
	printf("\n");
	return top;
}

struct node *pop(){
	struct node *ptr;
	ptr=top;
	if(top==NULL){
		printf("Stack underflow\n");
	}
	else{
		top=ptr->next;
		free(ptr);
	}
	return top;
}

struct node *peek(){
	if(top==NULL){
		printf("stack is empty\n");
	}
	else{
		printf("%d\n", top->data);
	}
	return top;
}

