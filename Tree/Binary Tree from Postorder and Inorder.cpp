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

void P_inorder(Tnode* root){
    if(root== NULL){
        return;
    }
    P_inorder(root->left);
    cout<<root->data<<" ";
    P_inorder(root->right);
}

Tnode* tree_helper_poin(int *postorder, int *inorder, int &ind, int inorder_st, int inorder_end, unordered_map <int, int> &inordermap){
    if(inorder_st> inorder_end){
        return NULL;
    }
    Tnode *root;
    int x= postorder[ind--];
    root= new Tnode(x);
    int inorder_ind= inordermap[x];
    root->right= tree_helper_poin(postorder, inorder, ind, inorder_ind+1, inorder_end, inordermap);
    root->left= tree_helper_poin(postorder, inorder, ind, inorder_st, inorder_ind-1, inordermap);

    return root;
}

Tnode* tree_post_in(int *postorder, int *inorder, int size){
    unordered_map <int,int> inordermap;
    for(int i=0; i<size; i++){
        inordermap[inorder[i]]=i;
    }
    int ind= size-1;
    return tree_helper_poin(postorder, inorder, ind, 0, size-1, inordermap);
}

int main(){
    Tnode *root= NULL;
    int postorder[]={4,2,7,5,8,9,6,3,1};
    int inorder[]={2,4,1,7,5,3,8,6,9};
    root= tree_post_in(postorder, inorder, 9);
    cout<<"Inorder: ";
    P_inorder(root);
    cout<<"\n";
    return 0;
}
