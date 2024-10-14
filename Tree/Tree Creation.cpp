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
void display(Tnode* root){
    if(root != NULL){
        cout<<root ->data<<" ";
        display(root ->left);
        display(root ->right);
    }
}
int main(){
    Tnode *root= NULL;
    root= create();
    display(root);
}
