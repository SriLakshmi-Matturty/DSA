#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
    public:
    int *arr;
    int max_size;
    int heap_size;

    MaxHeap(int totsize){
        heap_size=0;
        max_size= totsize;
        arr= new int[max_size];
    }
    
    int parent(int i){
        return (i-1)/2;
    }

    int lchild(int i){
        return (2*i+1);
    }

    int rchild(int i){
        return (2*i+2);
    }

    void max_heapify(int i){
        int l= lchild(i);
        int r= rchild(i);
        int largest= i;
        if(l<heap_size && arr[largest]<arr[l]){
            largest=l;
        }
        if(r<heap_size && arr[largest]<arr[r]){
            largest=r;
        }
        if(largest!= i){
            swap(arr[i],arr[largest]);
            max_heapify(largest);
        }
    }

    int get_max(){
        return arr[0];
    }

    void up_heapify(int i){
        while(i!=0 && arr[parent(i)]<arr[i]){
            swap(arr[parent(i)], arr[i]);
            i= parent(i);
        }
    }

    void insert(int x){
        if(heap_size== max_size){
            cout<<"Error: Heap overflow";
        }
        else{
            heap_size++;
            int i= heap_size-1;
            arr[i]=x;
            up_heapify(i);
        }
    }

    int extract_max(){
        if(heap_size==0){
            return INT_MIN;
        }
        else if(heap_size==1){
            heap_size--;
            return arr[0];
        }
        int root= arr[0];
        arr[0]=arr[heap_size-1];
        heap_size--;
        max_heapify(0);
        return root;
    }

    void increase_key(int i, int key){
        arr[i]=key;
        up_heapify(i);
    }

    void delete_key(int i){
        increase_key(i, get_max()+1);
        extract_max();
    }

    void curr_size(){
        cout<<heap_size;
    }
    void print_heap(){
        for(int i=0; i<heap_size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
};

int main(){
    int n;
    cout<<"Enter the max size of heap: ";
    cin>>n;
    int m;
    cout<<"Enter the number of elements to insert: ";
    cin>>m;
    MaxHeap h(n);
    while(m--){
        int x;
        cout<<"Enter key: ";
        cin>>x;
        h.insert(x);
    }
    h.print_heap();
    h.curr_size(); cout<<"\n";
    cout<<"Max element: "<<h.get_max();
    h.delete_key(2);
    //h.extract_max();
    h.print_heap();
    h.increase_key(1, 100);
    h.print_heap();
    return 0;
}
