#include <bits/stdc++.h>
using namespace std;
#define size 5

class Deque{
	public:
	    int arr[size];
		int front;
		int rear;

		void build_Deque(){
	    front=-1;
	    rear=-1;
}
};

bool isempty(Deque &d){
	return (d.front==-1 && d.rear==-1);
}

bool isfull(Deque &d){
	if((d.front==0 && d.rear== size-1) || (d.front== (d.rear+1))){
		return 1;
	}
	return 0;
}

void insert_front(Deque &d, int x){
	if(isfull(d)){
		cout<<"Error: Deque Overflow\n";
	}
	else if(isempty(d)){
		d.front=0; d.rear=0;
		d.arr[d.front]=x;
	}
	else if(d.front==0){
		d.front= size-1;
		d.arr[d.front]=x;
	}
	else{
		d.front--;
		d.arr[d.front]=x;
	}
}

void insert_rear(Deque &d, int x){
	if(isfull(d)){
		cout<<"Error: Deque Overflow\n";
	}
	else if(isempty(d)){
		d.front=0; d.rear=0;
		d.arr[d.rear]=x;
	}
	else{
		d.rear= (d.rear+1)%size;
		d.arr[d.rear]=x;
	}
}

void pop_front(Deque &d){
	if(isempty(d)){
		cout<<"Error: Deque Underflow\n";
	}
	else if(d.front== d.rear){
		cout<<d.arr[d.front]<<"\n";
		d.front= d.rear=-1;
	}
	else if(d.front==(size-1)){
		cout<<d.arr[d.front]<<"\n";
		d.front= 0;
	}
	else{
		cout<<d.arr[d.front]<<"\n";
		d.front++;
	}
}

void pop_rear(Deque &d){
	if(isempty(d)){
		cout<<"Error: Deque Underflow\n";
	}
	else if(d.front== d.rear){
		cout<<d.arr[d.rear]<<"\n";
		d.front= d.rear=-1;
	}
	else if(d.rear==0){
		cout<<d.arr[d.rear]<<"\n";
		d.rear= size-1;
	}
	else{
		cout<<d.arr[d.rear]<<"\n";
		d.rear--;
	}
}

void get_front(Deque &d){
	if(isempty(d)){
		cout<<"Error: Deque Underflow\n";
	}
	else{
		cout<<d.arr[d.front]<<" ";
	}
}

void get_rear(Deque &d){
	if(isempty(d)){
		cout<<"Error: Deque Underflow\n";
	}
	else{
		cout<<d.arr[d.rear]<<" ";
	}
}

void display(Deque &d){
	int i=d.front;
	while(i!=d.rear){
		cout<<d.arr[i]<<" ";
		i= (i+1)%size;
	}
	cout<<d.arr[d.rear]<<"\n";
}

int main(){
	Deque d;
	d.build_Deque();
	insert_front(d,1);
	insert_front(d,2);
	insert_rear(d,3);       
	insert_rear(d,4);
	//pop_front(d);
	insert_front(d,5);
	pop_rear(d);
	insert_front(d,6);
    display(d);
    return 0;
}
