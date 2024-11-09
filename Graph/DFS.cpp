#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> adj, int s, vector <int> &visited){
    visited[s]=1;
    cout<<s<<" ";
    for(int x: adj[s]){
        if(!visited[x]){
            visited[x]=1;
            dfs(adj,x,visited);
        }
    }
}

void dfsDisconnected(vector<vector<int>> adj){
    vector <int> visited(adj.size(),0);
    for(int i=0; i<adj.size(); i++){
        if(!visited[i]){
            dfs(adj,i,visited);
        }
    }
}

void addEdge(vector <vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    vector <vector<int>> adj(6);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 1, 5);  
    dfsDisconnected(adj); 
    return 0;
}
