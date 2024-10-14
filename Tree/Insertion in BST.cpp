#include <bits/stdc++.h>
using namespace std;

class BSTnode{
    public:
        int data;
        BSTnode* left;
        BSTnode* right;

        BSTnode(int val){
            data=val;
            left= NULL;
            right= NULL;
        }
};

void inorder(BSTnode* root){
    if(root== NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

BSTnode* create(){
    BSTnode* new_node;
    int x;
    cout<<"Enter data (-1 for no node): ";
    cin>>x;
    if(x==-1){
        return NULL;
    }
    new_node= new BSTnode(x);
    cout<<"Enter left child of "<<x<<"\n";
    new_node->left= create();
    cout<<"Enter right child of "<<x<<"\n";
    new_node->right= create();
    return new_node;
}

BSTnode* insert(BSTnode* &root, int key){
    BSTnode* new_node= new BSTnode(key);
    if(root== NULL){
        root= new_node;
        return root;
    }
    BSTnode *prev, *temp= root;
    while(temp!= NULL){
        if(temp->data>key){
            prev= temp;
            temp= temp->left;
        }
        else if(temp->data <key){
            prev= temp;
            temp= temp->right;
        }
    }
    if(prev->data< key){
        prev->right= new_node;
    }
    else{
        prev->left= new_node;
    }
    return root;
}

void display(BSTnode* root){
    if(root != NULL){
        cout<<root->data<<" ";
        display(root->left);
        display(root->right);
    }
}

int main(){
    BSTnode *root= NULL;
    root= create();
    cout<<"BST before insertion: ";
    inorder(root);
    cout<<"\n";
    int key;
    cout<<"Enter the value to insert: ";
    cin>>key;
    insert(root, key);
    cout<<"BST after insertion: ";
    inorder(root);
    cout<<"\n";
    return 0;
}
