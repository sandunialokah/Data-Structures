#include<stdio.h>
#include<stdlib.h>

struct node *start=NULL;
struct node *create_ll();
struct node *display();

struct node{
	int data;
	struct node *next;
};

int main(){
	int option;
	do{
		printf("\n**********MAIN MENU**********\n");
		printf("1)create linked list\n");
		printf("2)display\n");
		printf("3)exit\n");
		printf("Enter option: ");
		scanf("%d", &option);
		switch(option){
			case 1:
				start=create_ll();
				break;
			case 2:
				start=display();
				break;
		}
	}while(option!=3);
}

struct node *create_ll(){
	struct node *new_node, *ptr;
	int num;
	printf("Enter -1 to exit\n");
	printf("Enter data: ");
	scanf("%d", &num);
	while(num!=-1){
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=num;
		new_node->next=NULL;
		if(start==NULL){
			start=(struct node*)malloc(sizeof(struct node));
			start->next=new_node;
		}
		else{
			ptr=start;
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			ptr->next=new_node;
		}
		printf("Enter data: ");
		scanf("%d", &num);
	}
	return start;
}

struct node *display(){
	struct node *ptr;
	ptr=start->next;
	while(ptr!=NULL){
		printf("%d ", ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
	return start;
}
