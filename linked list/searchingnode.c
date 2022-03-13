#include<stdio.h>
#include<stdlib.h>

struct node *start=NULL;
struct node *createll();

struct node{
	int data;
	struct node *next;
};

int main(){
	struct node *ptr;
	int num;
	int flag=0;
	start=createll();
	
	ptr=start;
	printf("Enter the data to be searched: ");
	scanf("%d", &num);
	while(ptr!=NULL){
		if(ptr->data==num){
			flag=1;
			printf("%d is found.", num);
			return 0;
		}
		else{
			ptr=ptr->next;
		}
	}
	if(flag==0){
		printf("%d is not found.", num);
	}
	
}

struct node *createll(){
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
	return start;
}
