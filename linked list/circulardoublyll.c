#include<stdio.h>
#include<stdlib.h>

struct node *start=NULL;
struct node *create_ll();
struct node *display();
struct node *insertbeg();
struct node *insertend();
struct node *delbeg();
struct node *delend();
struct node *del_node();
struct node *del_list();

struct node{
	struct node *prev;
	int data;
	struct node *next;
};

int main(){
	int option;
	do{
		printf("\n***********MAIN MENU**************\n");
		printf("1)create link list\n");
		printf("2)insert beginig\n");
		printf("3)insert end\n");
		printf("4)delete begining\n");
		printf("5)delete end\n");
		printf("6)delete node\n");
		printf("7)display\n");
		printf("8)delete list\n");
		printf("9)exit\n");
		printf("Enter option: ");
		scanf("%d", &option);
		switch(option){
			case 1:
				start=create_ll();
				break;
			case 2:
				start=insertbeg();
				break;
			case 3:
				start=insertend();
				break;
			case 4:
				start=delbeg();
				break;
			case 5:
				start=delend();
				break;
			case 6:
				start=del_node();
				break;
			case 7:
				start=display();
				break;
			case 8:
				start=del_list();
				break;	
		}
	}while(option!=9);
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
			new_node->prev=NULL;
			new_node->next=new_node;
			start=new_node;
		}
		else{
			ptr=start;
			while(ptr->next!=start){
				ptr=ptr->next;
			}
			new_node->prev=ptr;
			ptr->next=new_node;
			new_node->next=start;
			start->prev=new_node;
			
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
	new_node->prev=ptr;
	new_node->next=start;
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
	while(ptr->next!=start){
		ptr=ptr->next;
	}
	ptr->next=new_node;
	new_node->next=start;
	new_node->prev=ptr;
	start->prev=new_node;
	return start;
}

struct node *delbeg(){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start){
		ptr=ptr->next;
	}
	ptr->next=start->next;
	start->next->prev=ptr;
	free(start);
	start=ptr->next;
	return start;
}

struct node *delend(){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start){
		ptr=ptr->next;
	}
	ptr->prev->next=start;
	start->prev=ptr->prev;
	free(ptr);
	return start;
}

struct node *del_node(){
	struct node *ptr;
	int val;
	printf("Enter the value of the node that should be deleted: ");
	scanf("%d", &val);
	ptr=start;
	if(ptr->data==val){
		start=delbeg();
		return start;
	}
	else{
		while(ptr->data!=val){
			ptr=ptr->next;
		}
		ptr->prev->next=ptr->next;
		ptr->next->prev=ptr->prev;
		free(ptr);
		return start;
	}
}

struct node *del_list(){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start){
		start=delbeg();
		ptr=ptr->next;
	}
	free(start);
	return start;
}
