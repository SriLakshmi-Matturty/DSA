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

int pop(Stack* &s1){
    if(isempty(s1)){
        cout<<"Error: Stack Underflow\n";
    }
    else{
        return s1->arr[s1->top--];
    }
}

void enqueue(Stack* &s1,int x){
	if(isfull(s1)){
		cout<<"Error: Queue Overflow\n";
	}
	else{
		push(s1,x);
	}
}

void dequeue(Stack* &s1, Stack* &s2){
	int b;
	if(isempty(s1) && isempty(s2)){
		cout<<"Error: Queue Underflow\n";
	}
	else{
		while(s1->top!=-1){
			int a= pop(s1);
			push(s2,a);
		}
		b= pop(s2);
		while(s2->top!=-1){
			int a= pop(s2);
			push(s1,a);
		}
		cout<<"The popped element is: "<<b<<"\n";
	}
}

bool q_empty(Stack* s1){
	if(isempty(s1)){
		return 1;
	}
	return 0;
}

bool q_full(Stack* &s1){
	return isfull(s1);
}

void display(Stack* s1){
	int x;
	if(isempty(s1)){
		cout<<0<<"\n";
	}
	else{
		x=s1->top;
		cout<<"The elements in the queue are: ";
		while((s1->top)!=-1){
			cout<<s1->arr[s1->top--]<<" ";
		}
		cout<<"\n";
		s1->top=x;
	}
}

int main(){
    int n;
    cout<<"Enter the size of queue: ";
    cin>>n;
    Stack *s1, *s2;
    build_stack(n, s1);
    build_stack(n, s2);
	enqueue(s1,1);
	enqueue(s1,2);
	display(s1);
	dequeue(s1,s2);
	if(q_empty(s1)){
		cout<<"Empty\n";
	}
	else{
		cout<<"Not empty\n";
	}
	if(q_full(s1)){
		cout<<"Full\n";
	}
	else{
		cout<<"Not Full\n";
	}
  return 0;
}
