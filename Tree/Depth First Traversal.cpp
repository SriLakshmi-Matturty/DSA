#include <bits/stdc++.h>
using namespace std;

class Tnode{
    public:
        int data;
        Tnode* left;
        Tnode* right;

        Tnode(int val){
            data=val;
            left= NULL;
            right= NULL;
        }
};

Tnode* create(){
    Tnode* new_node;
    int x;
    cout<<"Enter data (-1 for no node): ";
    cin>>x;
    if(x==-1){
        return NULL;
    }
    new_node= new Tnode(x);
    cout<<"Enter left child of "<<x<<"\n";
    new_node->left= create();
    cout<<"Enter right child of "<<x<<"\n";
    new_node->right= create();
    return new_node;
}

void preorder(Tnode* root){
    if(root== NULL){
        return;
    }
    cout<<root->data<<" ";
    P_preorder(root->left);
    P_preorder(root->right);
}

void nr_preorder(Tnode* root){
    if(root== NULL){
        return;
    }
    stack <Tnode*> s;
    s.push(root);
    while(!s.empty()){
        Tnode* temp= s.top();
        cout<<temp->data<<" ";
        s.pop();
        if(temp->right!= NULL){
            s.push(temp->right);
        }
        if(temp->left!= NULL){
            s.push(temp->left);
        }
    }
}

void postorder(Tnode* root){
    if(root== NULL){
        return;
    }
    P_postorder(root->left);
    P_postorder(root->right);
    cout<<root->data<<" ";
}

void inorder(Tnode* root){
    if(root== NULL){
        return;
    }
    P_inorder(root->left);
    cout<<root->data<<" ";
    P_inorder(root->right);
}
int main(){
    Tnode *root= NULL;
    root= create();
    cout<<"Preorder: ";
    preorder(root);
    cout<<"\n";
    cout<<"Postorder: ";
    postorder(root);
    cout<<"\n";
    cout<<"Inorder: ";
    inorder(root);
    cout<<"\n";
}
