#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* left;
    int data;
    struct node *right;
};

int preorder(struct node *start);
int postorder(struct node *start);
int inorder(struct node *start);
struct node *newnode(int val);
int size(struct node *start);
int max(int a, int b);
int height(struct node *start);

int main(){
    struct node* start=newnode(5);
    start->left=newnode(4);
    start->right=newnode(6);
    start->left->left=newnode(3);
    start->left->right=newnode(2);

    printf("\nPreorder traversal: \n");
    preorder(start);
    printf("\nPostorder traversal: \n");
    postorder(start);
    printf("\nInorder traversal: \n");
    inorder(start);
    printf("\nSize of tree is %d", size(start));
    printf("\nHeight of tree is %d", height(start));
    
}

struct node *newnode(int val){
    struct node *node=(struct node*)malloc(sizeof(struct node));
    node->data=val;
    node->left=NULL;
    node->right=NULL;
    return node;
}

int preorder(struct node *start){
    if(start==NULL){
        return 0;
    }
    printf("%d ", start->data);
    preorder(start->left);
    preorder(start->right);
    
}

int inorder(struct node *start){
    if(start==NULL){
        return 0;
    }
    inorder(start->left);
    printf("%d ", start->data);
    inorder(start->right);
}

int postorder(struct node *start){
    if(start==NULL){
        return 0;
    }
    postorder(start->left);
    postorder(start->right);
    printf("%d ", start->data);
}

int size(struct node *start){
    if(start!=NULL){
        return (size(start->left)+1+size(start->right));
    }
    else{
        return 0;
    }
    
}

int height(struct node *start){
    if(start!=NULL){
        return (1+max(height(start->left),height(start->right)));
    }
    else{
        return 0;
    }
}

int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}