#include<iostream>
using namespace std;

struct node{
    int key;
    node *left;
    node *right;
    int height;
};

typedef node *nodePtr;


// creating newnode
nodePtr newnode(int key){
    nodePtr newnode = new node;
    newnode->key = key;
    newnode->left = nullptr;
    newnode->right =nullptr;
    newnode->height = 1;
    return newnode;
}

int max(int a, int b){
    return (a>b) ? a:b;
}

int height(nodePtr x){
    if(x == nullptr){
        return 0;
    }
    return x->height;
}
nodePtr rightRotate(nodePtr y){
    nodePtr x = y->left;
    nodePtr z = x->right;
    x->right = y;
    y->left = z;
    y->height = max(height(y->left) , height(y->right)) + 1;
    x->height = max(height(x->left) , height(x->right)) + 1;
    return x;
}

nodePtr leftRotate(nodePtr y){
    nodePtr x = y->right;
    nodePtr z = x->left;
    x->left = y;
    y->right = z;
    y->height = max(height(y->left) , height(y->right)) + 1;
    x->height = max(height(x->left) , height(x->right)) + 1;
    return x;
}

int balanceFactor(nodePtr x){
    if(x == nullptr){
        return 0;
    }
    return height(x->left) - height(x->right);
}

nodePtr insertNode(nodePtr node, int key){
    if(node == nullptr){
        return newnode(key);
    }
    if(key < node->key){
        node->left = insertNode(node->left, key);
    }
    else if(key > node->key){
            node->right = insertNode(node->right, key);
    }
    else{
        return node;
    }
    node->height = max(height(node->left) , height(node->right)) + 1;
    int balanceFac = balanceFactor(node);
    if(balanceFac > 1){
        if(key < node->left->key){
            return rightRotate(node);
        }
        else if(key > node->left->key){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if(balanceFac < -1){
        if(key > node->right->key){
            return leftRotate(node);
        }
        else if(key > node->right->key){
            node->right = rightRotate(node->right);
            return node->left;
        }
    }
    return node;
}

nodePtr minNode(nodePtr node){
    nodePtr current = node;
    while(current->left != nullptr){
        current = current->left;
    }
    return current;
}


nodePtr deleteNode(nodePtr root, int key){
    if(root == nullptr){
        return root;
    }
    if(key < root->key){
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->key){
        root->right = deleteNode(root->right, key);
    }
    else{
        if(root->left == nullptr || root->right == nullptr){
            nodePtr temp = root->left ? root->left: root->right;
            if(temp == nullptr){
                temp = root;
                root = nullptr;
            }
            else{
                *root = *temp;
            }
            free(temp);
        }
        else{
            nodePtr temp = minNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if(root == nullptr){
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balanceFac = balanceFactor(root);
    if(balanceFac > 1){
        if(balanceFactor(root->left) >= 0){
            return rightRotate(root);
        }
        else{
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    if(balanceFac < -1){
        if(balanceFactor(root->right) <= 0){
            return leftRotate(root);
        }
        else{
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    return root;
}

void printHelp(nodePtr root, string indent, bool last){
    if(root != nullptr){
        cout << indent;
        if(last){
            cout << "R----";
            indent += "    ";
        }
        else{
            cout << "L----";
           indent += "    ";
        }
        cout << root->key << endl;
        printHelp(root->left, indent, false);
        printHelp(root->right, indent, true);
    }
}


nodePtr searchHelp(nodePtr node, int key){
    if(node == nullptr || node->key == key){
        return node;
    }
    else if(key < node->key){
        return searchHelp(node->left, key);
    }
    return searchHelp(node->right, key);
}

void searchNode(nodePtr root, int key){
    nodePtr x;
    x = searchHelp(root, key);
    if(x == nullptr){
        cout << "The node searched is not found in the tree" << endl;
    }
    else{
        cout << "The node is in the tree" << endl;
    }

}

void printTree(nodePtr root, string indent, bool last){
    cout << "\n" << endl;
    printHelp(root,indent,last);
    cout << "\n" << endl;
}


int main(){
    nodePtr root = NULL;

    int option, key;
    do{
        cout << "\n1)insert node" << endl;
        cout << "2)delete node" << endl;
        cout << "3)dispaly" << endl;
        cout << "4)search node" << endl;
        cout << "5)exit" << endl;
        cout << "Enter the option: ";
        cin >> option;
        switch(option){
            case 1:
                cout << "\nEnter value of node to be inserted: ";
                cin >> key;
                root = insertNode(root,key);
                break;
            case 2:
                cout << "\nEnter value of node to be deleted: ";
                cin >> key;
                root = deleteNode(root, key);
                break;
            case 3:
                printTree(root, "", true);
                break;
            case 4:
                cout << "\nEnter value of node to be searched: ";
                cin >> key;
                searchNode(root, key);
                break;
        }
    }while(option!=5);
}



