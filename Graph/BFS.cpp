#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> adj, int s, vector <int> &visited){
    queue <int> q;
    visited[s]=1;
    q.push(s);
    while(!q.empty()){
        int curr= q.front();
        q.pop();
        cout<<curr<<" ";
        for(int i: adj[curr]){
            if(!visited[i]){
                visited[i]=1;
                q.push(i);
            }
        }
    }
}

void bfsDisconnected(vector<vector<int>> adj){
    vector <int> visited(adj.size(),0);
    for(int i=0; i<adj.size(); i++){
        if(!visited[i]){
            bfs(adj,i,visited);
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
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);  
    bfsDisconnected(adj); 
    return 0;
}
