#include <bits/stdc++.h>
using namespace std;

class Queue{
	public:
	    int data;
		Queue* next;

		Queue(int val){
			data= val;
			next= NULL;
		}
};

Queue *front, *rear;

bool isempty(){
	if(front== NULL){
		return 1;
	}
	return 0;
}

void build_queue(){
	front = rear=NULL;
}

void enqueue(int x){
	Queue *temp;
	temp= new Queue(x);
	if(front== NULL){
		front= rear= temp;
	}
	else{
		rear->next= temp;
		rear= temp;
	}
}

void dequeue(){
	Queue *temp= front;
	int p_ele;
	if(isempty()){
		cout<<"Error: queue underflow";
	}
	else{
		p_ele= front->data;
		front= front->next;
		delete temp;
		cout<<p_ele<<"\n";
	}
}

void get_front(){
	if(front== NULL){
		cout<<"Error: Queue Underflow";
	}
	else{
		cout<<front->data<<"\n";
	}
}

int size(){
	int l=1;
	if(front== NULL && rear== NULL){
		l=0;
	}
	while(front!= rear){
		front= front->next;
		l++;
	}
	return l;
}

int main(){
	build_queue();
	int n;
	cout<<"Enter no.of elements to push into queue: ";
	cin>>n;
	while(n--){
		int x;
		cout<<"Enter the data to push: ";
		cin>>x;
		enqueue(x);
	}
	dequeue();
	get_front();
	int l= size();
	cout<<"Size= "<<l<<"\n";
	if(isempty()){
		cout<<"Queue is empty\n";
	}
	else{
		cout<<"Queue is not empty\n";
	}
    return 0;
}
