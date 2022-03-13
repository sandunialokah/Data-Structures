#include<stdio.h>
#include<stdlib.h>

struct node *start=NULL;

struct node *createll();
struct node *display();
struct node *insert_beg();
struct node *insert_end();
struct node *insert_before();
struct node *insert_after();
struct node *delete_beg();
struct node *delete_end();
struct node *delete_node();
struct node *delete_after();
struct node *delete_list();
struct node *sort_list();

int main(){
	int option;
	do{
		printf("\n*******MAIN MENU**********\n");
		printf("1)create a list\n");
		printf("2)Display the list\n");
		printf("3)Add a node at the begining\n");
		printf("4)Add a node at the end\n");
		printf("5)Add a node before the given node\n");
		printf("6)Add a node after the given node\n");
		printf("7)Delete a node at the begining\n");
		printf("8)Delete a node at the end\n");
		printf("9)Delete a given node\n");
		printf("10)Delete a node after the given node\n");
		printf("11)Delete the entire list\n");
		printf("12)Sort the list\n");
		printf("13)Exit\n");
		printf("Enter your option: ");
		scanf("%d", &option);
		switch(option){
			case 1:
				start=createll();
				break;
			case 2:
				start=display();
				break;
			case 3:
				start=insert_beg();
				break;
			case 4:
				start=insert_end();
				break;
			case 5:
				start=insert_before();
				break;
			case 6:
				start=insert_after();
				break;
			case 7:
				start=delete_beg();
				break;
			case 8:
				start=delete_end();
				break;
			case 9:
				start=delete_node();
				break;
			case 10:
				start=delete_after();
				break;
			case 11:
				start=delete_list();
				break;
			case 12:
				start=sort_list();
				break;
		}
	}while(option!=13);
}

struct node{
	int data;
	struct node *next;
};

struct node *createll(){
	struct node *new_node, *ptr;
	int num;
	printf("Enter -1 to end\n");
	printf("Enter the data: ");
	scanf("%d", &num);
	while(num!=-1){
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=num;
		if(start==NULL){
			new_node->next=NULL;
			start=new_node;
		}
		else{
			ptr=start;
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			ptr->next=new_node;
			new_node->next=NULL;
		}
		printf("Enter the data: ");
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

struct node *insert_beg(){
	struct node *new_node;
	int num;
	printf("Enter the data: ");
	scanf("%d", &num);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=start;
	start=new_node;
	return start;
}

struct node *insert_end(){
	struct node *new_node, *ptr;
	int num;
	printf("Enter the data: ");
	scanf("%d", &num);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=NULL;
	ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=new_node;
	return start;
}

struct node *insert_before(){
	struct node *new_node, *ptr, *preptr;
	int num, val;
	printf("Enter the data: ");
	scanf("%d", &num);
	printf("Enter the value before which the data should be inserted: ");
	scanf("%d", &val);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->data!=val){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
	return start;
}

struct node *insert_after(){
	struct node *new_node, *ptr, *preptr;
	int num, val;
	printf("enter the data: ");
	scanf("%d", &num);
	printf("Enter the value after which the data should be entered: ");
	scanf("%d", &val);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	preptr=ptr;
	while(preptr->data!=val){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
	return start;
}

struct node *delete_beg(){
	struct node *ptr;
	ptr=start;
	start=start->next;
	free(ptr);
	return start;
}

struct node *delete_end(){
	struct node *ptr, *preptr;
	ptr=start;
	while(ptr->next!=NULL){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;
	free(ptr);
	return start;
}

struct node *delete_node(){
	struct node *ptr, *preptr;
	int val;
	printf("Enter the value of the node which has to deleted: ");
	scanf("%d", &val);
	ptr=start;
	if(ptr->data==val){
		start=delete_beg();
		return start;
	}
	else{
		while(ptr->data!=val){
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=ptr->next;
		free(ptr);
		return start;
	}
}

struct node *delete_after(){
	struct node *ptr, *preptr;
	int val;
	printf("Enter the value after which the node has to be deleted: ");
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

struct node *delete_list(){
	struct node *ptr;
	if(start!=NULL){
		ptr=start;
		while(ptr!=NULL){
			printf("%d is to be deleted next\n", ptr->data);
			start=delete_beg();
			ptr=start;
		}
	}
	return start;
}

struct node *sort_list(){
	struct node *ptr1, *ptr2;
	int temp;
	ptr1=start;
	while(ptr1->next!=NULL){
		ptr2=ptr1->next;
		while(ptr2!=NULL){
			if(ptr1->data>ptr2->data){
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
	return start;
}



