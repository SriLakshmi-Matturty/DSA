#include <bits/stdc++.h>
using namespace std;
#define n 5

int min_key(int key[], int MST[]){
    int min= INT_MAX, min_index;
    for(int i=0; i<n; i++){
        if(MST[i]==0 && key[i]<min){
            min= key[i];
            min_index= i;
        }
    }
    return min_index;
}

void print_MST(int Graph[][n], int parent[]){
    cout << "Edge \tWeight\n";
    for(int i=1; i<n; i++){
        cout<<parent[i]<<" - "<<i<<" \t"<<Graph[parent[i]][i]<<"\n";
    }
}

void PrimsMST(int Graph[][n]){
    int parent[n];
    int key[n];
    int MST[n];
    for(int i=0; i<n; i++){
        key[i]= INT_MAX;
        MST[i]=0;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0; i<n-1; i++){
        int u= min_key(key, MST);
        MST[u]=1;

        for(int j=0; j<n; j++){
            if(Graph[u][j]!=0 && MST[j]==0 && Graph[u][j]< key[j]){
                key[j]= Graph[u][j];
                parent[j]=u;
            }
        }
    }
    print_MST(Graph, parent);
}

int main(){
    int Graph[n][n];
    cout<<"Enter the weights\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>Graph[i][j];
        }
    }
    PrimsMST(Graph);
    return 0;
}
