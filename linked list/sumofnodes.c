#include<stdio.h>
#include<stdlib.h>

struct node *start=NULL;
struct node *createll();

struct node{
	int data;
	struct node *next;
};

int main(){
	start=createll();
}

struct node *createll(){
	struct node *ptr, *new_node;
	int num;
	int count=0;
	printf("Enter -1 to exit.\n");
	printf("Enter data: ");
	scanf("%d", &num);
	while(num!=-1){
		count+=num;
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
		printf("Enter data: ");
		scanf("%d", &num);
	}
	printf("sum of nodes= %d", count);
	return start;
}
