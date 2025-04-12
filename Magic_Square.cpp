#include <bits/stdc++.h>
using namespace std;

void magic_square(int n, vector <vector<int>> &a){
    int i=0, j=n/2;
    a[i][j]=1;
    for(int num=2; num<=(n*n); num++){
        int r=i,c=j;
        if(r>0)r--;
        else r=n-1;
        if(c>0)c--;
        else c=n-1;
        if(a[r][c]==0) a[r][c]=num;
        else{
            r=i,c=j;
            r=(r+1)%n;
            a[r][c]=num;
        }
        i=r;j=c;
    }
}

int main(){
    int n;
    cin>>n;
    vector <vector<int>> a(n, vector<int> (n,0));
    magic_square(n,a);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j]<<' ';
        }
        cout<<"\n";
    }
    return 0;
}
