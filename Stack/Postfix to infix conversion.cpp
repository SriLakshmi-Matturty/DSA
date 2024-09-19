#include <bits/stdc++.h>
using namespace std;

class Stack{
public:
    int top;
    int size;
    string *arr;

    Stack(int n){
        size= n;
        top=-1;
        arr= NULL;
    }
};

void build_stack(Stack* &s1){
    s1= new Stack(100);
    s1->arr= new string[100];
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

void push(Stack* &s1, string x){
    if(isfull(s1)){
        cout<<"Error: Stack Overflow\n";
    }
    else{
        s1->top++;
        s1->arr[s1->top]=x;
    }
}

string pop(Stack* &s1){
    if(isempty(s1)){
        cout<<"Error: Stack Underflow\n";
    }
    else{
        string a= s1->arr[s1->top];
        s1->top--;
        return a;
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

bool isoperator(char c){
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
		return 1;
	}
	return 0;
}

void postfix_to_infix(string postfix){
    string infix;
    Stack *s= NULL;
    build_stack(s);
    int n= postfix.length();
    for(int i=0; i<n; i++){
        if(isalnum(postfix[i])){
            string operand(1, postfix[i]);
            push(s, operand);
        }
        else if(isoperator(postfix[i])){
            string a= pop(s);
            string b= pop(s);
            string c= string("(")+ b+ string(1,postfix[i])+ a+ string(")");
            push(s,c); 
        }
    }
    infix= pop(s);
    cout<<"The infix expression is: ";
    cout<<infix<<"\n";
}

int main(){
    string postfix;
    cout<<"Enter Postfix Expression: ";
    cin>>postfix;
    postfix_to_infix(postfix);
    return 0;
}
