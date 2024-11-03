#include <bits/stdc++.h>
using namespace std;

class AVLTree{
    public:
        int key;
        AVLTree *left, *right;
        int height;

        AVLTree(int val){
            key=val;
            left= NULL;
            right= NULL;
            height=1;
        }
};

int height(AVLTree* node){
    if(node== NULL){
        return 0;
    }
    return node->height;
}

AVLTree* right_rotation(AVLTree* &y){
    AVLTree *x= y->left;
    AVLTree *T2= x->right;

    x->right= y;
    y->left= T2;

    x->height= 1+max(height(x->left), height(x->right));
    y->height= 1+max(height(y->left), height(y->right));

    return x;
}

AVLTree* left_rotation(AVLTree* x){
    AVLTree* y= x->right;
    AVLTree* T1= y->left;

    y->left=x;
    x->right=T1;

    x->height= 1+max(height(x->left), height(x->right));
    y->height= 1+max(height(y->left), height(y->right));

    return y;
}

int balance_factor(AVLTree *node){
    if(node== NULL){
        return 0;
    }
    return (height(node->left)- height(node->right));
}

AVLTree* insert(AVLTree* node, int val){
    if(node== NULL){
        return new AVLTree(val);
    }
    if(val< node->key){
        node->left= insert(node->left, val);
    }
    else if(val> node->key){
        node->right= insert(node->right, val);
    }
    else{
        return node;
    }

    node->height= 1+max(height(node->left), height(node->right));
    int balance= balance_factor(node);

    if(balance>1 && val< node->left->key){
        return right_rotation(node);
    }
    else if(balance<-1 && val> node->right->key){
        return left_rotation(node);
    }
    else if(balance>1 && val> node->left->key){
        node->left= left_rotation(node->left);
        return right_rotation(node);
    }
    else if(balance<-1 && val< node->right->key){
        node->right= right_rotation(node->right);
        return left_rotation(node);
    }

    return node;
}

void preorder(AVLTree* root){
    if(root!= NULL){
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    AVLTree* root= NULL;
    root = insert(root, 10); 
    root = insert(root, 20); 
    root = insert(root, 30); 
    root = insert(root, 40); 
    root = insert(root, 50); 
    root = insert(root, 25); 

    cout<<"Preorder Traversal\n";
    preorder(root);
    return 0;
}
