#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int new_data){
        data= new_data;
        next= NULL;
    }
};

void creation(Node* &head){
    Node *temp,*new_node;
    bool choice= true;
    cout<<"Do you want to Insert node: ";
    cin>>choice;
    while(choice){
        int val;
        cout<<"Enter the data of the node: ";
        cin>>val;
        new_node= new Node(val);
        if(head== NULL){
            head= temp= new_node;
        }
        else{
            temp-> next= new_node;
            temp= new_node;
        }
        cout<<"Do you want to Insert another node: ";
        cin>>choice;
    }
}

void display(Node *head){
    Node *temp=head;
    cout<<"The data stored are: \n";
    if(head== NULL){
        cout<<"No data is stored\n";
    }
    while(temp!=NULL){
        cout<<temp-> data<<"\n";
        temp= temp-> next;
    }
}

void insert(Node* &head, int val, int pos){
    Node *temp, *new_node;
    temp=head;
    new_node= new Node(val);
    if(pos==1){
        new_node->next= head;
        head= new_node;
    }
    else{
        int i=1;
        while(i!=pos-1){
            temp= temp->next;
            i++;
        }
        new_node-> next= temp-> next;
        temp-> next= new_node;
    }
}

void deletion(Node* &head, int val){
    Node *iter= head, *temp, *prev_node;
    if(!head){
        cout<<"Error: List is empty!\n";
    }
    else if(head->data == val){
        temp=head;
        head= head->next;
        delete temp;
    }
    else{
        while(iter->next!= NULL && iter->data !=val){
            prev_node= iter;
            iter= iter->next;
        }
        if(iter->next== NULL && iter->data != val){
            cout<<"Error: Value not found\n";
        }
        else{
            prev_node->next= iter->next;
            temp= iter;
            delete temp;
        }
    }
}

void size(Node* head){
    Node* iter= head;
    int length=0;
    if(head== NULL){
        cout<<"Length of List = "<<length<<"\n";
    }
    else{
        while(iter->next!= NULL){
            iter= iter->next;
            length++;
        }
        cout<<"Length of List = "<<length+1;
    }
}

void reverse(Node* &head){
    Node *prev_node= NULL, *c_node, *next_node;
    c_node= next_node= head;
    while(next_node!= NULL){
        next_node= next_node->next;
        c_node->next = prev_node;
        prev_node= c_node;
        c_node= next_node;
    }
    head= prev_node;
}

int main(){
    Node *head= NULL;
    creation(head);
    display(head);
    size(head);
    //Reverse
    reverse(head);
    cout<<"List after Reversing\n";
    display(head);
    // //Insertion
    // int val;
    // cout<<"Enter the data to be inserted: ";
    // cin>>val;
    // int pos;
    // cout<<"Enter position: ";
    // cin>>pos;
    // insert(head, val, pos);
    // cout<<"After Insertion:\n";
    // display(head);
    // //Deletion
    // int val1;
    // cout<<"Enter the data to be deleted: ";
    // cin>>val1;
    // deletion(head, val1);
    // cout<<"After Deletion:\n";
    // display(head);
    return 0;
}