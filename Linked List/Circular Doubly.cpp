#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node(int new_data){
        prev= NULL;
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
            new_node->prev= temp;
            temp= new_node;
        }
        cout<<"Do you want to Insert another node: ";
        cin>>choice;
    }
    temp->next= head;
    head->prev= temp;
}

void display(Node *head){
    Node *temp=head;
    cout<<"The data stored are: \n";
    if(head== NULL){
        cout<<"No data is stored\n";
    }
    while(temp->next!=head){
        cout<<temp-> data<<" ";
        temp= temp-> next;
    }
    cout<<temp-> data<<"\n";
}

void insert(Node* &head, int val, int pos){
    Node *temp, *new_node;
    temp=head;
    new_node= new Node(val);
    if(pos==1){
        new_node->next= head;
        head->prev= new_node;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next= new_node;
        new_node->prev= temp;
        head= new_node;
    }
    else{
        int i=1;
        while(i!=pos-1){
            temp= temp->next;
            i++;
        }
        new_node->prev= temp;
        new_node-> next= temp-> next;
        if(temp->next !=head){
            temp->next->prev= new_node;
        }
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
        while(iter->next!= head){
            iter= iter->next;
        }
        iter->next= head->next;
        head= head->next;
        head->prev= iter;
        delete temp;
    }
    else{
        while(iter->next!= head && iter->data !=val){
            prev_node= iter;
            iter= iter->next;
        }
        if(iter->next== head && iter->data != val){
            cout<<"Error: Value not found\n";
        }
        else{
            prev_node->next= iter->next;
            if(iter->next!= head){
                iter->next->prev= prev_node;
            }
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
        while(iter->next!= head){
            iter= iter->next;
            length++;
        }
        cout<<"Length of List = "<<length+1<<"\n";
    }
}

void reverse(Node* &head){
    Node *prev_node= NULL, *c_node, *next_node;
    c_node= next_node= head;
    while(next_node->next!= head){
        next_node= next_node->next;
        c_node->next = prev_node;
        c_node->prev= next_node;
        prev_node= c_node;
        c_node= next_node;
    }
    if(next_node->next ==head){
        next_node= next_node->next;
        c_node->next = prev_node;
        c_node->prev= next_node;
        prev_node= c_node;
        c_node= next_node;
    }
    head->next= prev_node;
    prev_node->prev= head;
    head= prev_node;
}

int main(){
    Node *head= NULL;
    creation(head);
    display(head);
    size(head);
    //Insertion
    int val;
    cout<<"Enter the data to be inserted: ";
    cin>>val;
    int pos;
    cout<<"Enter position: ";
    cin>>pos;
    insert(head, val, pos);
    cout<<"After Insertion:\n";
    display(head);
    //Deletion
    int val1;
    cout<<"Enter the data to be deleted: ";
    cin>>val1;
    deletion(head, val1);
    cout<<"After Deletion:\n";
    display(head);
    //Reverse
    reverse(head);
    cout<<"List after Reversing\n";
    display(head);
    return 0;
}
