#include <bits/stdc++.h>
using namespace std;

void selection_sort(int a[], int n){
    for(int i=0; i<n-1; i++){
        int j=i;
        for(int k=i+1; k<n; k++){
            if(a[k]<a[j]){
                j=k;
            }
        }
        swap(a[j],a[i]);
    }
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    selection_sort(a,n);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
