#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data, size;
    Node *left, *right;

    Node(int val){
        data= val;
        size=1;
        left= right= NULL;
    }
};

void update_size(Node* root){
    if(root){
        int left_size= (root->left) ? root->left->size: 0;
        int right_size= (root->right) ? root->right->size: 0;
        root->size= left_size+ right_size+1;
    }
}

Node* insert(Node* root, int key){
    if(root== NULL){
        root= new Node(key);
        return root;
    }
    else if(key< root->data){
        root->left= insert(root->left, key);
    }
    else{
        root->right= insert(root->right, key);
    }
    update_size(root);
    return root;
}

int find_rank(Node* root, int key){
    if(!root){
        return -1;
    }
    int left_size= (root->left) ? root->left->size: 0;
    if(key== root->data){
        return left_size+1;
    }
    else if(key< root->data){
        return find_rank(root->left, key);
    }
    else{
        int right_rank= find_rank(root->right, key);
        if(right_rank== -1){
            return -1;
        }
        return left_size+1+ right_rank;
    }
}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    Node* root= NULL;
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        root= insert(root, x);
    }
    int x;
    cout<<"Enter the element to find rank: ";
    cin>>x;
    int rank= find_rank(root, x);
    if(rank==-1){
        cout<<"Element Not found!\n";
    }
    else{
        cout<<rank<<"\n";
    }
    return 0;
}
