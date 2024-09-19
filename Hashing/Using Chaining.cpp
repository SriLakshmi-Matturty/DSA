#include <bits/stdc++.h>
using namespace std;
#define size 10

struct node{
    int key;
    node* next;
};

struct node table[size];

void table_init(){
    for(int i=0; i<size; i++){
        table[i].key= -1;
        table[i].next= NULL;
    }
}

int hashfunction(int key){
    return key%size;
}

void insert(int k){
    int i= hashfunction(k);
    if(table[i].key== -1){
        table[i].key= k;
    }
    else{
        struct node *new_node, *temp= &table[i];
        new_node= (struct node*) malloc(sizeof(struct node));
        new_node->key= k;
        new_node->next= NULL;
        while(temp->next!= NULL){
            temp= temp->next;
        }
        temp->next= new_node;
    }
}

void delete_key(int k){
    int i= hashfunction(k);
    struct node* temp= &table[i];
    if(temp->key==k){
        if(temp->next== NULL){
            temp->key= -1;
        }
        else{
            table[i]= *(temp->next);
            free(temp);
        }
    }
    else{
        struct node* prev;
        while(temp->next->key != k){
            temp= temp->next;
        }
        prev= temp;
        temp= temp->next;
        prev->next= temp->next;
        free(temp);
    }
}

void print_hash(){
    cout<<"Hash Table\n";
    for(int i=0; i<size; i++){
        struct node* temp= &table[i];
        cout<<"Row "<<i<<": ";
        if(temp->key!= -1){
            cout<<temp->key;
            temp= temp->next;
            while(temp!= NULL){
                cout<<" -> "<<temp->key;
                temp= temp->next;
            }
        }
        cout<<"\n";
    }
}

int main(){
    table_init();
    int arr[]={1,2,3,4,5,6,7,89,101,14,15,1005};
    for(int i=0; i<12; i++){
        insert(arr[i]);
    }
    print_hash();
    return 0;
}
