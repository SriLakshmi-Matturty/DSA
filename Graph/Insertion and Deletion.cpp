#include <bits/stdc++.h>
using namespace std;

class AdjNode{
public:
    int node;
    AdjNode* next;

    AdjNode(int v){
        node=v;
        next= NULL;
    }
};

class AdjList{
private:
    int v;
    AdjNode** graph;

public:
    AdjList(int ver){
        v=ver;
        graph= new AdjNode*[v];
        for(int i=0; i<v; i++){
            graph[i]=NULL;
        }
    }

    void addEdge(int src, int dest){
        AdjNode* new_node= new AdjNode(dest);
        AdjNode* temp= graph[src];
        if(temp== NULL){
            graph[src]= new_node;
        }
        else{
            while(temp->next!= NULL){
                temp= temp->next;
            }
            temp->next= new_node;
        }
    }

    void addVertex(int new_v, int src, int dest){
        addEdge(src, new_v);
        addEdge(new_v, dest);
    }

    void delVertex(int k){
        for(int i=0; i<v; i++){
            AdjNode* temp= graph[i];
            if(i==k){
                graph[i]= NULL;
            }
            else{
                AdjNode* prev= NULL;
                while(temp!=NULL && temp->node!= k){
                    prev=temp;
                    temp= temp->next;
                }
                if(temp!= NULL && temp->node==k){
                    if(prev== NULL){
                        graph[i]= temp->next;
                    }
                    else{
                        prev->next= temp->next;
                    }
                    delete temp;
                }
            }
        }
    }

    void print_graph(){
        for(int i=0; i<v; i++){
            cout<<i<<"-> ";
            AdjNode* temp= graph[i];
            while(temp!= NULL){
                cout<<temp->node<<"-> ";
                temp= temp->next;
            }
            cout<<"\n";
        }
    }
};

int main(){
    int V = 6;
    AdjList graph(V);
    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(3, 2);
    graph.addEdge(4, 3);

    cout << "Initial adjacency list" << endl;
    graph.print_graph();

    // Add vertex
    graph.addVertex(5, 3, 2);
    cout << "Adjacency list after adding vertex" << endl;
    graph.print_graph();

    // Delete vertex
    graph.delVertex(4);
    cout << "Adjacency list after deleting vertex" << endl;
    graph.print_graph();

    return 0;
}
