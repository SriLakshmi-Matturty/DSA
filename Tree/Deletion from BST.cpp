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

BSTnode* find_min(BSTnode* root){
    BSTnode* temp= root;
    if(root== NULL){
        return root;
    }
    while(temp->left != NULL){
        temp= temp->left;
    }
    return temp;
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

BSTnode* delete_node(BSTnode* &root, int key){
    BSTnode* temp;
    if(root== NULL){
        return root;
    }
    if(root->data> key){
        root->left= delete_node(root->left, key);
    }
    else if(root->data< key){
        root->right = delete_node(root->right, key);
    }
    else{
        if(root-> left== NULL){
            temp= root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            temp= root->left;
            delete root;
            return temp;
        }
        temp= find_min(root->right);
        root->data= temp->data;
        root->right= delete_node(root->right, temp->data);
    }
    return root;
}

int main(){
    BSTnode *root= NULL;
    root= create();
    cout<<"BST before insertion: ";
    inorder(root);
    cout<<"\n";
    int key;
    cout<<"Enter the value to delete: ";
    cin>>key;
    delete_node(root, key);
    cout<<"BST after deletion: ";
    inorder(root);
    cout<<"\n";
    return 0;
}
