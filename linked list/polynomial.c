#include<stdio.h>
#include<stdlib.h>

struct node{
	int coeff;
	int power;
	struct node *next;
};
struct node *start1=NULL;
struct node *start2=NULL;
struct node *start3=NULL;
struct node *start4=NULL;
struct node *create_poly(struct node *start);
struct node *display(struct node *start);
struct node *add_node(struct node *start, int n, int c);
struct node *add_poly(struct node *start1, struct node *start2);
struct node *sub_poly(struct node *start1, struct node *start2);

int main(){
	int option;
	do{
		printf("\n***********MAIN MENU***********\n");
		printf("1)create the first polynomial\n");
		printf("2)display\n");
		printf("3)create the second polynomial\n");
		printf("4)display\n");
		printf("5)add polynomials\n");
		printf("6)display the result\n");
		printf("7)subtract polynomials\n");
		printf("8)display the result\n");
		printf("9)exit\n");
		printf("Enter the option: ");
		scanf("%d", &option);
		switch(option){
			case 1:
				start1=create_poly(start1);
				break;
			case 2:
				start1=display(start1);
				break;
			case 3:
				start2=create_poly(start2);
				break;
			case 4:
				start2=display(start2);
				break;
			case 5:
				start3=add_poly(start1,start2);
				break;
			case 6:
				start3=display(start3);
				break;
			case 7:
				start4=sub_poly(start1,start2);
				break;
			case 8:
				start4=display(start4);
				break;
		}
	}while(option!=9);
}

struct node *create_poly(struct node *start){
	struct node *new_node, *ptr;
	int n, c;
	printf("Enter coefficeient: ");
	scanf("%d", &c);
	printf("Enter power: ");
	scanf("%d", &n);
	while(c!=-1){
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->coeff=c;
		new_node->power=n;
		if(start==NULL){
			start=new_node;
			new_node->next=NULL;
		}
		else{
			ptr=start;
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			ptr->next=new_node;
			new_node->next=NULL;
		}
		printf("Enter coefficient: ");
		scanf("%d", &c);
		if(c==-1){
			break;
		}
		printf("Enter power: ");
		scanf("%d", &n);
	}
	return start;
}

struct node *display(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL){
		printf("%d x %d\t", ptr->coeff, ptr->power);
		ptr=ptr->next;
	}
	printf("\n");
	return start;
}

struct node *add_node(struct node *start, int c, int n){
	struct node *ptr, *new_node;
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->coeff=c;
	new_node->power=n;
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
	return start;
}

struct node *add_poly(struct node *start1, struct node *start2){
	struct node *ptr1, *ptr2;
	int sum;
	ptr1=start1; ptr2=start2;
	while(ptr1!=NULL && ptr2!=NULL){
		if(ptr1->power == ptr2->power){
			sum=ptr1->coeff + ptr2->coeff;
			start3=add_node(start3, sum, ptr1->power);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->power > ptr2->power){
			start3=add_node(start3, ptr1->coeff, ptr1->power);
			ptr1=ptr1->next;
		}
		else if(ptr2->power > ptr1->power){
			start3=add_node(start3, ptr2->coeff, ptr2->power);
			ptr2=ptr2->next;
		}
	}
	if(ptr1==NULL){
		while(ptr2!=NULL){
			start3=add_node(start3, ptr2->coeff, ptr2->power);
			ptr2=ptr2->next;
		}
	}
	if(ptr2==NULL){
		while(ptr1!=NULL){
			start3=add_node(start3, ptr1->coeff, ptr1->power);
			ptr1=ptr1->next;
		}
	}
	return start3;
}

struct node *sub_poly(struct node *start1, struct node *start2){
	struct node *ptr1, *ptr2;
	int diff;
	ptr1=start1; ptr2=start2;
	while(ptr1!=NULL && ptr2!=NULL){
		if(ptr1->power==ptr2->power){
			diff=ptr1->coeff-ptr2->coeff;
			start4=add_node(start4, diff, ptr1->power);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->power > ptr2->power){
			start4=add_node(start4, ptr1->coeff, ptr1->power);
			ptr1=ptr1->next;
		}
		else if(ptr2->power > ptr1->power){
			start4=add_node(start4, ptr2->coeff, ptr2->power);
			ptr2=ptr2->next;
		}
	}
	if(ptr1==NULL){
		while(ptr2!=NULL){
			start4=add_node(start4, ptr2->coeff, ptr2->power);
			ptr2=ptr2->next;
		}
	}
	if(ptr2==NULL){
		while(ptr1!=NULL){
			start4=add_node(start4, ptr1->coeff, ptr1->power);
			ptr1=ptr1->next;
		}
	}
	return start4;
}

