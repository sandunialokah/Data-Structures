#include<iostream>
using namespace std;

struct node{
    int data;
    node *parent;
    node *left;
    node *right;
    int color;  // red -> 1 black -> 0
};

typedef node *nodePtr;  // pointer to the structure node

class redblackTree{
    nodePtr root;
    nodePtr TNULL;  // NIL node

    void leftRotate(nodePtr x){
        nodePtr y = x->right;
        x->right = y->left;
        if(y->left != TNULL){
            y->left->parent = x;
        }
        y->parent = x->parent;
        if(x->parent == nullptr){
            root = y;
        }
        else if(x == x->parent->left){
            x->parent->left = y;
        }
        else{
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(nodePtr x){
        nodePtr y = x->left;
        x->left = y->right;
        if(y->right != TNULL){
            y->right->parent = x;
        }
        y->parent = x->parent;
        if(x->parent == nullptr){
            root = y;
        }
        else if(x == x->parent->left){
            x->parent->left = y;
        }
        else{
            x->parent->right = y;
        }
        y->right = x;
        x->parent = y;
    }

    nodePtr grand_parent(nodePtr x){
        if(x !=nullptr && x->parent != nullptr){
            return x->parent->parent;
        }
        else{
            return NULL;
        }
    }

    nodePtr uncle(nodePtr x){
        nodePtr g;
        g = grand_parent(x);
        if(g == nullptr){
            return NULL;
        }
        if(x->parent == g->left){
            return g->right;
        }
        else{
            return g->left;
        }
    }

    void fixInsert(nodePtr x){
        nodePtr u;
        while(x->parent->color == 1){
            // if parent is the right child of grandparent
            if(x->parent == x->parent->parent->right){
                u = x->parent->parent->left;  // uncle
                // if uncle is red and parent is red
                if(u->color == 1){
                    u->color = 0;  // uncles color is changed to black
                    x->parent->color = 0;  // parents color is changed to black
                    x->parent->parent->color = 1;  // grandparent color s changed to red
                    x = x->parent->parent;  // grandparent is updated to be current node
                }
                //if uncle is black and parent is red
                else{
                    // if it is left child right rotation is done 
                    if(x == x->parent->left){
                        x = x->parent;
                        rightRotate(x);
                    }
                    // now it is the right child
                    // color of parent and grandparent is swapped
                     //left rotation is done
                    x->parent = 0;
                    x->parent->parent->color = 1;
                    leftRotate(x->parent->parent);
                }
            }
             // if parent is the left child of grandparent
            else{
                u = x->parent->parent->right; // uncle
                if(u->color == 1){
                    u->color = 0;
                    x->parent->color = 0;
                    x->parent->parent->color = 1;
                    x = x->parent->parent;
                }
                else{
                        if(x == x->parent->right){
                            x = x->parent;
                            leftRotate(x);
                        }
                        x->parent->color = 0;
                        x->parent->parent->color = 1;
                        rightRotate(x->parent->parent);
                }
            }
            if(x == root){
                break;
            }
        }
        root->color = 0;
    }

    void fixDelete(nodePtr x){
        nodePtr s; // sibling of x
        while(x != root && x->color == 0){
            if(x == x->parent->left){
                s = x->parent->right;
                // if sibling red
                if(s->color == 1){
                    s->color = 0;
                    x->parent->color = 1;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }
                // if sibling is black and  both children of sibling is black
                if(s->left->color == 0 && s->right->color == 0){
                    s->color =1;
                    x = x->parent;
                }
                else{
                    // if sibling is black and right child is black and left child is red
                    if(s->right->color = 0){
                        s->left->color =0;
                        s->color = 1;
                        rightRotate(s);
                        s = x->parent->right;
                    }
                    // if sibling is black and right child is red
                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->right->color = 0;
                    leftRotate(x->parent);
                    x = root;
                } 
            }
            else{
                s = x->parent->left;
                if(s->color == 1){
                    s->color = 0;
                    x->parent->color = 1;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }
                if(s->right->color == 0 && s->left->color == 0){
                    s->color = 1;
                    x = x->parent;
                }
                else{
                    if(s->left->color = 0){
                        s->right->color = 0;
                        s->color = 1;
                        leftRotate(s);
                        s = x->parent->left;
                    }
                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->left->color = 0;
                    rightRotate(x->parent);
                    x = root;
                }
            }
            x->color = 0;
        }
    }


    void rbswap(nodePtr u, nodePtr v){
        if(u->parent == nullptr){
            root = v;
        }
        else if(u == u->parent->left){
            u->parent->left = v;
        }
        else{
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    // finding the minimum node in the left subtree of a node
    nodePtr minimum(nodePtr x){
        while (x->left != TNULL)
        {
            x = x->left;
        }
        return x;
    }

    void deleteHelp(nodePtr node, int key){
        nodePtr z = TNULL;
        nodePtr x, y;
        // finding the node that should be deleted
        while (node != TNULL)
        {
            if(node->data == key){
                z = node;
            }
            if(node->data <= key){
                node = node->right;
            }
            else{
                node = node->left;
            }
        }

        // if node to be deleted is not found
        if(z == TNULL){
            cout << "Couldn't find key in the tree" << endl;
            return;
        }
        
        y = z;
        int y_original_color = y->color;
        // fix right child to the deleting node's place
        if(z->left == TNULL){
            x = z->right;
            rbswap(z, z->right);
        }
         // fix left child to the deleting node's place
        else if(z->right == TNULL){
            x = z->left;
            rbswap(z, z->left);
        }
        else{
            y = minimum(z->right);  // node that replaces the deleting node
            y_original_color = y->color;
            x = y->right;
            if(y->parent == z){
                x->parent= y;
            }
            else{
                rbswap(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            rbswap(z,y);
            y->left = z->left;
            y->left->parent =y;
            y->color = z->color;
        }
        delete z;
        if(y_original_color == 0){
            fixDelete(x);
        }
    }

     nodePtr searchNodeHelp(nodePtr node, int key){
            if(node == TNULL || node->data == key){
                return node;
            }
            else if(key < node->data){
                return searchNodeHelp(node->left, key);
            }
            return searchNodeHelp(node->right, key);
        }

    void printHelp(nodePtr root, string indent, bool last){
        if(root != TNULL){
            cout << indent;
            if(last){
                cout << "R----";
                indent +="    ";
            }
            else{
                cout << "L----";
                indent += "    ";
            }
            string rb = root->color?"RED":"BLACK";
            cout << root->data << "(" << rb << ")" << endl;
            printHelp(root->left, indent, false);
            printHelp(root->right, indent, true);
        }
    }

    public:
        //constructor
        redblackTree(){
            TNULL = new node;
            TNULL->color = 0;
            TNULL->left = nullptr;
            TNULL->right = nullptr;
            root = TNULL;
        }

        // insert into the tree at the appropriate position
        void insert(int key){
            nodePtr newnode = new node;  // dynamically allocate memory for newnode
            newnode->parent = nullptr;
            newnode->data = key;
            newnode->left = TNULL;
            newnode->right = TNULL;
            newnode->color = 1; // new node should be red

            nodePtr y =nullptr;
            nodePtr x = this->root;

            // finding parent of new node
            while(x!=TNULL){
                y = x;  
                if(newnode->data < x->data){
                    x = x->left;
                }
                else{
                    x = x->right;
                }
            }

            newnode->parent = y; // y is parent of new node
            
            if(y==nullptr){
                root = newnode;
            }
            else if(newnode->data < y->data){
                y->left = newnode;
            }
            else{
                y->right = newnode;
            }

            // if newnode is root change color to black and return
            if(newnode->parent == nullptr){
                newnode->color = 0;
                return;
            }

            // if parent of newnode is root return
            if(newnode->parent->parent == nullptr){
                return;
            }
            fixInsert(newnode);
        }


        void deleteNode(int key){
            deleteHelp(this->root, key);
        }

       void serchNode(int key){
           nodePtr node;
           node = searchNodeHelp(this->root, key);
           if(node == TNULL){
               cout << "The searched node is not found in the tree" << endl;
           }
           else{
               cout << "The node is in the tree" << endl;
           }

       }

        void print(){
            if(root){
                printHelp(this->root, "", true);
            }
            cout << "\n";
        }
};

int main(){
    redblackTree tree;
    int option, key;
    do{
        cout << "\n1)insert" << endl;
        cout << "2)delete" << endl;
        cout << "3)display" << endl;
        cout << "4)search" << endl;
        cout << "5)exit" << endl;
        cout << "Enter the option: ";
        cin >> option;
        switch(option){
            case 1:
                cout << "\nEnter the value of the node that need to be inserted: ";
                cin >> key;
                tree.insert(key);
                break;
            case 2:
                cout << "\nEnter the value of the node that need to be deleted: ";
                cin >> key;
                tree.deleteNode(key);
                break;
            case 3:
                 tree.print();
                 break;
            case 4:
                cout << "\nEnter the value of the node that need to be searched: ";
                cin >> key;
                tree.serchNode(key);
                break;
        }
    }while(option != 5);
}