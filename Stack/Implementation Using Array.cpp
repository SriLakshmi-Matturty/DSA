#include <bits/stdc++.h>
using namespace std;

class Stack{
public:
    int top;
    int size;
    int *arr;

    Stack(int n){
        size= n;
        top=-1;
        arr= NULL;
    }
};

void build_stack(int n, Stack* &s1){
    s1= new Stack(n);
    s1->arr= new int[s1->size];
}

bool isempty(Stack *s1){
    if(s1->top== -1){
        return true;
    }
    else{
        return false;
    }
}

bool isfull(Stack *s1){
    if(s1->top== s1->size-1){
        return true;
    }
    else{
        return false;
    }
}

void push(Stack* &s1, int x){
    if(isfull(s1)){
        cout<<"Error: Stack Overflow\n";
    }
    else{
        s1->top++;
        s1->arr[s1->top]=x;
    }
}

void pop(Stack* &s1){
    if(isempty(s1)){
        cout<<"Error: Stack Underflow\n";
    }
    else{
        cout<<s1->arr[s1->top--]<<"\n";
    }
}

void peek(Stack *s1){
    if(isempty(s1)){
        cout<<-1<<"\n";
    }
    else{
        cout<<s1->arr[s1->top]<<"\n";
    }
}

int main(){
    int n;
    cout<<"Enter the size of stack: ";
    cin>>n;
    Stack *s1;
    build_stack(n, s1);
    cout<<"Stack is empty: "<<isempty(s1)<<"\n";
    push(s1, 1);
    push(s1, 2);
    push(s1, 3);
    push(s1, 4);
    push(s1, 5);
    pop(s1);
    cout<<"Stack is Full: "<<isfull(s1)<<"\n";
    peek(s1);
    return 0;
}
