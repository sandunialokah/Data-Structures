#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode(int val);
struct node *insert(struct node *start, int val);
int inorder(struct node *start);
struct node* min_node(struct node *start);
struct node* max_node(struct node *start);
struct node *delete(struct node *start, int val);
struct node * min_recurse(struct node *start);
struct node *max_recurse(struct node *start);
void mirror(struct node *start);
void balance(struct node *start);
void rotate_right(struct node *start);
void create_backbone(struct node *start);

int main(){
    int n, val, option;
    struct node *start=NULL;
    struct node *temp;
   
    do{
        printf("\n1)Insert node\n");
        printf("2)Delete node\n");
        printf("3)Traversal\n");
        printf("4)Find minimum\n");
        printf("5)Find maximum\n");
        printf("6)Find minimum(recursive)\n");
        printf("7)Find maximum(recursive)\n");
        printf("8)Mirror image\n");
        printf("9)BSW\n");
        printf("10)Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("\nEnter node to insert: ");
                scanf("%d", &val);
                start = insert(start, val);
                break;
            case 2:
                printf("\nEnter node to delete: ");
                scanf("%d", &val);
                start = delete(start, val);
                break;
            case 3:
                printf("\nTraversal: ");
                inorder(start);
                break;
            case 4:
                temp = min_node(start);
                printf("\nMinimum node data is: %d", temp->data);
                break;
            case 5:
                temp = max_node(start);
                printf("\nMaximum node data is: %d", temp->data);
                break;
            case 6:
                temp = min_recurse(start);
                printf("\nMinimum node data is: %d", temp->data);
                break;
            case 7:
                temp = max_recurse(start);
                printf("\nMaximum node data is: %d", temp->data);
                break;
            case 8:
                mirror(start);
                break;
            case 9:
                //rotate_right(start);
                create_backbone(start);
                balance(start);
                break;
        }
    }while(option!=10);
}

struct node *newnode(int val){
    struct node *node=(struct node*)malloc(sizeof(struct node));
    node->data=val;
    node->left=NULL;
    node->right=NULL;
    return node;
}

int inorder(struct node *start){
    if(start==NULL){
        return 0;
    }
    inorder(start->left);
    printf("%d ", start->data);
    inorder(start->right);
}

struct node *insert(struct node *start, int val){
    if(start==NULL){
        return newnode(val);
    }
    if(val < start->data){
        start->left=insert(start->left,val);
    }
    else if(val>start->data){
        start->right=insert(start->right,val);
    }
    return start;
}

struct node *delete(struct node *start, int val){
    if(start==NULL){
        return start;
    }
    if(val > start->data){
        start->right = delete(start->right,val);
    }
    else if(val < start->data){
        start->left = delete(start->left,val);
    }
    else{
        if(start->left==NULL){
            struct node *temp=start->right;
            free(start);
            return temp;
        }
        else if(start->right==NULL){
            struct node *temp=start->left;
            free(start);
            return temp;
        }
        struct node *temp=min_node(start->right);
        start->data=temp->data;
        start->right=delete(start->right,temp->data);
    }
    return start;
}

struct node* min_node(struct node *start){
    struct node *current=start;
    while(current && current->left!=NULL){
        current=current->left;
    }
    return current;
}

struct node* max_node(struct node *start){
    struct node *current=start;
    while(current && current->right!=NULL){
        current=current->right;
    }
    return current;
}

struct node * min_recurse(struct node *start){
    if(start==NULL){
        return NULL;
    }
    else if(start->left==NULL){
        return start;
    }
    return min_recurse(start->left);
}

struct node *max_recurse(struct node *start){
    if(start==NULL){
        return NULL;
    }
    else if(start->right==NULL){
        return start;
    }
    return max_recurse(start->right);
}

void mirror(struct node *start){
    struct node *temp;
    while(start!=NULL){
        mirror(start->left);
        mirror(start->right);
        temp = start->left;
        start->left=start->right;
        start->right=temp;
    }
}

void rotate_right(struct node *start){
    if(start->left!=NULL){
        struct node *temp=start->left;
        start->left=temp->right;
        temp->right=start;
        start=temp;
    }
    else if(start->left!=NULL && start->right->left==NULL){
        struct node *flag=start;
        start=start->right;
        struct node *temp=start->left;
        start->left=temp->right;
        temp->right=start;
        flag->right=temp;
        start=flag->right;
    }
    else{
        start=start->right;
    }
    //return start;
}

void create_backbone(struct node *start){
    struct node *temp=start;
    while(temp!=NULL){
        rotate_right(temp);
    }
}

void balance(struct node *start){
    struct node *temp1=start;
    struct node *temp2=temp1->right->right;
    while(temp1!=NULL){
        if(temp2!=NULL && temp2->right!=NULL){
            temp1->right=temp1->right->left;
            temp1->right->left=temp1;
            temp1=temp1->right;
            temp1->right=temp1->right->right;
            temp2->right->left=temp2;
            temp2->right=NULL;
            temp2=temp1->right->right;
        }
        else{
            break;
        }
    }
}