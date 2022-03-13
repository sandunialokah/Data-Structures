#include<stdio.h>
#include<stdlib.h>

struct node *start=NULL;
struct node *createcll();
struct node *display();
struct node *insertbeg();
struct node *insertend();
struct node *delbeg();
struct node *delend();
struct node *delafter();
struct node *sort_list();

struct node{
	int data;
	struct node *next;
};

int main(){
	int option;
	do{
		printf("\n****************MAIN MENU************\n");
		printf("1)create a list\n");
		printf("2)display a list\n");
		printf("3)insert a node at beginig\n");
		printf("4)insert a node at end\n");
		printf("5)delete a node at beginig\n");
		printf("6)delete a node at end\n");
		printf("7)delete a node after a given node\n");
		printf("8)exit\n");
		printf("Enter option: ");
		scanf("%d", &option);
		switch(option){
			case 1:
				start=createcll();
				break;
			case 2:
				start=display();
				break;
			case 3:
				start=insertbeg();
				break;
			case 4:
				start=insertend();
				break;
			case 5:
				start=delbeg();
				break;
			case 6:
				start=delend();
				break;
			case 7:
				start=delafter();
				break;
		}
	}while(option!=8);	
}

struct node *createcll(){
	struct node *new_node, *ptr;
	int num;
	printf("Enter -1 to exit\n");
	printf("Enter data: ");
	scanf("%d", &num);
	while(num!=-1){
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=num;
		if(start==NULL){
			new_node->next=new_node;
			start=new_node;
		}
		else{
			ptr=start;
			while(ptr->next!=start){
				ptr=ptr->next;
			}
			ptr->next=new_node;
			new_node->next=start;
		}
		printf("Enter data: ");
		scanf("%d", &num);
	}
	return start;
}

struct node *display(){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start){
		printf("%d ", ptr->data);
		ptr=ptr->next;
	}
	printf("%d\n", ptr->data);
	return start;
}

struct node *insertbeg(){
	struct node *new_node, *ptr;
	int num;
	printf("Enter data: ");
	scanf("%d", &num);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->next!=start){
		ptr=ptr->next;
	}
	ptr->next=new_node;
	new_node->next=start;
	start=new_node;
	return start;
}

struct node *insertend(){
	struct node *new_node, *ptr;
	int num;
	printf("Enter data: ");
	scanf("%d", &num);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->next!=start){
		ptr=ptr->next;
	}
	ptr->next=new_node;
	new_node->next=start;
	return start;
}

struct node *delbeg(){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start){
		ptr=ptr->next;
	}
	ptr->next=start->next;
	free(start);
	start=ptr->next;
	return start;
}

struct node *delend(){
	struct node *ptr, *preptr;
	ptr=start;
	while(ptr->next!=start){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=start;
	free(ptr);
	return start;
}

struct node *delafter(){
	struct node *ptr, *preptr;
	int val;
	printf("Enter the value after which the node should be deleted: ");
	scanf("%d", &val);
	ptr=start;
	preptr=ptr;
	while(preptr->data!=val){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}


