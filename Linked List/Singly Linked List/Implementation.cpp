#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next= NULL;
    }
};

class LinkedList{
public:
    Node* head= NULL;

    void insert_at_beg(int x){
        Node* newnode= new Node(x);
        newnode->next= head;
        head= newnode;
    }

    void insert_at_end(int x){
        Node* newnode= new Node(x);
        Node* iter= head;
        if(head== NULL){
            head= newnode;
        }
        else{
            while(iter->next!= NULL){
                iter= iter->next;
            }
            iter->next= newnode;
        }
    }

    int length(){
        if(head== NULL){
            return 0;
        }
        Node* iter= head;
        int l=1;
        while(iter->next!= NULL){
            l++;
            iter= iter->next;
        }
        return l;
    }

    void insert_at_pos(int x, int pos){
        if(pos==1){
            insert_at_beg(x);
        }
        else if(pos> length()){
            insert_at_end(x);
        }
        else{
            Node* newnode= new Node(x);
            int i=1;
            Node* iter= head;
            while(i<pos-1){
                iter= iter->next;
                i++;
            }
            newnode->next= iter->next;
            iter->next= newnode;
        }
    }

    void del_head(){
        if(head== NULL){
            cout<<"Error!\n";
            return;
        }
        Node* temp= head;
        head= head->next;
        delete temp;
    }

    void del_tail(){
        if(head== NULL){
            cout<<"Error!\n";
            return;
        }
        Node *iter= head, *prev= head;
        while(iter->next!= NULL){
            prev= iter;
            iter= iter->next;
        }
        prev->next= NULL;
        delete iter;
    }

    void del_at_pos(int pos){
        if(pos==1){
            del_head();
        }
        else if(pos>= length()){
            del_tail();
        }
        else{
            int i=1;
            Node *iter=head, *prev;
            while(i<pos){
                prev=iter;
                iter= iter->next;
            }
            prev->next= iter->next;
            delete iter; 
        }
    }

    void del_x(int x){
        if(head== NULL){
            cout<<"NOT FOUND!\n";
        }
        else{
            if(head->data== x){
                del_head();
            }
            else{
                Node *iter= head, *prev= NULL;
                while(iter!= NULL && iter->data!= x){
                    prev= iter;
                    iter= iter->next;
                }
                if(iter== NULL){
                    cout<<"NOT FOUND!\n";
                }
                else{
                    prev->next= iter->next;
                    delete iter;
                }
            }
        }
    }

    void reverse(){
        Node *prev_node= NULL, *c_node, *next_node;
        c_node= next_node= head;
        while(next_node!= NULL){
            next_node= next_node->next;
            c_node->next = prev_node;
            prev_node= c_node;
            c_node= next_node;
        }
        head= prev_node;
    }

    void print(){
        Node* iter= head;
        while(iter!= NULL){
            cout<<iter->data<<" ";
            iter= iter->next;
        }
        cout<<"\n";
    }
};

int main(){
    LinkedList ll;
    ll.insert_at_beg(1);
    ll.insert_at_beg(2);
    ll.insert_at_beg(3);
    ll.insert_at_beg(4);
    ll.insert_at_pos(5, 3);
    ll.print();
    ll.del_head();
    ll.print();
    ll.del_at_pos(4);
    ll.print();
    ll.del_x(6);
    ll.print();
    ll.reverse();
    ll.print();
    return 0;
}
