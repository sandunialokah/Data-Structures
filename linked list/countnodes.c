#include<stdio.h>
#include<stdlib.h>

struct node *start=NULL;
struct node *create_ll();

struct node{
	int data;
	struct node *next;
};

int main(){
	struct node *ptr;
	int count=0;
	start=create_ll();
	ptr=start;
	while(ptr!=NULL){
		count++;
		ptr=ptr->next;
	}
	printf("The number of nodes in the linked list is: %d", count);
}

struct node *create_ll(){
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
