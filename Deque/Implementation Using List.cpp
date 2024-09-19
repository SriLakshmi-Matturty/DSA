#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data= val;
        next= NULL;
        prev= NULL;
    }
};

Node *front= NULL, *rear= NULL;

bool isempty(){
    if(front== NULL && rear== NULL){
        return 1;
    }
    return 0;
}

void insert_front(int x){
    Node* temp;
    temp= new Node(x);
    if(front== NULL){
        front=temp;
        rear= temp;
    }
    else{
        front->prev= temp;
        temp->next= front;
        front= temp;
    }
}

void insert_rear(int x){
    Node* temp;
    temp= new Node(x);
    if(rear== NULL){
        rear= temp;
        front= temp;
    }
    else{
        temp->prev= rear;
        rear->next= temp;
        rear= temp;
    }
}

void pop_front(){
    if(front== NULL){
        cout<<"Error: Deque Underflow\n";
    }
    else{
        Node *temp= front;
        if(front== rear){
            front= rear= NULL;
        }
        else{
            front= front->next;
            front->prev= NULL;
        }
        int x= temp->data;
        delete temp;
        cout<<x<<"\n";
    }
}

void pop_rear(){
    if(rear==NULL){
        cout<<"Error: Deque Underflow\n";
    }
    else{
        Node *temp=rear;
        if(front== rear){
            front= rear= NULL;
        }
        else{
            rear= rear->prev;
            rear->next= NULL;
        }
        int x= temp->data;
        delete temp;
        cout<<x<<"\n";
    }
}

void get_front(){
    if(front==NULL){
        cout<<"Error: Deque Underflow\n";
    }
    else{
        cout<<front->data<<"\n";
    }
}

void get_rear(){
    if(rear== NULL){
        cout<<"Error: Deque Underflow\n";
    }
    else{
        cout<<rear->data<<"\n";
    }
}

void display(){
    Node *iter= front;
    while(iter!= rear){
        cout<<iter->data<<" ";
        iter= iter->next;
    }
    cout<<iter->data<<"\n";
}

int main(){
    insert_front(1);
    insert_front(2);
    pop_rear();
    insert_front(0);
    get_front();
    insert_rear(3);
    pop_front();
    insert_rear(4);
    get_rear();
    insert_rear(5);
    display();
    return 0;
}
