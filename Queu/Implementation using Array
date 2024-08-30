#include <bits/stdc++.h>
using namespace std;
#define size 5

class CircularQueue{
	public:
	    int arr[size];
		int front;
		int rear;

		void build_queue(){
	    front=-1;
	    rear=-1;
}
};

bool isempty(CircularQueue &q){
	if(q.front== -1 && q.rear== -1){
		return 1;
	}
	return 0;
}


bool isfull(CircularQueue &q){
	if(((q.rear+1)%size)== q.front){
		return 1;
	}
	return 0;
}
void enqueue(CircularQueue &q,int x){
	if(q.front== -1 && q.rear== -1){
		q.front=0;
		q.rear=0;
		q.arr[q.rear]= x;
	}
	else if(isfull(q)){
		cout<<"Error: Queue Overflow\n";
	}
	else{
		q.rear= (q.rear+1)%size;
		q.arr[q.rear]= x;
	}
}

void dequeue(CircularQueue &q){
	if(q.front== -1 && q.rear== -1){
		cout<<"Error: Queue Underflow\n";
	}
	else if(q.front== q.rear){
		cout<<q.arr[q.front]<<"\n";
		q.front= q.rear= -1;
	}
	else{
		cout<<q.arr[q.front]<<"\n";
		q.front= (q.front+1)%size;
	}
}

void get_front(CircularQueue &q){
	if(q.front!=-1){
		cout<<q.arr[q.front]<<"\n";
	}
	else{
		cout<<"Error: Queue Underflow\n";
	}
}

void print(CircularQueue &q){
	while(q.front!= q.rear){
		cout<<q.arr[q.front]<<"\n";
		q.front= (q.front+1)%size;
	}
	if(q.front!= -1 && q.rear!=-1){
		cout<<q.arr[q.front]<<"\n";
	}
	else{
		cout<<"No elements\n";
	}
}

int main(){
	CircularQueue q;
	q.build_queue();
	enqueue(q,1);
	enqueue(q,2);
	dequeue(q);
	enqueue(q,3);
	get_front(q);
    dequeue(q);
    dequeue(q);
	get_front(q);
	print(q);
    return 0;
}
