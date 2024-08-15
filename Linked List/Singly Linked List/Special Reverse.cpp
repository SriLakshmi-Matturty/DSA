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

void reverse(Node* &head, int l, int r){
	int i= 1;
	Node *prev_node= NULL, *c_node, *next_node, *temp, *pp_node;
	temp=head;
	if(l!=1 && i<=l){
		prev_node= temp;
		temp= temp->next;
		i++;
	}
	pp_node= prev_node;
	c_node= next_node= temp;
    if(l==1){
        pp_node= head;
    }
	int j=l;
	while(next_node!= NULL && j<=r){
		next_node= next_node->next;
		c_node->next= prev_node;
		prev_node= c_node;
		c_node= next_node;
        j++;
	}
	if(l!=1){
        pp_node->next= prev_node;
    }
    else{
        head=prev_node;
        pp_node= prev_node;
    }
	temp->next= c_node;
}

int main(){
    Node *head= NULL;
    creation(head);
    display(head);
    //Reverse
	int l,r;
	cout<<"Enter l,r: ";
	cin>>l>>r;
    reverse(head,l,r);
    cout<<"List after Reversing\n";
    display(head);
    return 0;
}
