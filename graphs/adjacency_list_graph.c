#include<stdio.h>
#include<stdlib.h>

struct node{
	int vertex;
	struct node *next;
};
void create_graph(struct node *adj[], int n);
void display_graph(struct node *adj[], int n);
void delete_graph(struct node *adj[], int n);

int main(){
	int n;
	printf("Enter the number of nodes in the graph: ");
	scanf("%d", &n);
	struct node *adj[n];
	for(int i=0;i<n;i++){
		adj[i]=NULL;
	}
	create_graph(adj,n);
	display_graph(adj,n);
	delete_graph(adj,n);
	display_graph(adj,n);
}

void create_graph(struct node *adj[], int n){
	int nodes, data;
	struct node *newnode, *last;
	for(int i=0;i<n;i++){
		last=NULL;
		printf("Enter the number of adjacnt nodes of %d: ", i+1);
		scanf("%d", &nodes);
		for(int j=0;j<nodes;j++){
			printf("Enter adjacent node %d of %d: ", j+1, i+1);
			scanf("%d", &data);
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->vertex=data;
			newnode->next=NULL;
			if(adj[i]==NULL){
				adj[i]=newnode;
			}
			else{
				last->next=newnode;
			}
			last=newnode;
		}
	}
}

void display_graph(struct node *adj[], int n){
	struct node *ptr;
	for(int i=0;i<n;i++){
		ptr=adj[i];
		printf("Neigbours of node %d: ", i+1);
		while(ptr!=NULL){
			printf("%d ", ptr->vertex);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

void delete_graph(struct node *adj[], int n){
	struct node *ptr, *temp;
	for(int i=0;i<n;i++){
		ptr=adj[i];
		while(ptr!=NULL){
			temp=ptr;
			ptr=ptr->next;
			free(ptr);
		}
		adj[i]=NULL;
	}
}