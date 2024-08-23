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

char pop(Stack* &s1){
	char poped_value;
    if(s1==NULL){
        cout<<"Error: Stack Underflow\n";
    }
    else{
        Stack *temp=s1;
        s1= s1->next;
        poped_value=temp->data;
        delete temp;
		return poped_value;
    }
}

char peek(Stack *s1){
	char a;
    if(s1==NULL){
        cout<<-1<<"\n";
    }
    else{
        a=s1->data;
    }
	return a;
}

int precedence(char c){
	if(c=='^'){
		return 3;
	}
	else if(c=='*' || c=='/'){
		return 2;
	}
	else if(c=='+' || c=='-'){
		return 1;
	}
	return -1;
}

bool isoperator(char c){
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
		return 1;
	}
	return 0;
}

string reverse(string a){
	string r_a;
	int n=a.length();
	for(int i=n-1; i>=0; i--){
		if(a[i]=='('){
			r_a+=')';
		}
		else if(a[i]==')'){
			r_a+='(';
		}
		else{
			r_a+= a[i];
		}
	}
	return r_a;
}

string infix_to_postfix(string infix){
	Stack *s= NULL;
	string postfix;
	for(char &c: infix){
		if(isalnum(c)){
			postfix+=c;
		}
		else if(c=='('){
			push(s,c);
		}
		else if(c==')'){
			while((!isempty(s)) && peek(s)!='('){
				postfix+=pop(s);
			}
			pop(s);
		}
		else if(isoperator(c)){
			while((!isempty(s)) && precedence(c)<= precedence(peek(s))){
				postfix+=pop(s);
			}
			push(s,c);
		}
	}
	while((!isempty(s))){
		postfix+=pop(s);
	}
	return postfix;
}

string infix_to_prefix(string infix){
	string a= reverse(infix);
	string b= infix_to_postfix(a);
	string prefix= reverse(b);
	return prefix;
}

int main(){
    string infix;
	cout<<"Enter the infix expression: ";
	cin>>infix;
	string postfix= infix_to_postfix(infix);
	cout<<"The postfix expression is: ";
	cout<<postfix<<"\n";
	string prefix= infix_to_prefix(infix);
	cout<<"The prefix expression is: ";
	cout<<prefix<<"\n";
    return 0;
}
