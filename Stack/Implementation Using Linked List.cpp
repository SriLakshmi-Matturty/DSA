#include <bits/stdc++.h>
using namespace std;

class Stack{
public:
    int data;
    Stack *next;

    Stack(int val){
        data= val;
        next= NULL;
    }
};

bool isempty(Stack *s1){
    if(s1==NULL){
        return true;
    }
    return false;
}

void build_stack(Stack* &s1){
    s1= NULL;
}

void push(Stack* &s1, int x){
    Stack *temp;
    temp= new Stack(x);
    temp->next= s1;
    s1=temp;
}

void pop(Stack* &s1){
    if(s1==NULL){
        cout<<"Error: Stack Underflow\n";
    }
    else{
        Stack *temp=s1;
        s1= s1->next;
        cout<<temp->data<<"\n";
        delete temp;
    }
}

void peek(Stack *s1){
    if(s1==NULL){
        cout<<-1<<"\n";
    }
    else{
        cout<<s1->data<<"\n";
    }
}

int main(){
    Stack *s1;
    build_stack(s1);
    cout<<"Stack is empty: "<<isempty(s1)<<"\n";
    push(s1, 1);
    push(s1, 2);
    push(s1, 3);
    push(s1, 4);
    push(s1, 5);
    pop(s1);
    peek(s1);
    return 0;
}
