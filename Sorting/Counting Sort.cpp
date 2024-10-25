#include <bits/stdc++.h>
using namespace std;

vector <int> counting_sort(vector <int> &a){
    int n= a.size();
    int maxe=0;
    for(int i=0; i<n; i++){
        maxe= max(maxe, a[i]);
    }
    vector <int> c(maxe+1, 0);
    for(int i=0; i<n; i++){
        c[a[i]]++;
    }
    for(int i=1; i<maxe+1; i++){
        c[i]+=c[i-1];
    }
    vector <int> b(n);
    for(int i=n-1; i>=0; i--){
        b[c[a[i]]-1]=a[i];
        c[a[i]]--;
    }
    return b;
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector <int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    vector <int> b;
    b= counting_sort(a);
    cout<<"After sorting: ";
    for(int i=0; i<n; i++){
        cout<<b[i]<<" ";
        
    }
    cout<<"\n";
    return 0;
}
