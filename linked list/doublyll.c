#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;
};

struct node *start=NULL;
struct node *create_ll();
struct node *display();
struct node *insertbeg();
struct node *insertend();
struct node *insert_before();
struct node *insert_after();
struct node *delbeg();
struct node *delend();
struct node *delete_after();
struct node *delete_before();

int main(){
	int option;
	do{
		printf("\n*************MAIN MENU***********\n");
		printf("1)create linked list\n");
		printf("3)insert at the beginig of the linked list\n");
		printf("4)insert at the end of the linked list\n");
		printf("5)insert before\n");
		printf("6)insert after\n");
		printf("7)delete at the beginig of the linked list\n");
		printf("8)delete at the end of the linked list\n");
		printf("9)delete before\n");
		printf("10)delete after\n");
		printf("11)exit\n");
		printf("Enter option: ");
		scanf("%d", &option);
		switch(option){
			case 1:
				start=create_ll();
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
				start=insert_before();
				break;
			case 6:
				start=insert_after();
				break;
			case 7:
				start=delbeg();
				break;
			case 8:
				start=delend();
				break;
			case 9:
				start=delete_before();
				break;
			case 10:
				start=delete_after();
				break;
		}
	}while(option!=11);
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
		if(start==NULL){
			new_node->next=NULL;
			new_node->prev=NULL;
			start=new_node;
		}
		else{
			ptr=start;
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			new_node->next=NULL;
			new_node->prev=ptr;
			ptr->next=new_node;
		}
		printf("Enter data: ");
		scanf("%d", &num);
	}
	return start;
}

struct node *display(){
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL){
		printf("%d ", ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
	return start;
}

struct node *insertbeg(){
	struct node *new_node;
	int num;
	printf("Enter data: ");
	scanf("%d", &num);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=start;
	new_node->prev=NULL;
	start->prev=new_node;
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
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=new_node;
	new_node->next=NULL;
	new_node->prev=ptr;
	return start;
}

struct node *insert_before(){
	struct node *new_node, *ptr;
	int num, val;
	printf("Enter data: ");
	scanf("%d", &num);
	printf("Enter the value before which the node should be inserted: ");
	scanf("%d", &val);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->data!=val){
		ptr=ptr->next;
	} 
	new_node->next=ptr;
	new_node->prev=ptr->prev;
	ptr->prev->next=new_node;
	ptr->prev=new_node;
	return start;
}

struct node *insert_after(){
	struct node *new_node, *ptr;
	int num, val;
	printf("Enter data: ");
	scanf("%d", &num);
	printf("Enter the value after which the node should be entered: ");
	scanf("%d", &val);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->data!=val){
		ptr=ptr->next;
	}
	new_node->next=ptr->next;
	new_node->prev=ptr;
	ptr->next->prev=new_node;
	ptr->next=new_node;
	return start;
}

struct node *delbeg(){
	struct node *ptr;
	ptr=start;
	start=start->next;
	start->prev=NULL;
	free(ptr);
	return start;
}

struct node *delend(){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->prev->next=NULL;
	free(ptr);
	return start;
}

struct node *delete_after(){
	struct node *ptr, *temp;
	int val;
	printf("Enter value after which the node should be deleted: ");
	scanf("%d", &val);
	ptr=start;
	while(ptr->data!=val){
		ptr=ptr->next;
	}
	temp=ptr->next;
	ptr->next=temp->next;
	temp->next->prev=ptr;
	free(temp);
	return start;
}

struct node *delete_before(){
	struct node *ptr, *temp;;
	int val;
	printf("Enter the value before which the node should be deleted: ");
	scanf("%d", &val);
	ptr=start;
	while(ptr->data!=val){
		ptr=ptr->next;
	}
	temp=ptr->prev;
	if(temp==start){
		start=delbeg();
	}
	else{
		temp->prev->next=ptr;
		ptr->prev=temp->prev;
	}
	free(temp);
	return start;
}
